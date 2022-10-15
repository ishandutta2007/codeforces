#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 300013
#define MAXQ 300013
int N, Q;
int nloc[MAXQ];
vector<int> view[MAXN];
int viewa[MAXN];
int ans = 0;
int ith[MAXQ];
int idx = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;
	int p = 0;
	for (int q = 0; q < Q; q++) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			ith[idx++] = q;
			nloc[q] = x;
			view[x].push_back(q);
			ans++;
			viewa[x]++;
		}
		else if (t == 2) {
			for (int y : view[x]) {
				nloc[y] = 0;
			}
			view[x].clear();
			ans -= viewa[x];
			viewa[x] = 0;
		}
		else {
			for (; p < x; p++) {
				if (nloc[ith[p]]) {
					viewa[nloc[ith[p]]]--;
					ans--;
				}
			}
		}
		cout << ans << '\n';
	}

	cout.flush();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
typedef pair<int, int> pii;

#define MAXN 100002
int N;
int A[MAXN];
LL prefix[MAXN];
map<LL, int> aux;
int nexteq[MAXN];
int nonzero[MAXN];
bool done[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	prefix[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		prefix[i + 1] = prefix[i] + A[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		aux[prefix[i]] = i + N;
	}

	for (int i = N - 1; i >= 0; i--) {
		nexteq[i] = aux[prefix[i]];
		aux[prefix[i]] = i;
	}

	int ans = MAXN;
	for (int start = 0; start < N; start++) {
		if (done[start]) continue;
		int c = 0, idx = start;
		// error(c, idx);
		while (idx < start + N) {
			// error(c, idx);
			done[idx % N] = true;
			int n;
			if (idx < N) {
				n = nexteq[idx];
			}
			else {
				n = nexteq[idx - N] + N;
			}
			c += n - idx - 1;
			idx = n;
		}
		ans = min(ans, c);
	}

	cout << ans << endl;

}
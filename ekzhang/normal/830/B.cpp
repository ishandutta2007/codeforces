#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 100013
int N;
int A[MAXN];
int ar[MAXN];
map<int, list<int> > pos;
bool seen[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
		pos[ar[i]].push_back(i);
	}

	int pre = 0;
	for (auto& p : pos) {
		list<int>& l = p.second;
		if (l.front() >= pre) {
			pre = l.back();
		}
		else if (l.back() >= pre) {
			while (l.front() < pre) {
				l.push_back(l.front());
				l.pop_front();
			}
			pre = l.back();
		}
		else {
			pre = l.back();
		}
	}

	int t = 0;
	for (auto& p : pos) {
		for (int idx : p.second) {
			A[idx] = t++;
		}
	}

	LL ans = 0;
	for (int i = 0; i < N; i++) {
		// error(A[i]);
		if (!A[i] || !seen[A[i] - 1]) {
			ans += N - A[i];
		}
		seen[A[i]] = true;
	}

	cout << ans << endl;
	return 0;
}
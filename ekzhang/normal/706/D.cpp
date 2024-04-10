#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 6200013

#define SZ 31
int Q;
int N = 1;
int G[MAXN][2];
int val[MAXN];

string to_bin(int x) {
	return bitset<SZ>(x).to_string();
}

void up(string s, int d) {
	int cur = 0;
	val[cur] += d;
	for (int i = 0; i < s.size(); i++) {
		bool b = (s[i] == '1');
		if (G[cur][b] == -1) {
			G[cur][b] = N++;
		}
		cur = G[cur][b];
		val[cur] += d;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	memset(G, -1, sizeof G);
	up(to_bin(0), 1);
	for (int i = 0; i < Q; i++) {
		string t;
		int x;
		cin >> t >> x;
		if (t[0] == '+') {
			up(to_bin(x), 1);
		}
		else if (t[0] == '-') {
			up(to_bin(x), -1);
		}
		else {
			// assert(val[0]);
			string s = to_bin(x);
			int ans = 0;
			int cur = 0;
			for (int i = 0; i < SZ; i++) {
				ans *= 2;
				if (val[G[cur][s[i] == '0']]) {
					ans += 1;
					cur = G[cur][s[i] == '0'];
				}
				else {
					cur = G[cur][s[i] == '1'];
				}
			}
			cout << ans << '\n';
		}
	}

	cout.flush();
	return 0;
}
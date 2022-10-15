#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
#define MAXM 1000013
#define P  179426549 // big prime number
#define P2 961748941
#define MOD 1000000007
typedef long long LL;
int N, M;
map<int, int> m;
LL H[MAXM];
LL H2[MAXM];
LL p[MAXN], p2[MAXN];
LL f[MAXM];
map<pair<LL, LL>, int> ANS;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	p[0] = 1;
	p2[0] = 1;
	f[0] = 1;
	for (int i = 0; i < M; i++) {
		f[i+1] = ((i + 1) * f[i]) % MOD;
	}
	for (int i = 0; i < N; i++) {
		p[i+1] = (p[i] * P) % MOD;
		p2[i+1] = (p2[i] * P2) % MOD;
	}

	for (int i = 0; i < N; i++) {
		int g; cin >> g;
		for (int j = 0; j < g; j++) {
			int k; cin >> k;
			m[k]++;
		}
		for (auto pp : m) {
			// error(pp.first, pp.second);
			H[pp.first] += pp.second * p[i];
			H[pp.first] %= MOD;
			// error(pp.first, H2[pp.first], pp.second*p2[i]);
			H2[pp.first] += pp.second * p2[i];
			// error(H2[pp.first]);
			H2[pp.first] %= MOD;
		}
		m.clear();
		// error(i, H[2], H2[2], H[1], H2[1]);
	}

	for (int i = 1; i <= M; i++) {
		// error(i, H[i]);
		ANS[{H[i], H2[i]}]++;
	}

	LL ans = 1;
	for (auto pp : ANS) {
		// error(ans, pp.first, pp.second);
		ans *= f[pp.second];
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;
}
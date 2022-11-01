#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
#include<cassert>
using namespace std;
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<string> str(3, "");
vector<int> l(3, 0);
string w;
int n, q;
vector<vector<vector<int>>> dp(251, vector<vector<int>>(251, vector<int>(251, -1)));
vector<vector<int>> nx(26);

int dfs(int l1, int l2, int l3) {
	if(dp[l1][l2][l3] != -1) return dp[l1][l2][l3];
	int ret = INF;
	if(l1) {
		int tmp = dfs(l1 - 1, l2, l3);
		if(tmp != INF && tmp != n && nx[str[0][l1 - 1] - 'a'][tmp] != -1) {
			ret = min(ret, nx[str[0][l1 - 1] - 'a'][tmp] + 1);
		}
	}
	if(l2) {
		int tmp = dfs(l1, l2 - 1, l3);
		if(tmp != INF && tmp != n && nx[str[1][l2 - 1] - 'a'][tmp] != -1) {
			ret = min(ret, nx[str[1][l2 - 1] - 'a'][tmp] + 1);
		}
	}
	if(l3) {
		int tmp = dfs(l1, l2, l3 - 1);
		if(tmp != INF && tmp != n && nx[str[2][l3 - 1] - 'a'][tmp] != -1) {
			ret = min(ret, nx[str[2][l3 - 1] - 'a'][tmp] + 1);
		}
	}
	return dp[l1][l2][l3] = ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	REP(i, 26) nx[i].assign(n, -1);
	cin >> w;
	dp[0][0][0] = 0;
	for(int i = 0; i < 26; i++) for(int j = n - 1; j >= 0; j--) {
		if(w[j] - 'a' == i) nx[i][j] = j;
		else {
			if(j != n - 1) nx[i][j] = nx[i][j + 1];
		}
	}
	REP(query, q) {
		char ex;
		cin >> ex;
		if(ex == '+') {
			int i;
			char alp;
			cin >> i >> alp;
			i--;
			str[i] += alp;
			l[i]++;
		} else {
			int i;
			cin >> i;
			i--;
			if(i == 0) {
				REP(j, 251) REP(k, 251) {
					dp[(int)str[i].size()][j][k] = -1;
				}
			} else if(i == 1) {
				REP(j, 251) REP(k, 251) {
					dp[j][(int)str[i].size()][k] = -1;
				}
			} else {
				REP(j, 251) REP(k, 251) {
					dp[j][k][(int)str[i].size()] = -1;
				}
			}
			str[i] = str[i].substr(0, (int)str[i].size() - 1);
			l[i]--;
		}
		if(dfs(l[0], l[1], l[2]) != INF) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
/* --------------------------------------- */
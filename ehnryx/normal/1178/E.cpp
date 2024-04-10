#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Pair {
	int i, j, t;
};

const int N = 1e6+1;
unordered_map<int,pii> pre[2][N];
unordered_map<int,int> dist[2][N];
int nxti[3][N], prei[3][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	string s;
	cin >> s;
	int n = s.size();

	prei[0][0] = prei[1][0] = prei[2][0] = -1;
	For(i,n) {
		For(c,3) {
			if (s[i]-'a' == c) {
				prei[c][i+1] = i;
			} else {
				prei[c][i+1] = prei[c][i];
			}
		}
	}
	nxti[0][n] = nxti[1][n] = nxti[2][n] = -1;
	Down(i,n) {
		For(c,3) {
			if (s[i]-'a' == c) {
				nxti[c][i] = i;
			} else {
				nxti[c][i] = nxti[c][i+1];
			}
		}
	}

	queue<Pair> bfs;
	bfs.push({0,n,0});
	bfs.push({0,n,1});
	dist[0][0][n] = 0;
	dist[1][0][n] = 0;
	while (!bfs.empty()) {
		int i = bfs.front().i;
		int j = bfs.front().j;
		int t = bfs.front().t;
		bfs.pop();
		int bi = -1;
		int bj = -7;
		vector<int> o = (t ? vector<int>({0,1,2}) : vector<int>({2,1,0}));
		for (int c : o) {
			int left = nxti[c][i];
			int right = prei[c][j];
			if (left == -1 || right == -1 || left > right) continue;
			if (left == right) {
				if (dist[t][i][j]+1 >= n/2) {
					vector<char> ans;
					for (int ii=i, jj=j; ii!=0 && jj!=n; tie(ii,jj)=pre[t][ii][jj]) {
						ans.push_back(s[jj]);
					}
					for (int k=ans.size()-1; k>=0; k--) cout << ans[k];
					cout << s[left];
					for (char v : ans) cout << v;
					cout << nl;
					return 0;
				}
			} else {
				if (dist[t][i][j]+2 >= n/2) {
					vector<char> ans = { s[left] };
					for (int ii=i, jj=j; ii!=0 && jj!=n; tie(ii,jj)=pre[t][ii][jj]) {
						ans.push_back(s[jj]);
					}
					for (int k=ans.size()-1; k>=0; k--) cout << ans[k];
					for (char v : ans) cout << v;
					cout << nl;
					return 0;
				}
				int ni = left+1;
				int nj = right;
				if (nj-ni > bj-bi) {
					bi = ni;
					bj = nj;
				}
			}
		}
		if (bi>=0) {
			dist[t][bi][bj] = dist[t][i][j]+2;
			pre[t][bi][bj] = pii(i,j);
			bfs.push({bi,bj,t});
		}
	}

	cout << "IMPOSSIBLE" << nl;

	return 0;
}
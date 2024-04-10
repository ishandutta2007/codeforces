//#include "stdafx.h"


#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };


int main() {
	int n;
	cin >> n;
	vector<vii> a(4, vii(n, vi(n)));
	rep(i, 4) {
		rep(j, n) {
			rep(k, n) {
				char c;
				scanf(" %c", &c);
				a[i][j][k] = c - '0';
			}
		}
	}
	int ans = inf;
	vi b = { 0,1,2,3 };
	do {
		vii c(2 * n, vi(2 * n));
		rep(i, n) {
			rep(j, n) {
				c[i][j] = a[b[0]][i][j];
			}
		}
		rep(i, n) {
			rep(j, n) {
				c[i][j + n] = a[b[1]][i][j];
			}
		}
		rep(i, n) {
			rep(j, n) {
				c[i + n][j] = a[b[2]][i][j];
			}
		}
		rep(i, n) {
			rep(j, n) {
				c[i + n][j + n] = a[b[3]][i][j];
			}
		}
		int cnt = 0;
		rep(i, 2 * n) {
			rep(j, 2 * n) {
				if ((i + j) % 2) {
					if (c[i][j]) {
						cnt++;
					}
				}
				else {
					if (!c[i][j]) {
						cnt++;
					}
				}
			}
		}
		ans = min(ans, cnt);
		rep(i, 2 * n) {
			rep(j, 2 * n) {
				if ((i + j) % 2) {
					if (!c[i][j]) {
						cnt++;
					}
				}
				else {
					if (c[i][j]) {
						cnt++;
					}
				}
			}
		}
		ans = min(ans, cnt);
	} while (next_permutation(b.begin(), b.end()));
	cout << ans << endl;
}
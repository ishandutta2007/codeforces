#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

bool exi[101][101];
void solve() {
	int n; cin >> n;
	rep(i, 4*n+1) {
		int x, y; cin >> x >> y;
		exi[x][y] = true;
	}
	rep(i, 51) {
		rep(j, 51) {
			Rep1(k, n, 50) {
				int cnt = 0;
				Rep1(x, j+1, j + k-1) {
					if (exi[i][x])cnt++;
					if (exi[i + k][x])cnt++;
				}
				Rep1(x, i + 1, i + k - 1) {
					if (exi[x][j])cnt++;
					if (exi[x][j + k])cnt++;
				}
				if (exi[i][j])cnt++;
				if (exi[i][j+k])cnt++;
				if (exi[i+k][j])cnt++;
				if (exi[i+k][j+k])cnt++;
				if(cnt==4*n){
					Rep1(x, j, j + k) {
						exi[i][x] = false;
						exi[i + k][x] = false;
					}
					Rep1(x, i, i + k) {
						exi[x][j] = exi[x][j + k] = false;
					}
					rep(x, 51) {
						rep(y, 51) {
							if (exi[x][y]) {
								cout << x << " " << y << endl; return;
							}
						}
					}
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
	//stop
	return 0;
}
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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n, m;
int a[400];
int need[400][400][400];

//k
int mem[401];
void init() {
	rep(i, 400) {
		rep(j, 400) {
			rep(k, 400) {
				need[i][j][k] = mod;
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) {
		cin >> a[i];
	}
	init();
	rep(i, n) {
		rep(j, 401) {
			mem[j] = i+j;
		}
		need[i][i][0] = 0;
		Rep(j, i + 1, n) {
			per1(k, j - i) {
				//jk,DP
				while (mem[k-1]+1<j&&need[i][mem[k - 1]+1][k - 1] < a[j] - a[mem[k - 1]+1]) {
					mem[k - 1]++;
				}
				int id = mem[k - 1];
				need[i][j][k] = min(need[i][j][k], max(need[i][id][k - 1], a[j] - a[id]));
				if(id + 1 < j) {
					need[i][j][k] = min(need[i][j][k], max(need[i][id + 1][k - 1], a[j] - a[id + 1]));
				}
			}
			need[i][j][0] = a[j] - a[i];
		}
	}
	ll ans = 0;
	rep(i, m) {
		int l, r, c, d;
		cin >> l >> r >> c >> d;
		d = min(d, r - l);
		l--; r--;
		//cout << ans << endl;
		ans = max(ans, (ll)c*need[l][r][d]);
	}
	cout << ans << endl;
	//cout << need[0][2][0] << endl;
	//stop
	return 0;
}
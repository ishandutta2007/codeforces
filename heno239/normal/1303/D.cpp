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
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



void solve() {
	ll n, m; cin >> n >> m;
	vector<ll> a(m);
	rep(i, m) {
		cin >> a[i];
	}
	ll sum = 0;
	rep(i, m)sum += a[i];
	if (sum < n) {
		cout << -1 << endl; return;
	}
	vector<int> cnt(55);
	rep(i, m) {
		int tmp = 0;
		ll s = 1;
		while (s < a[i]) {
			s <<= 1; tmp++;
		}
		cnt[tmp]++;
	}
	int ans = 0;
	rep(i, 50) {
		if ((n >> i) & 1) {
			if (cnt[i] == 0) {
				for (int j = i + 1; j < 50; j++) {
					if (cnt[j] > 1) {
						ans += j - i;
						for (int k = i; k < j; k++) {
							cnt[k]++;
						}
						cnt[i]++;
						cnt[j]--;
						break;
					}
					else if(cnt[j]==1){
						if ((n >> j) & 1) {
							continue;
						}
						else {
							//cout << "hello " << j << endl;
							ans += j - i;
							for (int k = i; k < j; k++) {
								cnt[k]++;
							}
							cnt[i]++;
							cnt[j]--;
							break;
						}
					}
				}
			}
			assert(cnt[i] > 0);
			cnt[i]--;
		}
		cnt[i + 1] += cnt[i] / 2;
	}
	cout << ans << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;rep(i,t) solve();
	//solve();
	stop
		return 0;
}
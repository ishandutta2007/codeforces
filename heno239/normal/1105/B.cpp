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
const ll mod = 998244353;
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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n, k;
string s;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k >> s;
	int ans = 0;
	rep(i, 26) {
		char t = 'a' + i;
		int cnt = 0;
		rep(j, n-k+1) {
			if (s[j] == t) {
				int c = 0;
				while (c < k) {
					if (s[j] == t) {
						c++; j++;
					}
					else {
						break;
					}
				}
				j--;
				if (c == k) {
					cnt++;
				}
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
	//stop
	return 0;
}
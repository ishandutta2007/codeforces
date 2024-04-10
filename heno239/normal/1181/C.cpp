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
const ll mod = 1000000007;
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

char mp[1000][1000];
int l[1000][1000];
bool b[1000][1000];
string pr[1000][1000];
void solve() {
	int h, w; cin >> h >> w;
	rep(i, h)rep(j, w)cin >> mp[i][j];
	rep(j, w) {
		stack<int> st;
		char memo = mp[0][j]; st.push(0);
		rep1(i, h-1) {
			if (memo == mp[i][j]) {
				st.push(i);
			}
			else {
				while (!st.empty()) {
					int pre = st.top(); st.pop();
					l[pre][j] = i - pre;
				}
				st.push(i);
				memo = mp[i][j];
			}
		}
		while (!st.empty()) {
			int pre = st.top(); st.pop();
			l[pre][j] = h - pre;
		}
	}
	rep(j, w) {
		rep(i, h) {
			b[i][j] = false;
			int len = l[i][j];
			int ni = i + len;
			if (ni >= h)continue;
			if (l[ni][j] != len)continue;
			ni += len;
			if (ni >= h)continue;
			if (l[ni][j] >= len) {
				b[i][j] = true;
				rep(k, 3) {
					pr[i][j].push_back(mp[i + k * len][j]);
				}
			}
		}
	}
	ll ans = 0;
	rep(i, h) {
		rep(j, w) {
			if (!b[i][j])continue;
			int le = j;
			while (j + 1 < w&&b[i][j + 1]&&pr[i][j]==pr[i][j+1])j++;
			int len = j - le + 1;
			ans += len * (len + 1) / 2;
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	//init();
	solve();
	//stop
	return 0;
}
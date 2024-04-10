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
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int n, m;
int a[1000][1000];
vector<int> vx[1000], vy[1000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> a[i][j];
		}
	}
	rep(i, n) {
		rep(j, m) {
			vx[i].push_back(a[i][j]);
		}
		sort(vx[i].begin(), vx[i].end());
		int len = unique(vx[i].begin(), vx[i].end()) - vx[i].begin();
		vx[i].erase(vx[i].begin() + len, vx[i].end());
	}
	rep(i, m) {
		rep(j, n) {
			vy[i].push_back(a[j][i]);
		}
		sort(vy[i].begin(), vy[i].end());
		int len = unique(vy[i].begin(), vy[i].end()) - vy[i].begin();
		vy[i].erase(vy[i].begin() + len, vy[i].end());
	}
	rep(i, n) {
		rep(j, m) {
			if (j > 0)cout << " ";
			int idx = lower_bound(vx[i].begin(), vx[i].end(), a[i][j]) - vx[i].begin();
			int idy = lower_bound(vy[j].begin(), vy[j].end(), a[i][j]) - vy[j].begin();
			int ans1 = mod, ans2 = mod;
			if(idx>=idy) ans1 = max(idx + (int)vy[j].size() - idy,(int)vx[i].size());
			if(idx<=idy) ans2 = max(idy + (int)vx[i].size() - idx,(int)vy[j].size());
			cout << min(ans1, ans2);
		}
		cout << endl;
	}
	//stop
		return 0;
}
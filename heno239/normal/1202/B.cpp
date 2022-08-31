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

//#define int long long
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
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

void solve() {
	string s; cin >> s;
	int n = s.length();
	rep(x, 10) {
		rep(y, 10) {
			int dist[10][10];
			rep(i, 10) {
				rep(j, 10) {
					dist[i][j] = mod;
				}
			}
			rep(i, 10) {
				queue<int> q;
				q.push(i);
				int tmp = 0;
				while (!q.empty()) {
					
					int len = q.size();
					rep(aa, len) {
						int cur = q.front(); q.pop();
						int t1 = (cur + x) % 10;
						int t2 = (cur + y) % 10;
						if (tmp < dist[i][t1]) {
							dist[i][t1] = tmp;
							q.push(t1);
						}
						if (tmp < dist[i][t2]) {
							dist[i][t2] = tmp;
							q.push(t2);
						}
					}
					//cout << tmp << endl;
					tmp++;
				}
			}
			ll sum = 0;
			int cur = 0;
			rep1(i, n-1) {
				int z = s[i] - '0';
				sum += dist[cur][z];
				cur = z;
				if (sum >= mod)break;
			}
			if (sum >= mod) {
				sum = -1;
			}
			if (y > 0)cout << " ";
			cout << sum;
		}
		cout << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}
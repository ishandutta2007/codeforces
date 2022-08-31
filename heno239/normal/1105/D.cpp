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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, p;
char mp[1000][1000];
int s[10];
queue<P> q[9];
bool used[1000][1000];
int ans[9];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;
	rep(i, p) {
		cin >> s[i];
	}
	int cnt = 0;
	rep(i, n) {
		rep(j, m) {
			cin >> mp[i][j];
			if ('0' <= mp[i][j] && mp[i][j] <= '9') {
				int t = mp[i][j] - '0'; t--;
				ans[t]++;
				q[t].push({ i,j });
				used[i][j] = true;
				cnt++;
			}
			else if (mp[i][j] == '#') {
				used[i][j] = true; cnt++;
			}
		}
	}
	int cur = 0;
	vector<int> v;
	rep(i, p) {
		v.push_back(i);
	}
	int len = v.size();
	int oricur = 0;
	while (cnt < n*m) {
		cur = v[oricur];
		int tmp = 0;
		while (tmp < s[cur] && !q[cur].empty()) {
			int len = q[cur].size();
			rep(j, len) {
				P z = q[cur].front(); q[cur].pop();
				rep(k, 4) {
					int nx = z.first + dx[k];
					int ny = z.second + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
					if (used[nx][ny])continue;
					used[nx][ny] = true; cnt++;
					q[cur].push({ nx,ny });
					ans[cur]++;
				}
			}

			tmp++;
		}
		if (q[cur].empty()) {
			v.erase(v.begin() + oricur); len--;
			if (len == 0)break;
			oricur = oricur % len;
		}
		else {
			oricur = (oricur + 1) % len;
		}
	}
	rep(i, p) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	//stop
	return 0;
}
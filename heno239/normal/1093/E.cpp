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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

vector<vector<int>> v;
int a[1 << 18], b[1 << 18],inv[1<<18],inva[1<<18];
int x[1 << 18];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	rep(i, n) {
		cin >> a[i];
		inva[a[i]] = i;
	}
	rep(i, n) {
		cin >> b[i];
		inv[b[i]] = i;
	}
	rep(i, n) {
		x[i] = inv[a[i]];
	}
	int d = sqrt(n);
	for (int j = 0; j < n; j += d) {
		int s = j; int t = min(n, j+d);
		vector<int> u;
		Rep(i, s, t) {
			u.push_back(x[i]);
		}
		sort(u.begin(), u.end());
		v.push_back(u);
	}
	rep(aa, m) {
		int t; cin >> t;
		if (t == 1) {
			int l[2], r[2]; cin >> l[0] >> r[0] >> l[1] >> r[1];
			l[0]--; r[0]--; l[1]--; r[1]--;
			if (l[1] > r[1])swap(l[1], r[1]);
			int ans = 0;
			int ss = l[0] / d, tt = r[0] / d;
			if (ss == tt) {
				Rep1(i, l[0], r[0]) {
					if (l[1] <= x[i] && x[i] <= r[1])ans++;
				}
			}
			else {
				Rep(i, l[0], d*(ss+1)) {
					if (l[1] <= x[i] && x[i] <= r[1])ans++;
				}
				Rep1(i, tt*d, r[0]) {
					if (l[1] <= x[i] && x[i] <= r[1])ans++;
				}
				Rep1(i, ss + 1, tt - 1) {
					int le = lower_bound(v[i].begin(), v[i].end(), l[1]) - v[i].begin();
					int ri = upper_bound(v[i].begin(), v[i].end(), r[1]) - v[i].begin();
					ans += ri - le;
				}
			}
			cout << ans << endl;
		}
		else {
			int l, r; cin >> l >> r; l--; r--;
			int lt = inva[b[l]]; int rt = inva[b[r]]; swap(b[l],b[r]);
			if (lt > rt)swap(lt, rt);
			int ss = lt / d, tt = rt / d;
			if (ss == tt) {
				swap(x[lt], x[rt]);
			}
			else {
				int id = lower_bound(v[ss].begin(), v[ss].end(), x[lt]) - v[ss].begin();
				v[ss].erase(v[ss].begin() + id);
				id = lower_bound(v[ss].begin(), v[ss].end(), x[rt]) - v[ss].begin();
				v[ss].insert(v[ss].begin()+id, x[rt]);

				id = lower_bound(v[tt].begin(), v[tt].end(), x[rt]) - v[tt].begin();
				v[tt].erase(v[tt].begin() + id);
				id = lower_bound(v[tt].begin(), v[tt].end(), x[lt]) - v[tt].begin();
				v[tt].insert(v[tt].begin() + id, x[lt]);

				swap(x[lt], x[rt]);
			}
		}
	}
	//stop
	return 0;
}
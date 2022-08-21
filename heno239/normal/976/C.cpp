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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n;
int l[1 << 19], r[1 << 19];
struct segm {
	int val, id, t;
	bool operator<(const segm &s)const {
		if (val != s.val)return val < s.val;
		if (t != s.t)return t < s.t;
		if(t==1)return l[id] < l[s.id];
		else return r[id] < r[s.id];
	}
};
void solve() {
	vector<segm> v;
	rep(i, n) {
		v.push_back({ l[i],i,0 });
		v.push_back({ r[i],i,1 });
	}
	sort(v.begin(), v.end());
	queue<P> q;
	rep(i, 2 * n) {
		if (i > 0 && v[i].val == v[i - 1].val&&v[i].t == v[i - 1].t) {
			if(v[i].t==0)cout << v[i - 1].id+1 << " " << v[i].id+1 << endl;
			else cout << v[i].id + 1 << " " << v[i - 1].id + 1 << endl;
			return;
		}
		else {
			if (v[i].t == 0) {
				q.push({ v[i].val,v[i].id });
			}
			else {
				if (q.front().first != l[v[i].id]) {
					cout << v[i].id + 1 << " " << q.front().second + 1 << endl;
					return;
				}
				else {
					q.pop();
				}
			}
		}
	}
	cout << -1 << " " << -1 << endl; return;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		cin >> l[i] >> r[i];
	}
	solve();
	//stop
		return 0;
}
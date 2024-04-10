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
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<int> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
}

ll multi(ll a, ll b) {
	ld x = log10(a) + log10(b);
	if (x > 18.1)return INF;
	return a * b;
}
ll plu(ll a, ll b) {
	return min(INF, a + b);
}

ll p[51];
ll num[51];
void init() {
	p[0] = 1;
	rep1(i, 50) {
		p[i] = multi(p[i-1], i);
	}
	num[0] = num[1]=1;
	Rep1(i,2, 50) {
		for (int j = 1; j <= i; j++) {
			ll csum = multi(p[max(0, j - 2)], num[i - j]);
			num[i] = plu(num[i], csum);
		}
		//cout << i << " " << num[i] << endl;
	}
}
ll calc(vector<int> v,int n) {
	ll res = 1;
	rep(i, n) {
		if (i >= v.size()) {
			res = multi(res, num[n - i]);
			break;
		}
		int ri = v[i];
		for (int j = i; j <= ri; j++) {
			if (j < v.size()) {
				if (v[j] > ri)return 0;
			}
		}
		if (ri < v.size()) {
			int cur = v[i]; int tmp = 1;
			while (cur != i) {
				cur = v[cur]; tmp++;
			}
			if (tmp != ri - i + 1)return 0;
		}
		else {
			for (int j = i; j <v.size(); j++) {
				int cur = v[j];
				while (cur!=j) {
					if (cur >= v.size())break;
					cur = v[cur];
				}
				if (cur == j)return 0;
			}
			int num = ri - i + 1 - (v.size() - i);
			res = multi(res , p[num - 1]);
		}
		i = ri;
	}
	return res;
}

void solve() {
	int n; ll k; cin >> n >> k;
	vector<bool> used(n,false);
	vector<int> ans;
	rep(i, n) {
		int chk = -1;
		rep(j, n) {
			if (used[j])continue;
			ans.push_back(j);
			ll num = calc(ans,n);
			if (k <= num) {
				chk = j; break;
			}
			else {
				k -= num;
				ans.pop_back();
			}
		}
		if (chk < 0) {
			cout << -1 << endl; return;
		}
		used[chk] = true;
	}
	rep(i, n)ans[i] = ans[i] + 1;
	debug(ans);
	
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	//stop
	return 0;
}
// kyopro.cpp : AvP[VGg |Cg`B
//

//#include "stdafx.h"


#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);


int main() {
	ll n, k, l;
	cin >> n >> k >> l;
	vl a(n * k);
	rep(i, n*k) {
		cin >> a[i];
	}
	sort(all(a));
	//DEBUG_VEC(a);
	ll mi = a[0];
	if (a[n - 1] - mi > l) {
		cout << 0 << endl;
		return 0;
	}
	vector<bool> used(n*k, false);
	vl use;
	use.push_back(mi);
	used[0] = true;
	auto itr = upper_bound(all(a), mi + l);
	itr--;
	int i = itr - a.begin();
	int j = n * k - 1;
	while (use.size() < n) {
		//DEBUG_VEC(used);
		int cnt = 0;
		while (cnt < k - 1) {
			if (!used[j]) {
				cnt++;
				used[j] = true;
			}
			j--;
			if (j < i) {
				i--;
			}
		}
		while (used[i]) {
			i--;
		}
		use.push_back(a[i]);
		used[i] = true;
		i--;
	}
	ll ans = 0;
	rep(i, n) {
		ans += use[i];
	}
	cout << ans << endl;
}
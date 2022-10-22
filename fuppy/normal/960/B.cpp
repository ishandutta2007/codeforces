//#include "stdafx.h";


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
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;//<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main(){
	int n;
	cin >> n;
	int k1, k2;
	cin >> k1 >> k2;
	int k = k1 + k2;
	vl a(n), b(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	vl e(n);
	rep(i, n) {
		e[i] = abs(a[i] - b[i]);
	}
	sort(e.begin(), e.end());
	reverse(e.begin(), e.end());
	int cnt = 0;
	int i = 0;
	ll ma = e[0];
	while (cnt < k) {
		if (ma == 0) {
			break;
		}
		cnt++;
		e[i]--;
		i++;
		if (i == n || e[i] < ma) {
			i = 0;
			ma = e[0];
		}
	}
	if (cnt != k) {
		e[0] = (k - cnt) % 2;
	}
	ll ans = 0;
	rep(i, n) {
		ans += e[i] * e[i];
	}
	cout << ans << endl;
}
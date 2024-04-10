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
#define Sp(p) cout<<setprecision(15)<< fixed<<p;//<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };



int main() {
	int n;
	cin >> n;
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	vl a(n);
	rep(i, n) {
		cin >> a[i];
	}
	ll ans = inf;
	int diff[3] = { -1, 0, 1 };
	rep(i0, 3) {
		rep(i1, 3) {
			ll cnt = 0;
			ll first = a[0] + diff[i0];
			ll now = a[1] + diff[i1];
			cnt += abs(diff[i0]) + abs(diff[i1]);
			ll d = now - first;
			for (int i = 2; i < n; i++) {
				ll nex = a[i];
				ll nex_d = now + d;
				if (abs(nex_d - nex) <= 1) {
					cnt += abs(nex_d - nex);
					now = nex_d;
				}
				else {
					cnt = inf;
					break;
				}
			}
			ans = min(ans, cnt);
		}
	}
	cout << (ans == inf ? -1 : ans) << endl;
}
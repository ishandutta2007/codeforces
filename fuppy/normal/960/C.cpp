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
	ll x, d;
	cin >> x >> d;
	d++;
	ll cnt = 0;
	int i = 32;
	vl ans;
	ll now = 1;
	while (i >= 0) {
		if (x & (1LL << i)) {
			rep(j, i) {
				ans.push_back(now);
			}
			cnt += (1LL << i) - 1;
			now += d;
		}
		i--;
	}
	while (cnt < x) {
		ans.push_back(now);
		now += d;
		cnt++;
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
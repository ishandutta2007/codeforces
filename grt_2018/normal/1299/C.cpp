#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 1000*1000+10;
const long double eps = -1e9;
int n;
ll a[nax];
vector<pair<int,ll> >Q;

bool ilo(pair<int,ll> A, pair<int,ll> B, pair<int,ll> C) {
	ll w1 = (A.ND-B.ND)*(B.ST-C.ST);
	ll w2 = (B.ND-C.ND)*(A.ST-B.ST);
	return w1<=w2;
}

long double ans[nax];

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]+=a[i-1];
	}
	Q.PB({0,0});
	for(int i=1; i<=n; i++) {
		while((int)Q.size()>=2&&ilo({i,a[i]},Q.back(),Q[(int)Q.size()-2])) {
			Q.pop_back();
		}
		Q.PB({i,a[i]});
	}
	int wsk = 1;
	for(int i=1; i<=n; i++) {
		while(Q[wsk].ST<i) wsk++;
		ll sum = Q[wsk].ND-Q[wsk-1].ND;
		int l = Q[wsk].ST-Q[wsk-1].ST;
		cout<<setprecision(10)<<(long double)sum/l<<"\n";
	}
		
	
}
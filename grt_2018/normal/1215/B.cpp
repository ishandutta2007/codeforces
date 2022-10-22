#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 200*1000+10;
int n,e;
int cnt1,cnt0;
ll ans,ans2;

int main() {_
	cin>>n;
	e=0;
	cnt0=1;
	for(int a,i=0; i<n;i++) {
		cin>>a;
		if(a<0) e = 1-e;
		if(e==1) ans+=cnt0;
		else ans+=cnt1;
		if(e==1) cnt1++;
		else cnt0++;
	}
	ans2 = (ll)n*(n+1)/2 - ans;
	cout<<ans<<" "<<ans2;
	
}
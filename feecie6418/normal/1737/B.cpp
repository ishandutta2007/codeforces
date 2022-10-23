#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const ll inf=1e9;
mt19937_64 rng(time(0));
int rnd(int l,int r){
	return l+rng()%(r-l+1);
}
ll Calc(ll x){//<x 
	ll L=1,R=inf,ans=0;
	while(L<=R){
		ll mid=(L+R)/2;
		if(mid*mid<=x)ans=mid,L=mid+1;
		else R=mid-1;
	}
	ll res=3*ans;
	return res+(x-1)/ans-(ans-1);
}
void Solve(){
	ll l,r;
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",Calc(r+1)-Calc(l));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}
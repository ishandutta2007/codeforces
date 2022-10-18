#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define ll long long
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define db double
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int n,i,j,T,x,y,v,a[N],sum;
//ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int main(){
	cin>>T;
	while(T--){
		cin>>n;sum=0;
		for(i=1;i<=n;++i)cin>>a[i],sum+=a[i];
		sum-=n;
		if(sum<0)cout<<"1\n";
		else if(sum==0)cout<<"0\n";
		else cout<<sum<<"\n";
	}
	return 0;
}
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
int n,i,j,T,x,y,v,a[N],sum,mn;
//ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);mn=1e9;
		for(i=1;i<n;++i)mn=min(mn,a[i+1]-a[i]);
		for(i=1;i<n;++i){
			if(a[i+1]-a[i]==mn){
				cout<<a[i]<<" ";
				for(j=i+2;j<=n;++j)cout<<a[j]<<" ";
				for(j=1;j<i;++j)cout<<a[j]<<" ";
				cout<<a[i+1]<<"\n";
				break;
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],sum,ans;
struct BIT{
	ll c[300005];
	void U(int x,ll y){
		x=max(x,1);
		while(x<=300000)c[x]+=y,x+=x&-x;
	}
	ll Q(int x){
		if(x<0)return 0;
		ll ret=0;
		while(x)ret+=c[x],x-=x&-x;
		return ret;
	}
}c1,c2;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]),sum+=a[i];
		for(int j=0;j<=300000;j+=a[i]){
			int l=j,r=min(j+a[i]-1,300000ll);
			ans+=(c1.Q(r)-c1.Q(l-1))*j;
			c2.U(l,j),c2.U(r+1,-j);
		}
		c1.U(a[i],1),ans+=c2.Q(a[i]);
		cout<<sum*i-ans<<' ';
	}
}
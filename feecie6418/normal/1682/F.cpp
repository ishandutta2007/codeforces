#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
const ll D=(ll)(4e14)+5,B=D/2;
int a[200005],b[200005],n,q; 
ll s[200005];
pr operator +(pr x,pr y){
	return pr((x.first+y.first)%mod,(x.second+y.second)%mod);
}
pr operator -(pr x,pr y){
	return pr((x.first-y.first+mod)%mod,(x.second-y.second+mod)%mod);
}
int ls[12000005],rs[12000005],tot,rt[200005];
pr sum[12000005];
void Insert(int &p,int q,ll l,ll r,ll x,int y,int z){
	p=++tot,ls[p]=ls[q],rs[p]=rs[q],sum[p]=sum[q]+pr(y,z);
	if(l==r)return ;
	ll mid=(l+r)/2;
	if(x<=mid)Insert(ls[p],ls[q],l,mid,x,y,z);
	else Insert(rs[p],rs[q],mid+1,r,x,y,z);
}
pr Query(int p,int q,ll l,ll r,ll x,ll y) {
	if(!p||q==p)return pr(0,0);
	if(x<=l&&r<=y)return sum[p]-sum[q];
	ll mid=(l+r)/2;
	pr ret=pr(0,0);
	if(x<=mid)ret=ret+Query(ls[p],ls[q],l,mid,x,y);
	if(mid<y)ret=ret+Query(rs[p],rs[q],mid+1,r,x,y);
	return ret;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]),s[i]=s[i-1]+b[i];
		Insert(rt[i],rt[i-1],1,D,s[i]+B,s[i]%mod*a[i]%mod,a[i]); 
	}
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		pr x1=Query(rt[r-1],rt[l-1],1,D,1,s[l-1]+B);
		int ans=(1ll*x1.second*(s[l-1]%mod+mod)%mod-x1.first+mod)%mod;
		x1=Query(rt[r-1],rt[l-1],1,D,s[l-1]+B,D);
		ans=(ans+x1.first-1ll*x1.second*(s[l-1]%mod+mod)%mod+mod)%mod;
		cout<<ans<<'\n';
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[1000005];
ll sum[4000005],mod;
vector<ll> t[4000005];
void Build(int p,int l,int r){
	if(l==r)return sum[p]=a[l],t[p].push_back(mod-a[l]-1),t[p].push_back(1e18);
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r),sum[p]=sum[p*2]+sum[p*2+1];
	for(int i=0;i<t[p*2].size();i++){
		ll tl=i?t[p*2][i-1]+1:-1e18,tr=t[p*2][i];
		ll l=tl-mod*i+sum[p*2],r=tr-mod*i+sum[p*2];//[l,r] 
		int L=lower_bound(t[p*2+1].begin(),t[p*2+1].end(),l)-t[p*2+1].begin(),R=lower_bound(t[p*2+1].begin(),t[p*2+1].end(),r)-t[p*2+1].begin();
		R=min(R,(int)t[p*2+1].size()-1);
		for(int j=L;j<=R;j++){
			if(t[p].size()&&t[p].size()-1==i+j)t[p][t[p].size()-1]=max(t[p][t[p].size()-1],min(tr,i*mod+t[p*2+1][j]-sum[p*2]));
			else t[p].push_back(min(tr,i*mod+t[p*2+1][j]-sum[p*2]));
		}
	}
}
ll Find(int p,int l,int r,int x,int y,ll s){
	if(x<=l&&r<=y){
		int x=lower_bound(t[p].begin(),t[p].end(),s)-t[p].begin();
		return s+sum[p]-x*mod;
	}
	int mid=(l+r)/2;
	if(x<=mid)s=Find(p*2,l,mid,x,y,s);
	if(mid<y)s=Find(p*2+1,mid+1,r,x,y,s);
	return s;
}
int main(){
	scanf("%d%d%lld",&n,&m,&mod);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	Build(1,1,n);
	for(int i=1,l,r;i<=m;i++)scanf("%d%d",&l,&r),printf("%lld\n",Find(1,1,n,l,r,0));
	return 0;
}
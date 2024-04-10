#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=(1ll<<60)-1;
const int mod=998244353;
struct Seg{
	ll l,r;
}a[5000005];
int n,m,cnt,c[50005][2],d[50005],tp[50005],tot,rt,t1[50005],t2[50005];
ll L[50005],R[50005];
ll aa[105][2],bb[105][2];
void Add(int &p,ll l,ll r,ll x,ll y,int z,int dep){
	if(!p)p=++tot,L[p]=l,R[p]=r,d[p]=dep;
	if(z==1)tp[p]|=z;
	if(x<=l&&r<=y){
		if(z==2)tp[p]|=z;
		return ;
	}
	ll mid=(l+r)/2;
	if(x<=mid)Add(c[p][0],l,mid,x,y,z,dep-1);
	if(mid<y)Add(c[p][1],mid+1,r,x,y,z,dep-1);
}
void Do(){
	for(int i=1;i<=n;i++)Add(rt,0,N,aa[i][0],aa[i][1],1,60);
	for(int i=1;i<=m;i++)Add(rt,0,N,bb[i][0],bb[i][1],2,60);
	for(int i=0;i<=60;i++){
		t1[0]=t2[0]=0;
		for(int j=1;j<=tot;j++){
			if(d[j]!=i)continue;
			if(tp[j]&1)t1[++t1[0]]=j;
			if(tp[j]&2)t2[++t2[0]]=j;
		}
		for(int j=1;j<=t1[0];j++){
			for(int k=1;k<=t2[0];k++){
				ll x=L[t1[j]]>>i,y=L[t2[k]]>>i;
				a[++cnt]={(x^y)<<i,((x^y)<<i)+(1ll<<i)-1};
			}
		}
	}
	rt=0;
	while(tot){
		c[tot][0]=c[tot][1]=d[tot]=tp[tot]=L[tot]=R[tot]=0;
		tot--;
	}
}
int Get(ll l,ll r){
	l%=mod,r%=mod;
	return (l+r)*(r-l+1)%mod*(mod+1)/2%mod;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>aa[i][0]>>aa[i][1];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>bb[i][0]>>bb[i][1];
	Do();
	swap(n,m);
	for(int i=1;i<=max(n,m);i++)swap(aa[i][0],bb[i][0]),swap(bb[i][1],aa[i][1]);
	Do();
	sort(a+1,a+cnt+1,[](Seg x,Seg y){return x.l<y.l;});
	ll curr=-1,ans=0;
	for(int i=1;i<=cnt;i++){
		if(a[i].l>curr){
			curr=a[i].r,ans+=Get(a[i].l,a[i].r);
		}
		else if(a[i].r>curr){
			ans+=Get(curr+1,a[i].r),curr=a[i].r;
		}
		ans=(ans%mod+mod)%mod;
	}
	cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
const int mod=1e9+9;
int t[1200005],n,q,f[1200005],len[1200005];
pr tag[1200005];
pr Shift(pr x,int y){//xy
	if(!y)return x;
	if(y==1)return pr(x.second,(x.first+x.second)%mod);
	return pr((1ll*x.first*f[y-2]+1ll*x.second*f[y-1])%mod,(1ll*x.first*f[y-1]+1ll*x.second*f[y])%mod);
}
void Tag(int p,pr x){
	tag[p].first=(tag[p].first+x.first)%mod;
	tag[p].second=(tag[p].second+x.second)%mod;
	int f1=f[len[p]-1],f2=(f[len[p]]-1+mod)%mod;
	t[p]=(t[p]+1ll*f1*x.first+1ll*f2*x.second)%mod;
}
void Pushdown(int p){
	if(tag[p].first||tag[p].second)Tag(p*2,tag[p]),Tag(p*2+1,Shift(tag[p],(len[p]+1)/2)),tag[p]=pr(0,0);
}
void Add(int p,int l,int r,int x,int y,pr fr){
	if(x<=l&&r<=y)return Tag(p,Shift(fr,l-x));
	int mid=(l+r)/2;
	Pushdown(p);
	if(x<=mid)Add(p*2,l,mid,x,y,fr);
	if(mid<y)Add(p*2+1,mid+1,r,x,y,fr);
	t[p]=(t[p*2]+t[p*2+1])%mod;
}
int Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	int mid=(l+r)/2,ret=0;
	Pushdown(p);
	if(x<=mid)ret=(ret+Query(p*2,l,mid,x,y))%mod;
	if(mid<y)ret=(ret+Query(p*2+1,mid+1,r,x,y))%mod;
	return ret;
}
void Build(int p,int l,int r){
	len[p]=r-l+1;
	if(l==r){
		scanf("%d",&t[p]);
		return ;
	}
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=(t[p*2]+t[p*2+1])%mod;
}
int main(){
	f[0]=f[1]=1;
	scanf("%d%d",&n,&q),Build(1,1,n);
	for(int i=2;i<=n+5;i++)f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1,op,x,y;i<=q;i++){
		scanf("%d",&op);
		if(op==2){
			scanf("%d%d",&x,&y),printf("%d\n",Query(1,1,n,x,y));
		}
		else {
			scanf("%d%d",&x,&y),Add(1,1,n,x,y,pr(1,1));
		}
	}
}
/*
10 10
1 3 5 7
1 5 7 4
2 3 6
*/
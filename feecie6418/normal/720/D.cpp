#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=1e6;
typedef long long ll;
int n,m,K,ans=0;
ll c1[1000005],c2[1000005];
int addtag[4000005],multag[4000005],sum[4000005],len[4000005];
struct Thing{
	int op,l,r;
};
vector<Thing> q[1000005];
void PushUp(int p){
    sum[p]=(sum[2*p]+sum[2*p+1])%mod;
}
void PushDown(int p){
    sum[p*2]=(1ll*sum[p*2]*multag[p]+1ll*addtag[p]*len[p*2])%mod;
    sum[p*2+1]=(1ll*sum[p*2+1]*multag[p]+1ll*addtag[p]*len[p*2+1])%mod;
    multag[p*2]=1ll*multag[p*2]*multag[p]%mod;
    multag[p*2+1]=1ll*multag[p*2+1]*multag[p]%mod;
    addtag[p*2]=(1ll*multag[p]*addtag[p*2]+addtag[p])%mod;
    addtag[p*2+1]=(1ll*multag[p]*addtag[p*2+1]+addtag[p])%mod;
    addtag[p]=0,multag[p]=1;
}
void Build(int p,int l,int r){
	multag[p]=1,len[p]=r-l+1;
	if(l==r)return ;
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	PushUp(p);
}
void Add(int p,int l,int r,int x,int y,int z){
	x=max(x,1),y=min(y,m);
	if(x>y)return ;
    if(l>=x&&r<=y){
        addtag[p]=(addtag[p]+z)%mod;
        sum[p]=(sum[p]+1ll*len[p]*z)%mod;
        return ;
    }
    PushDown(p);
    int mid=(l+r)/2;
    if(mid>=x)Add(2*p,l,mid,x,y,z);
    if(mid<y)Add(2*p+1,mid+1,r,x,y,z);
    PushUp(p);
}
void Mul(int p,int l,int r,int x,int y,int z){
	x=max(x,1),y=min(y,m);
	if(x>y)return ;
    if(l>=x&&r<=y){
        addtag[p]=1ll*addtag[p]*z%mod;
        multag[p]=1ll*multag[p]*z%mod;
        sum[p]=1ll*sum[p]*z%mod;
        return ;
    }
    PushDown(p);
    int mid=(l+r)/2;
    if(mid>=x)Mul(2*p,l,mid,x,y,z);
    if(mid<y)Mul(2*p+1,mid+1,r,x,y,z);
    PushUp(p);
}
int Sum(int p,int l,int r,int x,int y){
	x=max(x,1),y=min(y,m);
	if(x>y)return 0;
    if(l>=x&&r<=y)return sum[p];
    PushDown(p);
    int mid=(l+r)/2,ret=0;
    if(mid>=x)ret=(ret+Sum(2*p,l,mid,x,y))%mod;
    if(mid<y)ret=(ret+Sum(2*p+1,mid+1,r,x,y))%mod;
    return ret;
}
void Add_(int x,int y){
	int tx=x;
	while(x<=m)c1[x]+=y,c2[x]+=(1-tx)*y,x+=x&-x;
}
int Get(int x){
	ll r=0;
	int tx=x;
	while(x)r+=c1[x]*tx+c2[x],x-=x&-x;
	int ret=0;
	ll s1=0,s2=0;
	for(int i=20;i>=0;i--)
		if(ret+(1<<i)<=m&&(s1+c1[ret+(1<<i)])*(ret+(1<<i))+(s2+c2[ret+(1<<i)])<=r)ret+=(1<<i),s1+=c1[ret],s2+=c2[ret];
	return ret+1;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1,x1,y1,x2,y2;i<=K;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		q[x1].push_back({0,y1,y2});
		q[x2+1].push_back({1,y1,y2});
	}
	Build(1,1,m);
	for(int i=1;i<=n;i++){
		for(Thing j:q[i]){
			if(j.op==0)Add_(j.l,1),Add_(j.r+1,-1),Mul(1,1,m,j.l,j.r,0);
			else Add_(j.l,-1),Add_(j.r+1,1);
		}
		vector<Thing> t;
		for(Thing j:q[i]){
			if(j.op==1){
				int x=Sum(1,1,m,j.l-1,j.l-1);
				int k=Get(j.l-1);
				t.push_back({x,j.l,k-1});
			} 
		}
		if(i==1)t.push_back({1,1,Get(0)-1});
		for(Thing j:t)Add(1,1,m,j.l,j.r,j.op);
	}
	cout<<Sum(1,1,m,m,m);
}
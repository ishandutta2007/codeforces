#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int n,a[500005],b[500005],ans=0;
int addtag[2000005],multag[2000005],sum[2000005],len[2000005];
void PushUp(int p){
    sum[p]=(sum[2*p]+sum[2*p+1])%mod;
    len[p]=(len[2*p]+len[2*p+1])%mod;
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
	multag[p]=1;
	if(l==r)return len[p]=(b[l]-b[l-1])%mod,void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	PushUp(p);
}
void Add(int p,int l,int r,int x,int y,int z){
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
    if(l>=x&&r<=y)return sum[p];
    PushDown(p);
    int mid=(l+r)/2,ret=0;
    if(mid>=x)ret=(ret+Sum(2*p,l,mid,x,y))%mod;
    if(mid<y)ret=(ret+Sum(2*p+1,mid+1,r,x,y))%mod;
    return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	Build(1,1,m),Add(1,1,m,1,a[1],1);
	for(int i=2;i<=n;i++){
		int s=sum[1];
		if(a[i]<m)Mul(1,1,m,a[i]+1,m,0);
		Mul(1,1,m,1,a[i],mod-1);
		Add(1,1,m,1,a[i],s);
	}
	for(int i=1;i<=m;i++)ans=(ans+Sum(1,1,m,i,i))%mod;
	cout<<ans;
}
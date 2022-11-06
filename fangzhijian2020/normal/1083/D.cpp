#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,ans,a[100005],tmp[100005],tot,t[100005];
int pre[100005],suf[100005],q1[100005],tot1,q2[100005],tot2;
int size1[400005],size2[400005],Max[400005],Min[400005],sum1[400005],sum2[400005],tag[2][400005];
void Tag(int k,int x,int opt){
	if(opt==0){
		Max[k]=1ll*x*size1[k]%mod;
		sum2[k]=1ll*x*Min[k]%mod;
	}
	else{
		Min[k]=1ll*x*size1[k]%mod;
		sum1[k]=1ll*x*size2[k]%mod;
		sum2[k]=1ll*x*Max[k]%mod;
	}
	tag[opt][k]=x;
}
void pushdown(int k){
	if(tag[0][k]){
		Tag(k<<1,tag[0][k],0);
		Tag(k<<1|1,tag[0][k],0);
		tag[0][k]=0;
	}
	if(tag[1][k]){
		Tag(k<<1,tag[1][k],1);
		Tag(k<<1|1,tag[1][k],1);
		tag[1][k]=0;
	}
}
void pushup(int k){
	Max[k]=Mod(Max[k<<1]+Max[k<<1|1]);
	Min[k]=Mod(Min[k<<1]+Min[k<<1|1]);
	sum1[k]=Mod(sum1[k<<1]+sum1[k<<1|1]);
	sum2[k]=Mod(sum2[k<<1]+sum2[k<<1|1]);
}
void build(int k,int l,int r){
	if(l==r){
		size1[k]=1;size2[k]=l;
		Max[k]=1;sum1[k]=n+1;
		Min[k]=n+1;sum2[k]=1ll*l*(n+1)%mod;
		return;
	}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	size1[k]=size1[k<<1]+size1[k<<1|1];
	size2[k]=Mod(size2[k<<1]+size2[k<<1|1]);
	pushup(k);
}
void change(int k,int l,int r,int L,int R,int x,int opt){
	if(L<=l&&r<=R){Tag(k,x,opt);return;}
	int mid=l+r>>1;pushdown(k);
	if(L<=mid)change(k<<1,l,mid,L,R,x,opt);
	if(R>mid)change(k<<1|1,mid+1,r,L,R,x,opt);
	pushup(k);
}
int query(int k,int l,int r,int L,int R,int opt){
	if(L<=l&&r<=R){
		if(opt==0)return sum1[k];
		if(opt==1)return sum2[k];
		return Max[k];
	}
	int mid=l+r>>1,ans=0;pushdown(k);
	if(L<=mid)Add(ans,query(k<<1,l,mid,L,R,opt));
	if(R>mid)Add(ans,query(k<<1|1,mid+1,r,L,R,opt));
	return ans;
}
int sum(int l,int r){
	return Mod((1ll*r*(r+1)/2-1ll*l*(l-1)/2)%mod+mod);
}
int solve(int l,int r){
	return Mod(Mod(query(1,1,n,l,r,0)-1ll*sum(l,r)*r%mod+mod)+Mod(1ll*query(1,1,n,l,r,2)*r%mod-query(1,1,n,l,r,1)+mod));
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=tmp[i]=read();
	sort(tmp+1,tmp+n+1);tot=unique(tmp+1,tmp+n+1)-tmp-1;
	for(int i=1;i<=n;++i)a[i]=lower_bound(tmp+1,tmp+tot+1,a[i])-tmp;
	for(int i=1;i<=n;++i){pre[i]=t[a[i]];t[a[i]]=i;}
	for(int i=1;i<=n;++i)t[i]=n+1;
	for(int i=n;i;--i){suf[i]=t[a[i]];t[a[i]]=i;}
	build(1,1,n);int Max=0;
	for(int i=1;i<=n;++i){
		while(tot1&&pre[q1[tot1]]<=pre[i])--tot1;
		change(1,1,n,q1[tot1]+1,i,pre[i]+1,0);q1[++tot1]=i;
		while(tot2&&suf[q2[tot2]]>=suf[i])--tot2;
		change(1,1,n,q2[tot2]+1,i,suf[i]-1,1);q2[++tot2]=i;
		Max=max(Max,pre[i]);Add(ans,solve(Max+1,i));
	}
	cout<<ans<<"\n";
	return 0;
}
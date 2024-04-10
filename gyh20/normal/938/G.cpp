#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
inline void printnum(int x,char ch){
	print(x),pc(ch,false);
}
struct LB{
	int p[30];
	inline void ins(re int x){
		for(re int i=29;~i;--i)
			if(x&(1<<i)){
				if(!p[i]){
					p[i]=x;
					return;
				}
				x^=p[i];
			}
	}
	inline int ask(re int x){
		for(re int i=29;~i;--i)if(x&(1<<i))x^=p[i];
		return x;
	}
}P;
int n,fa[800002],d[800002],sz[800002],head[800002],cnt,m,q,l,a[800002],b[800002],c[800002],tot,sum[800002],stkx[800002],stky[800002],stkz[800002],s,tp,A[800002],B[800002];
map<pair<int,int>,int>mp;
map<int,int>v[800002];
struct node{int x,y,z;};
struct edge{node to;int next;}e[10000002];
inline int root(re int x){
	if(x==fa[x])return x;
	s^=d[x];
	return root(fa[x]);
}
inline void add(re int x,re node y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void ins(re int p,re int l,re int r,re int x,re int y,re node z){
	if(l>=x&&r<=y)return add(p,z);
	re int mid=l+r>>1;
	if(x<=mid)ins(p<<1,l,mid,x,y,z);
	if(y>mid)ins(p<<1|1,mid+1,r,x,y,z);
}
inline void merge(re int x,re int y,re int z){
	if(sz[x]>sz[y])swap(x,y);
	z^=s;
	fa[x]=y,d[x]=z,sz[y]+=sz[x];
	stkx[++tp]=x,stky[tp]=y,stkz[tp]=z;
}
inline void undo(re int x){
	while(tp^x){
		d[stkx[tp]]=0;
		fa[stkx[tp]]=stkx[tp],sz[stky[tp]]-=sz[stkx[tp]];
		--tp;
	}
}
inline void work(re int p,re int l,re int r,re LB L){
//	if(!(sum[r]-sum[l-1]))return;
	re int rr=tp;
	for(re int i=head[p];i;i=e[i].next){
		s=0;
		if((e[i].to.x=root(e[i].to.x))==(e[i].to.y=root(e[i].to.y)))L.ins(s^e[i].to.z);
		else merge(e[i].to.x,e[i].to.y,e[i].to.z);
	}
	if(l==r){
		if(!A[l])return;
		s=0,root(A[l]),root(B[l]);
		printf("%d\n",L.ask(s));
		return;
	}
	re int mid=l+r>>1;
	work(p<<1,l,mid,L),work(p<<1|1,mid+1,r,L);
	undo(rr);
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)sz[fa[i]=i]=1;
	for(re int i=1,x,y,z;i<=m;++i){
		++tot;
		a[i]=x=read(),b[i]=y=read(),c[i]=z=read();
		if(x>y)swap(x,y),swap(a[i],b[i]);
		v[x][y]=z;
		mp[make_pair(a[i],b[i])]=1;
	}
	q=read();
	for(re int i=1,x,y,z;i<=q;++i){
		re int o=read();
		if(o==1){
			++tot;
			a[tot]=read(),b[tot]=read(),c[tot]=read();
			v[a[tot]][b[tot]]=c[tot];
			if(a[tot]>b[tot])swap(a[tot],b[tot]);
			mp[make_pair(a[tot],b[tot])]=i;
		}
		else if(o==2){
			x=read(),y=read();
			if(x>y)swap(x,y);
			ins(1,1,q,mp[make_pair(x,y)],i,(node){x,y,v[x][y]});
			mp.erase(make_pair(x,y));
		}
		else{
			A[i]=read(),B[i]=read();
			sum[i]=1;
		}
		sum[i]+=sum[i-1];
	}
	memset(P.p,0,sizeof(P.p));
	for(re int i=1;i<=tot;++i)if(mp.count(make_pair(a[i],b[i])))ins(1,1,q,mp[make_pair(a[i],b[i])],q,(node){a[i],b[i],c[i]});
	work(1,1,q,P);
	
}
#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(ll x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(ll x,char ch)
{
	if(x<0)pc('-',false),x=-x;
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0,f=0;re char v=gc();
	while(v<'0')f|=(v=='-'),v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return f?-t:t;
}
int n,m,head[1000002],cnt,fa[1000002],dfn[1000002],a[1000002],siz[1000002],F[1000002],sz[1000002],c1[1000002],tim;
ll c[1000002],ans[1000002],SUM[1000002];char ia[1000002];
struct edge{int to,next;}e[2000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline int root(re int x){return x==F[x]?x:F[x]=root(F[x]);}
inline ll Div(re ll x,re int y){return x<0?x/y:(x+y-1)/y;}
inline void Merge(re int x,re int y){F[x]=y,sz[y]+=sz[x],SUM[y]+=SUM[x];}
struct node{
	int x;ll y;
	bool operator <(const node A)const{return y>A.y;}
};
struct Qry{
	int x,y,id;
	bool operator <(const Qry A)const{return y<A.y;}
}p[1000002];
priority_queue<node>Q;
inline void dfs(re int x,re int y){
	fa[x]=y,dfn[x]=++tim,siz[x]=1,a[x]=-1;re int mx=-1;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x),siz[x]+=siz[e[i].to],++a[x],mx=max(mx,a[e[i].to]);
	if(mx<a[x]&&(x^1))Q.push((node){x,-a[x]});
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,0),m=read();for(re int i=1;i<=n;++i)F[i]=i,sz[i]=1,SUM[i]=a[i];
	for(re int i=1;i<=m;++i)p[i].x=read(),p[i].y=-read(),p[i].id=i;
	sort(p+1,p+m+1);
	for(re int i=1;i<=m;++i){
		while(Q.size()&&Q.top().y<=p[i].y){
			re int x=Q.top().x,z=root(fa[x]);Q.pop();
			if(F[x]^x)continue;
			re ll Sz=SUM[x];re int l=dfn[fa[z]],r=dfn[fa[x]];
			if(!l){
				for(;r<=n;r+=r&(-r))c[r]+=Sz,c1[r]+=sz[x];
			}
			else{
				while((l<=n||r<=n)&&(l^r)){
					if(l<r)c[l]-=Sz,c1[l]-=sz[x],l+=l&(-l);
					else c[r]+=Sz,c1[r]+=sz[x],r+=r&(-r);
				}
			}
			Merge(x,z);if(z^1)Q.push((node){z,Div(-SUM[z],sz[z])});
		}
		re ll s=1;re int s1=0,r=dfn[p[i].x]+siz[p[i].x]-1,l=dfn[p[i].x]-1;
		while((l||r)&&(l^r)){
			if(r>l)s+=c[r],s1+=c1[r],r^=r&(-r);
			else s-=c[l],s1-=c1[l],l^=l&(-l);
		}
		ans[p[i].id]=s+a[p[i].x]+1ll*s1*p[i].y;
	}
	for(re int i=1;i<=m;++i)printnum(ans[i],'\n');pc('o',1);
}
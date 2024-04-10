#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(long long x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(long long x,char ch)
{
	print(x),pc(ch,false);
}
inline long long read(){
	re long long t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
const long long inf=1e15;
int n,m,rt[200002],ls[15000002],rs[15000002],head[200002],cnt,q,tot,siz[15000002],ans1,b[1000002];
long long a[200002];
struct edge{int to,next;}e[400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]};head[x]=cnt;}
long long ans[200002],ans2;
vector<long long>v[200002];
inline int merge(re int x,re int y,re long long l,re long long r){
	if((!x)||(!y))return x+y;
	siz[x]+=siz[y];
	if(l==r)return x;
	re long long mid=l+r>>1;
	ls[x]=merge(ls[x],ls[y],l,mid),rs[x]=merge(rs[x],rs[y],mid+1,r);
	return x;
}
inline void add(re int &p,re long long l,re long long r,re long long x){
	if(!p)p=++tot;
	++siz[p];
	if(l==r)return;
	re long long mid=l+r>>1;
	if(x<=mid)add(ls[p],l,mid,x);
	else add(rs[p],mid+1,r,x);
}
inline void ask(re int p,re long long l,re long long r,re long long x){
	if(!p)return;
	if(r<=x){ans1+=siz[p];return;}
	re long long mid=l+r>>1;
	if(x>mid)ask(rs[p],mid+1,r,x);
	ask(ls[p],l,mid,x);
}
inline void dfs1(re int x){for(re int i=head[x];i;i=e[i].next)a[e[i].to]+=a[x],dfs1(e[i].to);}
inline void dfs2(re int x){
	for(re int i=head[x];i;i=e[i].next)dfs2(e[i].to);
	for(re int i=head[x];i;i=e[i].next)rt[x]=merge(rt[x],rt[e[i].to],1,inf);
	add(rt[x],1,inf,a[x]-b[x]+1000000000);
	for(re int i=0;i<v[x].size();i+=2){
		re long long y=v[x][i],z=v[x][i+1];
		ans1=ans2=0,ask(rt[x],1,inf,a[x]+1000000000);
		ans[z]=ans1-1;
	}
}
signed main(){
	n=read();a[1]=1;
	for(re int i=1;i<=n;++i)b[i]=read();
	for(re int i=2;i<=n;++i)add(read(),i),a[i]=read();
	dfs1(1),q=n;
	for(re int i=1,x,y;i<=q;++i)x=i,v[x].push_back(b[i]),v[x].push_back(i);
	dfs2(1);
	for(re int i=1;i<=q;++i)printnum(ans[i],' ');
	return pc('o',1);
}
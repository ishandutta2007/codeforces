#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=100000;
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
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0,f=0;re char v=gc();
	while(v<'0')f|=(v=='-'),v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return f?-t:t;
}
int n,m,X[300002],w[300002],L[300002],R[300002],stk[300002],tp;
ll c[300002],ans[300002],inf=4e18;
inline void Add(re int x,re ll y){if(!x)return;for(;x<=n;x+=x&(-x))c[x]=min(c[x],y);}
inline ll ask(re int x,re ll s=inf){for(;x;x^=x&(-x))s=min(s,c[x]);return s;}
struct node{int x;ll y;};
vector<node>N[300002],Q[300002];
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)c[i]=inf,X[i]=read(),w[i]=read();
	for(re int i=1;i<=n;++i){
		while(tp&&w[i]<=w[stk[tp]])R[stk[tp--]]=i;
		stk[++tp]=i;
	}
	tp=0;
	for(re int i=n;i;--i){
		while(tp&&w[i]<=w[stk[tp]])L[stk[tp--]]=i;
		stk[++tp]=i;
	}
	for(re int i=1;i<=n;++i)N[i].push_back((node){R[i],1ll*(X[R[i]]-X[i])*(w[i]+w[R[i]])}),N[L[i]].push_back((node){i,1ll*(X[i]-X[L[i]])*(w[i]+w[L[i]])});
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),Q[x].push_back((node){y,i});
	for(re int i=n;i;--i){
		for(auto o:N[i])Add(o.x,o.y);
		for(auto o:Q[i])ans[o.y]=ask(o.x);
	}
	for(re int i=1;i<=m;++i)printnum(ans[i],'\n');pc('o',1);
}
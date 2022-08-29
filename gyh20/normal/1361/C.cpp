#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define re register
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
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,a[500002],b[500002],head[2100002],cnt,ans[2000002],tot,fa[2000002];
char v[4200002];
struct edge{int to,next;}e[4200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
char d[1<<20];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline bool ck(re int x){
	fill(d,d+x+1,0);
	for(re int i=0;i<=x;++i)fa[i]=i;
	for(re int i=1;i<=n;++i)d[a[i]&x]^=1,d[b[i]&x]^=1,fa[root(a[i]&x)]=root(b[i]&x);
	for(re int i=2;i<=n;++i)if(root(a[i]&x)^root(a[1]&x))return 0;
	for(re int i=0;i<=x;++i)if(d[i])return 0;
	return 1;
}
inline void dfs(re int x){
	re int id=0;
	for(re int&i=head[x];i;i=e[i].next)if(!v[i])v[i]=v[i^1]=1,id=i,dfs(e[i].to),ans[++tot]=id;
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read(),b[i]=read();
	re int l=1,r=20,pos=0;
	while(l<=r){
		re int mid=l+r>>1;
		if(ck((1<<mid)-1))pos=mid,l=mid+1;
		else r=mid-1; 
	}printnum(pos,'\n'),pos=(1<<pos)-1;cnt=1;
	for(re int i=1;i<=n;++i)add(a[i]&pos,b[i]&pos),add(b[i]&pos,a[i]&pos);dfs(a[1]&pos);
	for(re int i=tot;i;--i)printnum(ans[i]-1,' '),printnum((ans[i]^1)-1,' ');pc('o',1);
}
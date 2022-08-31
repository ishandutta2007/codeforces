#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2,3,4,5)
#include<cstdio>
#include<algorithm>
#define re register
using namespace std;
const int Mxdt=500000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;
	re char v=gc();
	while(v<'0')v=gc();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=gc();
	}
	return t;
}
int siz[100002],head[100002],n,cnt,w[100002],col[100002],son[100002],mx,to[200002],nxt[200002];
long long ans[100002],mxc;
inline void add(re int x,re int y){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void dfs(re int x,re int y){
	siz[x]=1;
	for(re int i=head[x];i;i=nxt[i]){
		if(to[i]!=y){
			dfs(to[i],x);
			if(siz[to[i]]>siz[son[x]])son[x]=to[i];
			siz[x]+=siz[to[i]];
		}
	}
}
void calc(re int x,re int y,re int k){
	col[w[x]]+=k;
	if(col[w[x]]>mx)mx=col[w[x]],mxc=w[x];
	else if(col[w[x]]==mx)mxc+=w[x];
	for(re int i=head[x];i;i=nxt[i]){
		if(to[i]!=y)calc(to[i],x,k);
	}
}
void dsu(re int x,re int y){
	for(re int i=head[x];i;i=nxt[i]){
		if(to[i]!=y&&to[i]!=son[x])dsu(to[i],x),calc(to[i],x,-1);}
	mx=mxc=0;
	if(son[x])dsu(son[x],x);
	++col[w[x]];
	if(col[w[x]]>mx)mx=col[w[x]],mxc=w[x];
	else if(col[w[x]]==mx)mxc+=w[x];
	for(re int i=head[x];i;i=nxt[i]){
		if(to[i]!=y&&to[i]!=son[x])calc(to[i],x,1);
	}
	ans[x]=mxc;
}
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
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)w[i]=read();
	for(re int i=1;i<n;++i){
		re int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	dfs(1,1);
	dsu(1,1);
	for(re int i=1;i<=n;++i)printnum(ans[i],' ');
	return pc('0',1);
}
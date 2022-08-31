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
#define ll long long
using namespace std;
const int Mxdt=100000;	// 
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
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,fa[200002],head[200002],v[200002],id[200002],tim,num,oo,cnt,dfn[200002],top[200002],ID[200002];
ll sum;
char f[200002];
struct edge{int to,next,w;}e[400002];
inline void add(re int x,re int y,re int z){
	e[++cnt]=(edge){y,head[x],z},head[x]=cnt;
}
inline void dfs(re int x,re int y){
	dfn[x]=++tim,top[x]=dfn[x]==dfn[fa[x]]+1?top[fa[x]]:x,ID[dfn[x]]=id[x];if(top[x]<=1)top[x]=x;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			fa[e[i].to]=x,id[e[i].to]=e[i].w,dfs(e[i].to,x);
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y,i),add(y,x,i);
	dfs(1,1),oo=1;
	while(1){
		re int o=read();
		if(o==3)break;
		if(o==1){
			++oo;
			re int x=read();
			while(x>1){
				for(re int i=dfn[x];i>=dfn[top[x]];--i){
					num+=ID[i]>0?1:-1;
					sum+=ID[i],ID[i]=-ID[i];
				}
				x=fa[top[x]];
			}
			if(num+num==oo)printf("%lld\n",sum);
			else puts("0");
			fflush(stdout);
		}
		else{
			if(num+num!=oo){
				puts("0");fflush(stdout);
				continue;
			}
			printf("%d ",num);
			vector<int>A;
			for(re int i=2;i<=n;++i)if(ID[i]<0)A.push_back(-ID[i]);sort(A.begin(),A.end());
			for(auto z:A)printnum(z,' ');pc('o',1);
			puts(""),fflush(stdout);
		}
	}
}
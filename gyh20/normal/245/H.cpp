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
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define re register
char s[5003];
int n,f[5003],ch[5003][27],len[5003],la,lst,tot,num[5003],ans[5002][5002],q,sum;
inline int gf(re int x,re int p){
	while(s[p]!=s[p-len[x]-1]){
	x=f[x];}
	return x;
}
const int Mxdt=500000;
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int insert(re int x){
	re int y=gf(lst,x);
	if(!ch[y][s[x]]){
	len[++tot]=len[y]+2;
	f[tot]=ch[gf(f[y],x)][s[x]];//printf("%d %d %d %d\n",tot,len[tot],f[tot],gf(f[y],x));
	ch[y][s[x]]=tot;
	num[tot]=num[f[tot]]+1;}sum+=num[ch[y][s[x]]];
	return num[lst=ch[y][s[x]]];
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch){
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1),f[0]=tot=1,len[1]=-1;s[0]=27;
	for(re int i=1;i<=n;++i)s[i]-='a';
	for(re int i=1;i<=n;++i){
		memset(len,0,sizeof(len));memset(ch,0,sizeof(ch));memset(f,0,sizeof(f));
		f[0]=tot=1,len[1]=-1;s[0]=27;lst=sum=0;
		for(re int j=1;j<=n-i+1;++j)insert(j),ans[i][i+j-1]=sum;
		s[1]=0;
		for(re int j=1;j<=n-i;++j)s[j]=s[j+1];}
	q=read();
	while(q--){
		re int x=read(),y=read();
		printf("%d\n",ans[x][y]);
	}
//	return pc('o',true);
}
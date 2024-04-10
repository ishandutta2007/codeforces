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
#include<unordered_map>
using namespace std;
#define re register
#define M 51123987
char s[2000003];
int n,f[2000003],len[2000003],la,lst,tot,num[2000003],len1[2000003],len2[2000003],ans,kk[2000003];
long long sum;
unordered_map<int,int>ch[27];
inline int gf(re int x,re int p) {
	while(s[p]!=s[p-len[x]-1])x=f[x];
	return x;
}
const int Mxdt=500000;
inline char pc(char ch,bool bj) {
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int insert(re int x) {
	re int y=gf(lst,x);
	if(!ch[s[x]][y]) {
		len[++tot]=len[y]+2;
		f[tot]=ch[s[x]][gf(f[y],x)];
		kk[tot]=kk[f[tot]]+1;//printf("%d %d %d %d\n",tot,len[tot],f[tot],gf(f[y],x));
		ch[s[x]][y]=tot;
	}
	return ++num[lst=ch[s[x]][y]];
}
void print(int x) {
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch) {
	print(x),pc(ch,false);
}
signed main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	f[0]=tot=1,len[1]=-1;
	s[0]=27;
	int sss=0;
	for(re int i=1; i<=n; ++i) {
		s[i]-='a';sss+=s[i];
		insert(i);
		len1[i]=kk[lst];
	}
	for(re int i=tot; i>1; --i)num[f[i]]+=num[i],sum+=num[i],sum%=M;
	memset(f,0,sizeof(f));
	memset(len,0,sizeof(len));
	lst=0;
	memset(num,0,sizeof(num));
	memset(kk,0,sizeof(kk));
	for(re int i=0; i<=26; ++i)ch[i].clear();
	f[0]=tot=1,len[1]=-1;
	s[0]=27;
	reverse(s+1,s+n+1);
	for(re int i=1; i<=n; ++i) {
		insert(i);
		len2[i]=kk[lst];
	}
	reverse(len2+1,len2+n+1);
	for(re int i=n; i; --i)(len2[i]+=len2[i+1])%=M;
	ans=1ll*sum*(sum-1)/2%M;
	for(re int i=1; i<=n; ++i)(ans-=1ll*len1[i]*len2[i+1]%M)%=M;
	printf("%d",(ans+M)%M);
//	return pc('o',true);
}
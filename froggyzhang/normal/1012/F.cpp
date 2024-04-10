#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
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
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 23
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,tot,ans[N][2],pre[1<<N],pos[1<<N],lim[1<<N];
int dp[1<<N];
struct Range{
	int l,r,id,t;
	bool operator <(const Range b)const{
		return l<b.l;
	}
}a[N];
void dfs(int st,int type){
	if(!st)return;
	ans[a[pre[st]].id][0]=type,ans[a[pre[st]].id][1]=pos[st];
	dfs(st^(1<<(pre[st]-1)),type);
} 
int main(){
	n=read(),m=read(),tot=(1<<n)-1;
	for(register int i=1;i<=n;++i){
		a[i].l=read(),a[i].r=a[i].l+read()-1,a[i].id=i,a[i].t=read();
	}
	sort(a+1,a+n+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=1;
	lim[0]=1;
	for(register int i=1;i<(1<<n);++i){
		for(register int j=1;j<=n;++j){
			if((i>>(j-1))&1){
				int u=(i^(1<<(j-1)));
				if(dp[u]==inf)continue;
				int now=dp[u];
				for(register int p=lim[u];p<=n;++p){
					if(now<a[p].l)break;
					if(now>=a[p].l&&now<=a[p].r)now=max(now,a[p].r+1);
				}
				for(register int k=1;k<=j;++k){
					if(now+a[j].t>=dp[i])break;
					if(!((i>>(k-1))&1)||a[k].r<now)continue;
					if(now<=a[k].l&&now+a[j].t>=a[k].l){
						now=max(now,a[k].r+1);
						for(register int p=lim[u];p<=n;++p){
							if(now<a[p].l)break;
							if(now>=a[p].l&&now<=a[p].r)now=max(now,a[p].r+1);
						}
					}
				}
				if(now+a[j].t>=a[j].l)continue;
				if(now+a[j].t<dp[i]){
					pos[i]=now,pre[i]=j;
					dp[i]=now+a[j].t;
					lim[i]=lim[u];
					while(lim[i]<=n&&a[lim[i]].r<now)++lim[i];
				}
			}
		}
	}
	if(m==1){
		if(dp[tot]^inf)dfs(tot,1);
	}
	else{
		for(register int i=0;i<(1<<n);++i){
			if(dp[i]^inf&&dp[tot^i]^inf){
				dfs(i,1),dfs(tot^i,2);
				break;
			}
		}
	}
	if(!ans[1][0]){
		printf("NO\n");return 0;
	}
	printf("YES\n");
	for(int i=1;i<=n;++i){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
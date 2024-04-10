#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 5050
inline char nc() {
    static char buf[100000],*p1,*p2;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
int rd() {
    int x=0; char s=nc();
    while(s<'0'||s>'9') s=nc();
    while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+s-'0',s=nc();
    return x;
}
int rc() {
	char s=nc();
	while(s!='0'&&s!='1') s=nc();
	return s-'0';
}
int n,m,Q,dis[N][N],w[N],cnt[N],ans[N][1350];
void dfs(int s1,int s2,int dep,int sum) {
	if(dep==n) {
		dis[s1][s2]=sum; return ;
	}
	dfs(s1|(1<<dep),s2|(1<<dep),dep+1,sum+w[dep+1]);
	dfs(s1,s2,                  dep+1,sum+w[dep+1]);
	dfs(s1,s2|(1<<dep),         dep+1,sum);
	dfs(s1|(1<<dep),s2,         dep+1,sum);
}
int main() {
	n=rd(); m=rd(); Q=rd();
	int i,j,mask=(1<<n)-1,sum=0;
	for(i=n;i;i--) w[i]=rd(),sum+=w[i];
	sum=min(sum,100);
	for(i=1;i<=m;i++) {
		int x=0;
		for(j=1;j<=n;j++) x=x*2+rc();
		cnt[x]++;
	}
	dfs(0,0,0,0);
	// printf("%d\n",dis[3][3]);
	for(i=0;i<=mask;i++) {
		for(j=0;j<=mask;j++) {
			ans[i][dis[i][j]]+=cnt[j];
		}
		for(j=1;j<=sum;j++) ans[i][j]+=ans[i][j-1];
	}
	// printf("%d\n",dis[0][1]);
	while(Q--) {
		int x=0; 
		for(i=1;i<=n;i++) x=x*2+rc();
		int K=rd();
		K=min(K,sum);
		printf("%d\n",ans[x][K]);
	}
}
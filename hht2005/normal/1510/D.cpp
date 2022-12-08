#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int f[maxn][10],pre[maxn][10],v[maxn],cnt;
double g[maxn][10];
void print(int n,int d) {
	if(n==0) {
		if(!cnt)puts("-1");
		else printf("%d\n",cnt);
		return;
	}
	if(f[n][d]==0)print(n-1,d);
	else cnt++,print(n-1,pre[n][d]),printf("%d ",v[n]);
}
signed main() {
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%d",v+i);
	memset(f,-1,sizeof(f));
	f[0][1]=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<10;j++)
			if(f[i][j]!=-1) {
				if(g[i][j]+log(v[i+1])>g[i+1][j*v[i+1]%10]) {
					g[i+1][j*v[i+1]%10]=g[i][j]+log(v[i+1]);
					f[i+1][j*v[i+1]%10]=1;
					pre[i+1][j*v[i+1]%10]=j;
				}
				if(f[i+1][j]==-1||g[i][j]>g[i+1][j]) {
					g[i+1][j]=g[i][j];
					f[i+1][j]=0;
					pre[i+1][j]=j;
				}
			}
	}
	if(f[n][d]==-1)puts("-1");
	else print(n,d);
	return 0;
}
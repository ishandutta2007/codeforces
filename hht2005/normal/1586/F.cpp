#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int col[N][N],tot;
void solve(int l,int r,int dep,int k) {
	if(l==r)return;
	tot=max(tot,dep);
	int L=(r-l)/k+1;
	for(int i=l;i+L<=r;i+=L)
		for(int j=i;j<=i+L-1;j++)
			for(int k=i+L;k<=r;k++)
				col[j][k]=dep;
	for(int i=l;i<=r;i+=L)
		solve(i,min(i+L-1,r),dep+1,k);
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	solve(1,n,1,k);
	printf("%d\n",tot);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			printf("%d ",col[i][j]);
	return 0;
}
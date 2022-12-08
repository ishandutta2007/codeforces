#include<bits/stdc++.h>
using namespace std; 
const int N=110;
#define fi first
#define se second
pair<int,int>a[N];
int f[N][N][2];
int main() {
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1);
	a[0]=make_pair(-1e9,0);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int p=0;p<2;p++) {
				f[i][j][p]=max(a[j].se,f[i][j][p]);
				ans=max(ans,f[i][j][p]);
				int R=a[j].fi+p*a[j].se,Max=-1e9,x=0,y=0;
				for(int k=i+1;k<=n;k++)
					for(int q=0;q<2;q++) {
						int now=a[k].fi+q*a[k].se;
						if(now<=R)continue;
						if(Max<now)Max=now,x=k,y=q;
						f[k][x][y]=max(f[k][x][y],f[i][j][p]+min(now-R,a[k].se)+Max-now);
					}
			}
	printf("%d\n",ans);
	return 0;
}
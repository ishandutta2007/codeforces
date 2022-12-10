#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=510;
const int INF=1000000000;
int n,a[MAX][MAX],p[MAX],d[MAX][MAX];
long long r[MAX];
bool alive[MAX];
main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=i==j?0:INF;
	for(int z=n;z>=1;z--){
		int x=p[z];
		alive[x]=true;
		for(int i=1;i<=n;i++)if(alive[i]){
			d[i][x]=a[i][x];
			d[x][i]=a[x][i];
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			d[x][i]=min(d[x][i],d[x][j]+d[j][i]);
			d[i][x]=min(d[i][x],d[i][j]+d[j][x]);
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			d[i][j]=min(d[i][j],d[i][x]+d[x][j]);
		}
		long long sum=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(alive[i]&&alive[j])sum+=d[i][j];
		r[z]=sum;
	}
	for(int i=1;i<=n;i++)printf("%I64d ",r[i]);
	puts("");
}
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
int main(){
	int n,m,k,q;
	scanf("%d %d %d %d",&n,&m,&k,&q);
	int dp[505][505];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		dp[i][j]=1e9+1;
	for(int i=0;i<q;i++){
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		dp[x][y]=t;
	}
	//for(int i=1;i<=n;i++,printf("\n"))
	//	for(int j=1;j<=m;j++)
	//	printf("%d ",dp[i][j]);
	int a[505];
	int ans=1e9+1;
	for(int i=1;i<=n-k+1;i++){
		for(int j=1;j<=m;j++){
			a[j]=0;
			for(int K=i;K<i+k;K++)
			a[j]=max(a[j],dp[K][j]);
			//printf("%d ",a[j]);
		}
	//	printf("\n");
		map<int,int> ma;
		for(int j=1;j<k;j++){
			ma[a[j]]++;	
		}
		for(int j=k;j<=m;j++){
			ma[a[j]]++;
			ans=min(ans,ma.rbegin()->x);
			if(--ma[a[j-k+1]]==0){
				ma.erase(a[j-k+1]);
			}
		}
	}
	if(ans==1e9+1)
	ans=-1;
	printf("%d\n",ans);
}
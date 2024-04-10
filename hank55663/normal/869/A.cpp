#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int vis[5000005];
int main(){
	MEM(vis);
	int n;
	scanf("%d",&n);
	int x[2005],y[2005];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		vis[x[i]]=1;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&y[i]);
		vis[y[i]]=1;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			if(vis[x[i]^y[j]])
			ans++;
		}
	printf("%s\n",ans%2?"Koyomi":"Karen");
} 
//200 2048 11
//10 
//01 
//1001 
//10011
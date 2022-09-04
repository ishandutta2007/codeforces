#include<bits/stdc++.h>
#include<assert.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define rank Rank
using namespace std;
typedef long long LL;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[200005],dp[200005];
	for(int i=0;i<k;i++)
	a[i]=1,dp[i]=0;
	vector<pii> ans;
	for(int i=2;i<=n;i++){
		ans.pb(mp(a[(i-2)%k],i));
		dp[(i-2)%k]++;
		a[(i-2)%k]=i;
	}
	sort(dp,dp+k);
	printf("%d\n",dp[k-1]+dp[k-2]);
	for(vector<pii>::iterator it=ans.begin();it!=ans.end();it++){
		printf("%d %d\n",it->x,it->y);
	}
}
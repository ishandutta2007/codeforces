#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	LL ans=0;
	int l[100005];
	for(int i=0;i<n;i++)
		scanf("%d",&l[i]);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(t){
			ans+=l[i];
			l[i]=0;
		}
	}
	LL sum[100005];
	sum[0]=0;
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+l[i-1];
	LL Max=0;
	for(int i=k;i<=n;i++){
		Max=max(Max,sum[i]-sum[i-k]);
	}
	printf("%lld\n",Max+ans);
}
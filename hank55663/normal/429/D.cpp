#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define index Index
#define N 300005
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int sum[100005];
	sum[0]=0;
	for(int i=0;i<n;i++){
		sum[i+1]=sum[i]+a[i];
	}
	LL res=1e9;
	for(int i=1;sqr(i)<res;i++){
		for(int j=i+1;j<=n;j++){
			res=min(res,sqr(i)+sqr((LL)(sum[j]-sum[j-i])));
		}
	}
	printf("%lld\n",res);
}
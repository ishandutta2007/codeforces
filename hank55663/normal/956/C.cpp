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
	int n;
	scanf("%d",&n);
	int m[100005];
	for(int i=0;i<n;i++)
		scanf("%d",&m[i]);
	int ans[100005];
	ans[0]=1;
	for(int i=1;i<n;i++){
		ans[i]=max(m[i]+1,ans[i-1]);
	}
	for(int i=n-2;i>=0;i--){
		ans[i]=max(ans[i],ans[i+1]-1);
	}
	LL a=0;
	for(int i=0;i<n;i++){
		a+=ans[i]-m[i]-1;
	}
	printf("%lld\n",a);
}
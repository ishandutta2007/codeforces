#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	LL sum=0;
	int a[500005];
	int Max=-1e9-1,Min=1e9+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=abs(a[i]);
		Max=max(Max,a[i]);
		Min=min(Min,a[i]);
	}
	if(Max<0)
	sum+=Max*2;
	if(Min>0&&n!=1)
	sum-=Min*2;
	printf("%lld\n",sum);
	return 0;
}
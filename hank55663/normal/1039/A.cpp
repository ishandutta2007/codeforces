#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n;
	LL t;
	scanf("%d %lld",&n,&t);
	LL a[200005];
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	a[n+1]=4e18+1;
	int x[200005];
	LL Max[200005];
	LL Min[200005];
	MEM(Min);
	fill(Max,Max+n+1,4e18);
	x[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		if(x[i]<x[i-1]){
			printf("No\n");
			return 0;
		}
		if(x[i]<i){
			printf("No\n");
			return 0;
		}
		if(x[i]!=i){
			Min[i]=max(a[i+1]+t,Min[i]);
		}
		if(x[i]==x[i-1]){
			Min[i-1]=max(a[i]+t,Min[i-1]);
		}
		if(x[i]!=x[i-1]){
			Max[i-1]=min(a[i]+t-1,Max[i-1]);
		}
		Min[i]=max(a[i]+t,Min[i]);
		Min[i]=max(Min[i],Min[i-1]+1);
	}
	int ok=1;
	for(int i=1;i<=n;i++){
	//	printf("%lld %lld\n",Max[i],Min[i]);
		if(Max[i]<Min[i])
		ok=0;
	}
	if(!ok)
	printf("No\n");
	else{
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		printf("%lld ",Min[i]);
		printf("\n");
	}
}
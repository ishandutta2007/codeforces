#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int a[200005];
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	map<int,int> ma;
	for(int i = 0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		ma[a]=max(ma[a],b);
	}
	sort(a,a+n);
	LL pre[200005];
	pre[0]=0;
	for(int i = 1;i<=n;i++){
		pre[i]=pre[i-1]+a[i-1];
	}
	LL dp[2005];
	dp[0]=0;
	for(int i = 1;i<=k;i++){
		dp[i]=dp[i-1]+a[i-1];
		for(auto it:ma){
			if(it.x>i)
			break;
			dp[i]=min(dp[i],dp[i-it.x]+pre[i]-pre[i-it.x+it.y]);
		}
		
		//printf("%d\n",dp[i]);
	}
	printf("%lld\n",dp[k]);
}
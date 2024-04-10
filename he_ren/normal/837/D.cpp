#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200 + 5;
const int MAXM = 200 + 5;
const int LB = 60;
const int LOG5 = 26;

inline int min(int a,int b){ return a<b? a: b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Node
{
	int x,y;
}a[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.y<q.y;}

ll pw2[LB + 5], pw5[LOG5 + 5];

int dp[MAXM][LOG5*MAXN];

int main(void)
{
	pw2[0]=pw5[0]=1;
	for(int i=1; i<=LB; ++i) pw2[i]=pw2[i-1]<<1ll;
	for(int i=1; i<=LOG5; ++i) pw5[i]=pw5[i-1]*5;
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		ll t;
		cin>>t;
		for(int j=1; j<=LB; ++j)
		{
			if(t%pw2[j]) break;
			a[i].x=j;
		}
		for(int j=1; j<=LOG5; ++j)
		{
			if(t%pw5[j]) break;
			a[i].y=j;
		}
	}
	sort(a+1,a+n+1,cmp);
	
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	
	int sum=0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=min(m,i)-1; j>=0; --j)
			for(int k=0; k<=sum; ++k)
				if(dp[j][k]!=-1) chk_max(dp[j+1][k+a[i].y], dp[j][k]+a[i].x);
		sum+=a[i].y;
	}
	
	int ans=0;
	for(int i=0; i<=sum; ++i)
		chk_max(ans, min(dp[m][i], i));
	printf("%d",ans);
	return 0;
}
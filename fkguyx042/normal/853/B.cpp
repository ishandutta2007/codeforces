#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 1000005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

const int inf=(int)1e9;

int i,j,m,n,p,k;

vector<pair<int,int> >In[N],Out[N];

int Time[N],d,f,t,c;

long long A[N],B[N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	long long ans=(long long)1e15;
	for (i=1;i<=m;++i)
	{
			scanf("%d%d%d%d",&d,&f,&t,&c);
			if (f==0)
			Out[d].pb(mk(t,c));
			else In[d].pb(mk(f,c));
	}
	int cnt=0; long long sum=0;
	for (i=1;i<=n;++i) Time[i]=inf,cnt++,sum+=inf;
	for (i=1;i<=1000000;++i)
	{
			for (j=0;j<(int)In[i-1].size();++j)
				if (Time[In[i-1][j].fi]>In[i-1][j].se)
				{
						if (Time[In[i-1][j].fi]==inf) cnt--;
						sum-=Time[In[i-1][j].fi]-In[i-1][j].se;
						Time[In[i-1][j].fi]=In[i-1][j].se;
				}
			if (cnt==0) A[i]=sum; else A[i]=(long long)1e18;
	}
	sum=0; cnt=0;
	for (i=1;i<=n;++i) Time[i]=inf,cnt++,sum+=inf;
	for (i=1000000;i>=1;--i)
	{
			for (j=0;j<(int)Out[i+1].size();++j)
				if (Time[Out[i+1][j].fi]>Out[i+1][j].se)
				{
						if (Time[Out[i+1][j].fi]==inf) cnt--;
						sum-=Time[Out[i+1][j].fi]-Out[i+1][j].se;
						Time[Out[i+1][j].fi]=Out[i+1][j].se;
				}
			if (cnt==0) B[i]=sum; else B[i]=(long long)1e18;
	}
	for (i=1;i+k<=1000000;++i)
		ans=min(ans,A[i]+B[i+k-1]);
	if (ans==(long long)1e15) printf("-1\n");
	else printf("%I64d\n",ans); 
}
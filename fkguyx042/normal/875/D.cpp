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

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,L[N],R[N],low[N],RR[N],LL[N],a[N];

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		for (i=1;i<=n;++i) 
		{
				L[i]=i-1;
				while (L[i]&&a[L[i]]<a[i]) L[i]=L[L[i]];
				LL[i]=L[i];
				for (j=0;j<=30;++j) if ((a[i]&(1<<j))==0)
				LL[i]=max(LL[i],low[j]);
				for (j=0;j<=30;++j) if ((a[i]&(1<<j))) low[j]=i;
		}
		for (i=0;i<=30;++i) low[i]=n+1;
		for (i=n;i;--i) 
		{
				R[i]=i+1;
				while (R[i]<=n&&a[R[i]]<=a[i]) R[i]=R[R[i]];
				RR[i]=R[i];
				for (j=0;j<=30;++j) if ((a[i]&(1<<j))==0)
				RR[i]=min(RR[i],low[j]);
				for (j=0;j<=30;++j) if ((a[i]&(1<<j))) low[j]=i;
		}
		long long ans=0;	
		for (i=1;i<=n;++i)
		{
				ans+=1ll*(i-L[i])*(R[i]-i);
				ans-=1ll*(i-LL[i])*(RR[i]-i);
		}
		printf("%I64d\n",ans);
}
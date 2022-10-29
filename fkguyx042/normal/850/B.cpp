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
#define M 2000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,sum[N],x,y,a[N];

long long A[M],B[M];

int main()
{
		scanf("%d%d%d",&n,&x,&y); 
		for (i=1;i<=n;++i) scanf("%d",&a[i]),A[a[i]]+=1ll*a[i]*y,B[a[i]]++;
		for (i=1;i<M;++i) A[i]+=A[i-1],B[i]+=B[i-1]; 
		long long ans=(long long)1e18;
		for (i=2;i<M;++i) 
		{
				long long sum=0;
				for (j=i;j<M;j+=i)
				{
						int down=j-i+1,up=j-i+1,P=(x+y-1)/y;down=max(j-i,j-P);
						sum-=(A[j-1]-A[down]);
						sum+=1ll*(B[j-1]-B[down])*j*y;	
						sum+=(B[down]-B[j-i])*x;
						if (sum>ans) break;
				}
				ans=min(ans,sum);
		}
			cout<<ans<<endl;
}
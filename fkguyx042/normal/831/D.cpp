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

int i,j,m,n,p,k,a[N],b[N];

int main()
{
		scanf("%d%d%d",&n,&m,&p);
		int ans=(int)2e9;
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		for (i=1;i<=m;++i) scanf("%d",&b[i]);
		sort(a+1,a+n+1); sort(b+1,b+m+1);
		for (i=1;i+n-1<=m;++i)
		{
				int Ans=0;
				for (j=1;j<=n;++j)
					Ans=max(Ans,abs(a[j]-b[i+j-1])+abs(p-b[i+j-1]));
				ans=min(ans,Ans);
		}
		cout<<ans<<endl;
}
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

int i,j,m,n,p,k,A[N],ans;

int main()
{
		scanf("%d%d",&n,&k);
		for (i=1;i<=n;++i) scanf("%d",&p),A[p]=1;
		for (i=0;i<k;++i) ans+=1-A[i];
		ans+=A[k];
		printf("%d\n",ans);
}
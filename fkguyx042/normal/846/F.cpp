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

int i,j,m,n,p,k;

vector<int>v[N];

long long ans;

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i)
		{
				scanf("%d",&k);
				v[k].pb(i);
		}
		for (i=1;i<N;++i)
		{
				int la=0;
				for (j=0;j<(int)v[i].size();++j)
					ans+=2ll*(v[i][j]-la)*(n-v[i][j]+1)-1,la=v[i][j];
		}
		printf("%.10lf\n",1.*ans/(1.*n*n)); 
}
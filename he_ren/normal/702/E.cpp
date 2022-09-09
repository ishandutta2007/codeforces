#include<cstdio>
#include<cmath>
#include<iostream>
typedef long long ll;
const int MAXN = 1e5 + 5;
const int LB = 34;
using namespace std;

inline int min(int a,int b){ return a<b? a: b;}

int n,lb;
ll k;
int to[MAXN][LB];
ll sum[MAXN][LB];
int mn[MAXN][LB];

void init(void)
{
	for(int j=1; j<=lb; ++j)
	{
		for(int i=1; i<=n; ++i)
		{
			to[i][j] = to[to[i][j-1]][j-1];
			sum[i][j] = sum[i][j-1] + sum[ to[i][j-1] ][j-1];
			mn[i][j] = min(mn[i][j-1], mn[ to[i][j-1] ][j-1]);
		}
	}
}

inline void print(int u)
{
	ll s=0;
	int m=1e8 + 5;
	ll t=k;
	
	for(int i=lb; i>=0 && t; --i)
		if((1ll<<i)<=t)
		{
			s += sum[u][i];
			m = min(m,mn[u][i]);
			u = to[u][i];
			t -= 1ll<<i;
		}
	
	cout<<s<<" "<<m<<endl;
}

int main(void)
{
	cin>>n>>k;
	for(int i=1; i<=n; ++i)
		scanf("%d",&to[i][0]), ++to[i][0];
	for(int i=1; i<=n; ++i)
		scanf("%d",&mn[i][0]), sum[i][0]=mn[i][0];
	
	lb = log(k)/log(2);
	init();
	
	for(int i=1; i<=n; ++i) print(i);
	return 0;
}
#include<cstdio>
#include<iostream>
typedef long long ll;
const int MAXN = 3e5 + 5;
const ll inf = 1e18 + 5;
using namespace std;

ll a[MAXN],b[MAXN];
ll f[MAXN][4];

inline void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		cin>>a[i]>>b[i];
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<=2; ++j)
		{
			f[i][j]=inf;
			for(int k=0; k<=2; ++k)
				if(a[i-1]+k != a[i]+j)
					f[i][j] = min(f[i][j], f[i-1][k]+j*b[i]);
		}
	}
	
	ll ans=inf;
	for(int i=0; i<=2; ++i)
		ans = min(ans,f[n][i]);
	
	cout<<ans<<endl;
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}
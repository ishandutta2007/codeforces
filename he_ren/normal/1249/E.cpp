#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline ll min(ll a,ll b){ return a<b? a: b;}
inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

int a[MAXN],b[MAXN];
ll f[MAXN],g[MAXN];

int main(void)
{
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=1; i<n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<n; ++i) scanf("%d",&b[i]);
	
	f[1]=c;
	g[1]=0;
	for(int i=2; i<=n; ++i)
	{
		f[i] = b[i-1] + min(f[i-1], g[i-1]+c);
		g[i] = a[i-1] + min(f[i-1], g[i-1]);
	}
	
	for(int i=1; i<=n; ++i) cout<<min(f[i],g[i])<<' ';
	return 0;
}
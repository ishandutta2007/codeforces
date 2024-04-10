#include<cstdio>
#include<iostream>
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
using namespace std;

int n;
ll f[MAXN];
int x[MAXM];

inline void update(int l,int r,ll k)
{
	if(r<l) return;
	f[l]+=k;
	f[r+1]-=k;
}

inline void gao(int a,int b)
{
	if(a>b) swap(a,b);
	if(a==b) return;
	
	update(a+1,b-1, b-a-1);
	
	update(1,a-1, b-a);
	update(b+1,n, b-a);
	
	update(a,a, b-1);
	update(b,b, a);
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d",&x[i]);
	for(int i=1; i<m; ++i)
	{
		gao(x[i],x[i+1]);
	}
	
	ll ans=f[0];
	for(int i=1; i<=n; ++i)
	{
		ans+=f[i];
		cout<<ans<<' ';
	}
	return 0;
}
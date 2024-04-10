#include<cstdio>
#include<cmath>
#include<iostream>
typedef long long ll;
const int MAXN = 1e6 + 5;
const int LB = 30;
using namespace std;

int m,a[MAXN],s[MAXN];

ll ans=0;
int son[MAXN*LB][3],sz[MAXN*LB],cnt=1;
inline void gao(int x)
{
	for(int i=LB, u=1; i>=0; --i)
	{
		if(!u) break;
		int bit=(x>>i)&1, mbit=(m>>i)&1;
		
		if(mbit)
			u=son[u][bit^1];
		else
		{
			ans+=sz[son[u][bit^1]];
			u=son[u][bit];
		}
	}
	
	for(int i=LB, u=1; i>=0; --i)
	{
		int bit=(x>>i)&1;
		if(!son[u][bit]) son[u][bit]=++cnt;
		u=son[u][bit];
		++sz[u];
	}
}

inline void print(int u,int l)
{
	if(!u) {return;};
	
	for(int i=1; i<=l; ++i) printf(" ");
	printf("[%d]{\n",sz[u]);
	print(son[u][0],l+1);
	print(son[u][1],l+1);
	for(int i=1; i<=l; ++i) printf(" ");
	printf("}\n");
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	--m;
	gao(0);
	for(int i=1; i<=n; ++i)
	{
		s[i]=s[i-1]^a[i];
		gao(s[i]);
	}
	
	//print(1,0);
	cout<<ans;
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const int MAXN = 1e6 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

ll pw(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res = res*a %mod;
		a = a*a %mod;
		b>>=1;
	}
	return res;
}

vector<int> a[MAXN];
int t[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			a[i].push_back(x);
			++t[x];
		}
	}
	
	int ans=0;
	ll invn = pw(n,mod-2);
	for(int i=1; i<=n; ++i)
	{
		int d = a[i].size();
		int invd = pw(d,mod-2);
		int p = invn*invd %mod;
		
		for(int j=0; j<d; ++j)
		{
			int x=a[i][j];
			add_mod(ans, invn*t[x] %mod * p %mod);
		}
	}
	printf("%d",ans);
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int mod = 1e6 + 3;
const int MAXN = 10 + 5;

inline ll pw(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

inline void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}

inline int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	
	int res;
	scanf("%d",&res);
	if(!res) answer(x);
	if(res==-1) exit(0);
	return res;
}

vector<int> mat[MAXN];

int main(void)
{
	int n = 10;
	
	for(int i=0; i<=n; ++i)
	{
		mat[i].resize(n+2);
		
		mat[i][0] = 1;
		for(int j=1; j<=n; ++j)
			mat[i][j] = (ll)mat[i][j-1] * i %mod;
		
		mat[i].back() = ask(i);
	}
	
	for(int i=0; i<=n; ++i)
	{
		int now = -1;
		for(int j=i; j<=n; ++j)
			if(mat[j][i]){ now=j; break;}
		
		if(now==-1)
		{
			for(int j=i; j<(int)mat[i].size(); ++j)
				mat[i][j] = 0;
			continue;
		}
		
		swap(mat[i], mat[now]);
		
		ll inv = pw(mat[i][i], mod-2);
		for(int j=i; j<(int)mat[i].size(); ++j)
			mat[i][j] = mat[i][j] * inv %mod;
		
		for(int j=0; j<=n; ++j) if(j!=i)
		{
			ll tmp = mat[j][i];
			for(int k=i; k<(int)mat[j].size(); ++k)
				mat[j][k] = (mat[j][k] - mat[i][k] * tmp %mod + mod) %mod;
		}
	}
	
	for(int i=0; i<mod; ++i)
	{
		int res = 0;
		ll tmp = 1;
		for(int j=0; j<=n; ++j)
		{
			res = (res + mat[j].back() * tmp) %mod;
			tmp = tmp * i % mod;
		}
		if(!res) answer(i);
	}
	answer(-1);
	return 0;
}
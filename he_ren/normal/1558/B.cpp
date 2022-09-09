#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 4e6 + 6;

int mod;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int f[MAXN], sum[MAXN];
inline int get(int l,int r)
{
	int res = sum[l] - sum[r+1];
	return res < 0? res + mod: res;
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&mod);
	
	f[n] = sum[n] = 1;
	for(int i=n-1; i>=1; --i)
	{
		f[i] = sum[i+1];
		for(int j=2; i*j<=n; ++j)
		{
			int l = i*j, r = min(n, i*j + j-1);
			add_mod(f[i], get(l,r));
		}
		add_mod(sum[i] = sum[i+1], f[i]);
	}
	
	printf("%d",f[1]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int sz = 320;
const int SZ = sz + 2;

ll a[MAXN];
vector<int> id[MAXM];

int p[SZ], pcnt = 0, atp[MAXM];
int num[MAXM][SZ];
ll f[SZ], tag[SZ];

int main(void)
{
	int n,m,Q;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	for(int i=1; i<=m; ++i)
	{
		int k;
		scanf("%d",&k);
		
		ll sum = 0;
		id[i].resize(k);
		for(int j=0; j<k; ++j)
			scanf("%d",&id[i][j]), sum += a[id[i][j]];
		
		if(k >= sz) p[atp[i] = ++pcnt] = i, f[pcnt] = sum;
	}
	
	for(int k=1; k<=pcnt; ++k)
	{
		static bool at[MAXN];
		int cur = p[k];
		for(int i=0; i<(int)id[cur].size(); ++i)
			at[id[cur][i]] = 1;
		
		for(int i=1; i<=n; ++i)
			for(int j=0; j<(int)id[i].size(); ++j)
				if(at[id[i][j]]) ++num[i][k];
		
		for(int i=0; i<(int)id[cur].size(); ++i)
			at[id[cur][i]] = 0;
	}
	
	while(Q--)
	{
		static char s[10];
		int k;
		scanf("%s%d",s+1,&k);
		if(s[1] == '?')
		{
			if(atp[k]) printf("%lld\n",f[atp[k]]);
			else
			{
				ll res = 0;
				for(int i=0; i<(int)id[k].size(); ++i)
					res += a[id[k][i]];
				for(int i=1; i<=pcnt; ++i)
					res += tag[i] * num[k][i];
				printf("%lld\n",res);
			}
		}
		else
		{
			int x;
			scanf("%d",&x);
			
			for(int i=1; i<=pcnt; ++i)
				f[i] += (ll)x * num[k][i];
			
			if(atp[k]) tag[atp[k]] += x;
			else
			{
				for(int i=0; i<(int)id[k].size(); ++i)
					a[id[k][i]] += x;
			}
		}
	}
	return 0;
}
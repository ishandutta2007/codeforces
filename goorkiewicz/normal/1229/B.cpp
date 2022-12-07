#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

const ll mod = 1000000007;
const int N = 100005;
const int K = 17;
int n, i, j;
ll out;
ll dep [N];
ll val [N];
int up [N][K+1];
ll re [N][K+1];
vector <int> e [N];
vector < pair <ll,ll> > vec [N];
vector < pair <ll,ll> > V;


void dfs (int u, int f)
	{
	int i;
	V.clear();
	for (pair <ll,ll> P : vec[f])
		V.push_back({__gcd(P.fi, val[u]), P.se});
	
	V.push_back({val[u], 1});
	sort(V.begin(), V.end());
	
	for (i=0; i<V.size(); i++)
		{
		if (i==0 || V[i]!=V[i-1])
			vec[u].push_back(V[i]);
		else
			vec[u].back().se += V[i].se;
		}
	
	for (pair <ll,ll> P : vec[u])
		out = (out + P.fi*P.se)%mod;

	for (int v : e[u])
		if (v!=f)
			dfs(v, u);
	}

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		scanf ("%lld", &val[i]);
	for (i=1; i<n; i++)
		{
		int a, b;
		scanf ("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
		}
	
	dfs(1, 0);
	printf ("%lld\n", out);

	return 0;
	}
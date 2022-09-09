#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXA = 1e6 + 5;

bool isnp[MAXA];
int pri[MAXA], pcnt = 0;
void sieve(int n)
{
	isnp[1] = 1;
	for(int i=2; i<=n; ++i) if(!isnp[i])
	{
		pri[++pcnt] = i;
		for(int j=i+i; j<=n; j+=i)
			isnp[j] = 1;
	}
}

inline ll get_res(vector<int> &a)
{
	int n = (int)a.size();
	if(n <= 1) return 0;
	for(int &x: a)
	{
		if(x == 1) x = 0;
		else x = isnp[x]? 2: 1;
	}
	
	vector<int> lef(n+1), rig(n+1);
	for(int i=0; i<n; ++i)
		lef[i+1] = a[i] == 0? lef[i] + 1: 0;
	for(int i=n-1; i>=0; --i)
		rig[i] = a[i] == 0? rig[i+1] + 1: 0;
	
	ll res = 0;
	for(int i=0; i<n; ++i) if(a[i] == 1)
	{
		int x = lef[i], y = rig[i+1];
		res += (ll)(x+1) * (y+1) - 1;
	}
	return res;
}

int a[MAXN];

void solve(void)
{
	int n,e;
	scanf("%d%d",&n,&e);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = 0;
	for(int i=1; i<=e; ++i)
	{
		vector<int> b;
		for(int j=i; j<=n; j+=e) b.push_back(a[j]);
		ans += get_res(b);
	}
	
	printf("%lld\n",ans);
}

int main(void)
{
	sieve(MAXA - 1);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
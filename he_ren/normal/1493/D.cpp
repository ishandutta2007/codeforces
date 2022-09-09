#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXA = 2e5 + 5;
const int MAXP = 1.8e4 + 5;
const int mod = 1e9 + 7;

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

bool isnp[MAXA];
int pri[MAXP], pcnt = 0, mnp[MAXA];
inline void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pcnt] = i, mnp[i] = pcnt;
		for(int j=1; j<=pcnt && (ll)i*pri[j]<=n; ++j)
		{
			isnp[i*pri[j]] = 1;
			mnp[i*pri[j]] = j;
			if(!(i%pri[j])) break;
		}
	}
}

inline vector<pii> get_fact(int x)
{
	vector<pii> res;
	while(x>1)
	{
		int pid = mnp[x], cur = pri[pid], cnt = 0;
		while(x%cur == 0) x /= cur, ++cnt;
		res.push_back(make_pair(pid, cnt));
	}
	return res;
}

int n, ans = 1;
map<int,int> f[MAXP];
multiset<int> g[MAXP];

inline void update(int pos,int x)
{
	vector<pii> fact = get_fact(x);
	for(int i=0; i<(int)fact.size(); ++i)
	{
		int pid = fact[i].first, cnt = fact[i].second;
		int now = (f[pid][pos] += cnt), lst = now - cnt;
		
		int lmn = (int)g[pid].size() < n? 0: *g[pid].begin();
		if(lst) g[pid].erase(g[pid].find(lst));
		g[pid].insert(now);
		int cmn = (int)g[pid].size() < n? 0: *g[pid].begin();
		
		if(cmn > lmn)
			ans = ans * pw(pri[pid], cmn - lmn) %mod;
	}
}

int main(void)
{
	sieve(MAXA - 1);
	
	int Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		update(i,x);
	}
	
	while(Q--)
	{
		int pos,x;
		scanf("%d%d",&pos,&x);
		update(pos, x);
		printf("%d\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

inline int get(int a[],int n,int k)
{
	int pos = lower_bound(a+1,a+n+1,k) - a;
	assert(pos <= n);
	if(a[pos] != k) return -pos;
	return pos;
}

inline ll calc(vector<pii> &p)
{
	sort(p.begin(),p.end());
	ll res = 0;
	for(int i=0,j=0; i<(int)p.size(); i=j)
	{
		while(j<(int)p.size() && p[i].first == p[j].first) ++j;
		int len = j - i;
		res += (ll)len * (len - 1) / 2;
	}
	for(int i=0,j=0; i<(int)p.size(); i=j)
	{
		while(j<(int)p.size() && p[i] == p[j]) ++j;
		int len = j - i;
		res -= (ll)len * (len - 1) / 2;
	}
	return res;
}

int a[MAXN], b[MAXN];

void solve(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	vector<pii> p,q;
	for(int i=1; i<=d; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x = get(a,n,x); y = get(b,m,y);
		if(x > 0 && y > 0) continue;
		if(x > 0) p.push_back(make_pair(-y, x));
		else q.push_back(make_pair(-x, y));
	}
	
	printf("%lld\n",calc(p) + calc(q));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
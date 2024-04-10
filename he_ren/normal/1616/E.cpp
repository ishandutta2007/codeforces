#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(int _n)
	{
		n = _n;
		memset(tree,0,(n+1)<<2);
	}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
}tree;

char s[MAXN], t[MAXN];
vector<int> pt[30];
int cur[30];

void solve(void)
{
	int n;
	scanf("%d%s%s",&n,s+1,t+1);
	
	for(int i=0; i<26; ++i) pt[i].clear(), cur[i] = 0;
	for(int i=1; i<=n; ++i) pt[s[i] - 'a'].push_back(i);
	
	tree.clear(n);
	for(int i=1; i<=n; ++i) tree.update(i,1);
	
	ll ans = linf, res = 0;
	for(int i=1; i<=n; ++i)
	{
		auto get = [&] (int c)
		{
			return tree.query(pt[c][cur[c]]) - 1;
		};
		
		int c = t[i] - 'a';
		for(int j=0; j<c; ++j)
			if(cur[j] < (int)pt[j].size())
				ans = min(ans, res + get(j));
		
		if(cur[c] == (int)pt[c].size()) break;
		res += get(c);
		tree.update(pt[c][cur[c]], -1);
		++cur[c];
	}
	
	if(ans == linf) printf("-1\n");
	else printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct BIT
{
	int tree[MAXN],n;
	#define lowbit(x) ((x)&-(x))
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
	inline int query(int l,int r){ return query(r) - query(l-1);}
}bit;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	bit.n = n;
	for(int i=1; i<=n; ++i) bit.update(i,1);
	
	static char t[MAXN];
	for(int i=1; i<=n; ++i) t[i] = s[n-i+1];
	
	static queue<int> pos[30];
	for(int i=1; i<=n; ++i)
		pos[s[i]-'a'].push(i);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int x = t[i] - 'a';
//		assert(pos[x].size());
		int p = pos[x].front(); pos[x].pop();
		
		bit.update(p, -1);
		ans += bit.query(p);
	}
	printf("%lld",ans);
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

struct BIT
{
	int tree[MAXN],n;// suffix sum
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		x = n-x+1;
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		x = n-x+1;
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(l) - query(r+1);}
};

int p[MAXN];
pair<pii,int> q[MAXM];

int ans[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	for(int i=1; i<=m; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		q[i] = make_pair(make_pair(r,l), i);
	}
	
	static int pos[MAXN];
	for(int i=1; i<=n; ++i) pos[p[i]] = i;
	
	static vector<pii> seg;
	for(int i=1; i<=n; ++i)
		for(int j=i; j<=n; j+=i)
		{
			int l = pos[i], r = pos[j];
			if(l>r) swap(l,r);
			seg.push_back(make_pair(r,l));
		}
	
	sort(q+1,q+m+1);
	sort(seg.begin(),seg.end());
	
	static BIT bit;
	bit.n = n;
	
	for(int i=1,j=0; i<=m; ++i)
	{
		int l = q[i].first.second, r = q[i].first.first, id = q[i].second;
		
		while(j<(int)seg.size() && seg[j].first <= r)
			bit.update(seg[j].second, 1), ++j;
		
		ans[id] = bit.query(l);
	}
	
	for(int i=1; i<=m; ++i)
		printf("%d\n",ans[i]);
	return 0;
}
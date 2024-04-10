#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct BIT
{
	int n,tree[MAXN];
	#define lowbit(x) ((x)&-(x))
	inline void init(int n_){ n=n_; memset(tree,0,sizeof(tree));}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x]+=k,
			x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res+=tree[x],
			x^=lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(r)-query(l-1);}
}tree;

pii a[MAXN];
int ans[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].first),
		a[i].second=i;
	
	sort(a+1,a+n+1);
	tree.init(n);
	for(int i=1; i<=n; ++i)
	{
		int id=a[i].second;
		for(int k=1; k<n; ++k)
		{
			ll l = k*(id-1)+2;
			if(l>n) break;
			int r = min(k*id+1, n);
			
			ans[k] += tree.query(l,r);
		}
		tree.update(id,1);
	}
	
	for(int i=1; i<n; ++i) printf("%d ",ans[i]);
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Segment_Tree
{
	int mn[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	void update(int u,int l,int r,int q,int k)
	{
		if(l==r){ mn[u]=k; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
		push_up(u);
	}
	int query(int u,int l,int r,int k)
	{
		if(l==r) return mn[u]<k? l: l+1;
		int mid = (l+r)>>1;
		if(mn[ls(u)] < k) return query(lson(u),k);
		return query(rson(u),k);
	}
}tree;

int a[MAXN];
vector<int> poss[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	bool eq = 1;
	for(int i=2; i<=n; ++i)
		if(a[i] != a[i-1]){ eq=0; break;}
	if(eq)
	{
		if(a[1] == 1) printf("1");
		else printf("2");
		return 0;
	}
	
	for(int i=1; i<=n; ++i)
		poss[a[i]].push_back(i);
	
	vector<pair<pii,int> > q;// r,l,id
	for(int i=1; i<=n; ++i)
	{
		int lst = 0;
		vector<int> &pos = poss[i];
		
		for(int j=0; j<(int)pos.size(); ++j)
		{
			if(pos[j] != lst+1)
				q.push_back(make_pair(make_pair(pos[j]-1, lst+1), i));
			lst = pos[j];
		}
		
		if(lst != n)
			q.push_back(make_pair(make_pair(n, lst+1), i));
	}
	q.push_back(make_pair(make_pair(n,1), n+1));
	
	sort(q.begin(),q.end());
	
	static int mx_mex[MAXN];
	
	for(int i=1,j=0; i<=n && j<(int)q.size(); ++i)
	{
		tree.update(1,1,n, a[i], i);
		while(j<(int)q.size() && q[j].first.first == i)
		{
			chk_max(mx_mex[q[j].second], tree.query(1,1,n, q[j].first.second));
			++j;
		}
	}
	
	static bool has[MAXN];
	for(int i=1; i<=n+1; ++i)
		has[mx_mex[i]] = 1;
	for(int i=1; i<=n+2; ++i)
		if(!has[i])
			return printf("%d",i), 0;
	return 0;
}
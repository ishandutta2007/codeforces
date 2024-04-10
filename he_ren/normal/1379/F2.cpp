#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct Segment_Tree
{
	set<int> has[MAXN][2];
	int mxL[MAXN<<2], mnR[MAXN<<2], isok[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	Segment_Tree(void)
	{
		memset(mxL, 0xc0, sizeof(mxL));
		memset(mnR, 0x3f, sizeof(mnR));
		memset(isok, 1, sizeof(isok));
	}
	inline void push_up(int u)
	{
		isok[u] = isok[ls(u)] && isok[rs(u)] && mxL[rs(u)] < mnR[ls(u)];
		if(!isok[u]) return;
		mxL[u] = max(mxL[ls(u)], mxL[rs(u)]);
		mnR[u] = min(mnR[ls(u)], mnR[rs(u)]);
	}
	inline void update(int u,int l,int r,int q,int k1,int k2)
	{
		if(l == r)
		{
			if(has[l][k2].count(k1)) has[l][k2].erase(k1);
			else has[l][k2].insert(k1);
			
			mxL[u] = has[l][0].size()? *has[l][0].rbegin(): -inf;
			mnR[u] = has[l][1].size()? *has[l][1].begin(): inf;
			isok[u] = mxL[u] < mnR[u];
			return;
		}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k1,k2);
		else update(rson(u),q,k1,k2);
		push_up(u);
	}
}tree;

int main(void)
{
	int n,m,Q;
	scanf("%d%d%d",&n,&m,&Q);
	
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		tree.update(1,1,n, (x+1)/2, (y+1)/2, x%2);
		if(tree.isok[1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
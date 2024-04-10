#include<cstdio>
#include<algorithm>
#include<vector>
const int MAXN = 100 + 5;
const int MAXR = 6e4 + 5;
using namespace std;

inline int max(int a,int b){ return a>b? a: b;}

struct Node
{
	int x,y;
};
vector<Node> pos,neg;
inline bool pos_cmp(Node x,Node y)
{
	return x.x<y.x;
}
inline bool neg_cmp(Node x,Node y)
{
	return x.x+x.y < y.x+y.y;
}

int f[MAXR];

int main(void)
{
	int n,r;
	scanf("%d%d",&n,&r);
	for(int i=1; i<=n; ++i)
	{
		Node a;
		scanf("%d%d",&a.x,&a.y);
		a.x = max(a.x, -a.y);
		if(a.y>=0) pos.push_back(a);
		else neg.push_back(a);
	}
	sort(pos.begin(), pos.end(), pos_cmp);
	sort(neg.begin(), neg.end(), neg_cmp);
	
	int ans=0;
	for(int i=0; i<(int)pos.size(); ++i)
		if(r>=pos[i].x)
		{
			r+=pos[i].y;
			++ans;
		}
	
	for(int i=0; i<(int)neg.size(); ++i)
		for(int j=r; j>=neg[i].x; --j)
			f[j] = max(f[j], f[j+neg[i].y]+1);
	
	printf("%d",ans+f[r]);
	return 0;
}
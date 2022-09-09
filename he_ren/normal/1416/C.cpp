#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int lb = 30;
const int LB = lb + 5;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)

struct Node
{
	int son[2], size;
	Node(void){ son[0]=son[1]=-1; size=0;}
};

ll tot[LB][2];

vector<Node> p(1);

inline int psize(int u){ return u==-1? 0: p[u].size;}
inline int lsize(int u){ return p[u].son[0] == -1? 0: p[p[u].son[0]].size;}
inline int rsize(int u){ return p[u].son[1] == -1? 0: p[p[u].son[1]].size;}
inline void push_up(int u){ p[u].size = lsize(u) + rsize(u);}

void insert(int x)
{
	int u = 0;
	for(int k=lb; k>=0; --k)
	{
		++p[u].size;
		int dig = bdig(x,k);
		
		tot[k][dig] += psize(p[u].son[!dig]);
		
		if(p[u].son[dig] == -1)
			p[u].son[dig] = (int)p.size(),
			p.push_back(Node());
		u = p[u].son[dig];
	}
	++p[u].size;
}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		insert(a[i]);
	
	int x = 0;
	ll ans = 0;
	for(int i=0; i<=lb; ++i)
	{
		if(tot[i][1] < tot[i][0])
			x |= bbit(i);
		
		ans += min(tot[i][0], tot[i][1]);
	}
	
	printf("%lld %d",ans,x);
	return 0;
}
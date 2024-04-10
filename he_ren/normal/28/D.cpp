#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
const int MAXN = 1e5 + 5;
const int MAXTOT = 3e5 + 5;
const int inf = 0x3f3f3f3f;

struct Node
{
	int val,c,l,r, id;
	inline void read(void){ scanf("%d%d%d%d",&val,&c,&l,&r);}
}p[MAXN];

int ans = 0;
vector<int> ansv;

vector<piii> f[MAXTOT];

void solve(vector<Node> &vec, int tot)
{
	if(!vec.size()) return;
	
	vector<int> use;
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int l=vec[i].l, c=vec[i].c, val=vec[i].val;
		if(f[l].back().first.first == -inf) continue;
		if(f[l].back().first.first + val <= f[l+c].back().first.first) continue;
		
		use.push_back(l+c);
		f[l+c].push_back(make_pair(make_pair(f[l].back().first.first + val, vec[i].id), f[l].size()));
	}
	
	if(f[tot].back().first.first > ans)
	{
		ans = f[tot].back().first.first;
		ansv.clear();
		
		int now = tot;
		while(now)
		{
			int u = f[now].back().first.second;
			ansv.push_back(u);
			f[now - p[u].c].resize(f[now].back().second);
			now -= p[u].c;
		}
	}
	
	for(int i=0; i<(int)use.size(); ++i)
		f[use[i]].resize(1);
}

vector<Node> nodes[MAXTOT];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		p[i].read(), p[i].id=i;
	
	for(int i=1; i<=n; ++i)
		nodes[p[i].l + p[i].c + p[i].r].push_back(p[i]);
	
	f[0].push_back(make_pair(make_pair(0,0), 0));
	for(int i=1; i<MAXTOT; ++i)
		f[i].push_back(make_pair(make_pair(-inf, 0), 0));
	
	for(int i=0; i<MAXTOT; ++i)
		solve(nodes[i], i);
	
	sort(ansv.begin(), ansv.end());
	printf("%d\n",(int)ansv.size());
	for(int i=0; i<(int)ansv.size(); ++i)
		printf("%d ",ansv[i]);
	return 0;
}
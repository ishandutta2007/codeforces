#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int n;
int a[MAXN], t[MAXN], tt[MAXN];

int fa[MAXN];
void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u]==u? u: fa[u]=find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

priority_queue<pii> q;
vector<int> tag[MAXN];

bool check(int mid)
{
	for(int i=1; i<=n; ++i) t[i] = tt[i];
	
	for(int i=1; i<=n; ++i) tag[i].clear();
	while(!q.empty()) q.pop();
	
	for(int i=1; i<=n; ++i)
		if(t[i]) q.push(make_pair(t[i], i));
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<(int)tag[i].size(); ++j)
			q.push(make_pair(t[tag[i][j]], tag[i][j]));
		
		if(q.empty()) return 0;
		int x = q.top().second; q.pop();
		
		--t[x];
		if(t[x])
		{
			if(i+mid+1 > n) return 0;
			tag[i+mid+1].push_back(x);
		}
	}
	return 1;
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) tt[i] = 0;
	for(int i=1; i<=n; ++i) ++tt[a[i]];
	sort(tt+1,tt+n+1);
	reverse(tt+1,tt+n+1);
	
	int l=0, r=n-2;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
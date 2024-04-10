#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int n,d;
ll a[MAXN];
int b[MAXN];

struct Node
{
	int id, time;
};
inline bool operator < (const Node &p,const Node &q){ return p.time > q.time;}

inline bool check(ll mid)
{
	static ll a[MAXN];
	static priority_queue<Node> q;
	
	while(!q.empty()) q.pop();
	for(int i=1; i<=n; ++i)
	{
		a[i] = ::a[i];
		ll time = a[i]/b[i];
		if(time >= d-1) continue;
		q.push((Node){i, (int)time});
	}
	
	for(int i=1; i<=d && !q.empty(); ++i)
	{
		Node uu = q.top(); q.pop();
		if(uu.time < i-1) return 0;
		int u = uu.id;
		
		a[u] += mid;
		ll time = a[u]/b[u];
		
		if(time < i) return 0;
		if(time >= d-1) continue;
		
		q.push((Node){u, (int)time});
	}
	return 1;
}

int main(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	ll l=0, r=2e12;
	if(!check(r)){ printf("-1"); return 0;}
	while(l<r)
	{
		ll mid = (l+r)>>1ll;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	
	printf("%lld",l);
	return 0;
}
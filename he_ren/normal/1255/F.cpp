#include<cstdio>
#include<algorithm>
#include<deque>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN = 1e3 + 5;
const ull ulinf = -1ull;

struct Node
{
	int id;
	ull x;
}p[MAXN],q[MAXN];
int pcnt=0, qcnt=0;
inline bool cmp(const Node &p,const Node &q){ return p.x>q.x;}
deque<Node> pp,qq;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=2; i<n; ++i)
	{
		printf("1 1 %d %d\n",i,n);
		fflush(stdout);
		ll x;
		scanf("%lld",&x);
		
		printf("2 1 %d %d\n",i,n);
		fflush(stdout);
		int y;
		scanf("%d",&y);
		
		if(y>0) p[++pcnt]=(Node){i,(ull)x};
		else q[++qcnt]=(Node){i,(ull)x};
	}
	
	if(pcnt)
	{
		sort(p+1,p+pcnt+1,cmp);
		pp.push_back(p[1]);
		for(int i=2; i<=pcnt; ++i)
		{
			printf("2 %d 1 %d\n",p[1].id,p[i].id);
			fflush(stdout);
			int tmp;
			scanf("%d",&tmp);
			
			if(tmp>0) pp.push_front(p[i]);
			else pp.push_back(p[i]);
		}
	}
	if(qcnt)
	{
		sort(q+1,q+qcnt+1,cmp);
		qq.push_back(q[1]);
		for(int i=2; i<=qcnt; ++i)
		{
			printf("2 %d 1 %d\n",q[1].id,q[i].id);
			fflush(stdout);
			int tmp;
			scanf("%d",&tmp);
			
			if(tmp>0) qq.push_front(q[i]);
			else qq.push_back(q[i]);
		}
	}
	
	deque<Node>::iterator it;
	printf("0 1 ");
	for(it=pp.begin(); it!=pp.end(); ++it) printf("%d ",(*it).id);
	printf("%d ",n);
	for(it=qq.begin(); it!=qq.end(); ++it) printf("%d ",(*it).id);
	return 0;
}
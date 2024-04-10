#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ldb;
const int MAXN = 2e5 + 5;

int n,m;

struct Node
{
	int a,t;
}p[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.t<q.t;}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i].a);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i].t);
	
	ldb s1=0,s2=0;
	for(int i=1; i<=n; ++i)
	{
		if(p[i].t<=m) s1 += (ldb)p[i].a * (m-p[i].t);
		else s2 += (ldb)p[i].a * (p[i].t-m);
	}
	
	s1 = s2 = min(s1,s2);
	ldb ans=0;
	sort(p+1,p+n+1,cmp);
	for(int i=n; i>=1; --i)
		if(p[i].t<=m)
		{
			ldb tmp = (ldb)p[i].a * (m-p[i].t);
			if(tmp <= s1)
			{
				ans += p[i].a;
				s1 -= tmp;
			}
			else
			{
				ans += s1 / (m-p[i].t);
				break;
			}
		}
	for(int i=1; i<=n; ++i)
		if(p[i].t>m)
		{
			ldb tmp = (ldb)p[i].a * (p[i].t-m);
			if(tmp <= s2)
			{
				ans += p[i].a;
				s2 -= tmp;
			}
			else
			{
				ans += s2 / (p[i].t-m);
				break;
			}
		}
	printf("%.20lf",(double)ans);
	return 0;
}
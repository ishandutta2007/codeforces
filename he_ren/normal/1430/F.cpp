#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Node
{
	int l,r,num;
}p[MAXN];

ll f[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].num);
	
	memset(f,0x3f,sizeof(f));
	
	f[0] = 0;
	for(int i=0; i<n; ++i) if(f[i] != linf)
	{
		int lst = p[i+1].l, rem = d;
		ll used = 0;
		
		for(int j=i+1; j<=n; ++j)
		{
			lst = max(lst, p[j].l);
			used += p[j].num;
			
			int num = p[j].num;
			if(num <= rem) rem -= num;
			else
			{
				num -= rem;
				int need = (num + d-1) / d;
				lst += need;
				rem = (ll)need * d - num;
			}
			
			if(lst > p[j].r) break;
			
			if(j == n) f[j] = min(f[j], f[i] + used);
			else if(lst + 1 <= p[j+1].l)
				f[j] = min(f[j], f[i] + used + rem);
		}
	}
	
	if(f[n] == linf) printf("-1");
	else printf("%lld",f[n]);
	return 0;
}
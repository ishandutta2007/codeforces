#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 25 + 5;

#define bit(i) (1ll<<(i))

ll a[MAXN][MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i+=2)
		for(int j=1; j<=n; ++j)
			a[i][j] = bit(i+j-2);
	
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=n; ++j)
			printf("%lld ",a[i][j]);
	fflush(stdout);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		ll d;
		scanf("%lld",&d);
		
		int cur=0;
		pii now(1,1);
		while(1)
		{
			printf("%d %d\n",now.first,now.second);
			if(now == make_pair(n,n)) break;
			++cur;
			if(d & bit(cur)){ ++now.second; continue;}
			
			++now.first;
			if(now.first==n)
			{
				while(now.second <= n)
				{
					printf("%d %d\n",now.first,now.second);
					++now.second;
				}
				break;
			}
			
			while(~d & bit(cur))
			{
				printf("%d %d\n",now.first,now.second);
				++cur;
				++now.second;
			}
			--now.second;
			++now.first;
		}
		fflush(stdout);
	}
	return 0;
}
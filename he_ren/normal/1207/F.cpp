#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int n = 5e5;
const int MAXN = n + 5;
const int sqn = 7e2;
const int MAXSQ = sqn + 5;

ll a[MAXN], sum[MAXSQ][MAXSQ];

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int oper,x,y;
		scanf("%d%d%d",&oper,&x,&y);
		if(oper==1)
		{
			a[x] += y;
			for(int i=1; i<=sqn; ++i)
				sum[i][x%i] += y;
		}
		else
		{
			if(x <= sqn) printf("%lld\n",sum[x][y]);
			else
			{
				ll res = 0;
				for(int i=y; i<=n; i+=x)
					res += a[i];
				printf("%lld\n",res);
			}
		}
	}
	return 0;
}
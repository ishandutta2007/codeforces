#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];
ll sum[MAXN], dif[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	int nn = (n+1)/2;
	for(int i=1; i<=nn; ++i) scanf("%d",&a[i]);
	int x;
	scanf("%d",&x);
	for(int i=nn+1; i<=n; ++i) a[i] = x;
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	if(x<=0)
	{
		int mn = n/2+1;
		
		for(int i=1; i<=nn; ++i)
		{
			ll tmp = sum[nn]-sum[i-1];
			if(tmp<=0){ ++dif[mn]; --dif[n-i+1 + 1]; continue;}
			
			if(!x) continue;
			
			ll need = (tmp-x-1)/(-x) + nn-i+1;
			if(need > n-i+1) continue;
			
			++dif[need];
			--dif[n-i+1 + 1];
		}
		
		for(int i=1; i<=n; ++i)
			dif[i] += dif[i-1];
		
		for(int i=mn; i<=n; ++i)
			if(!dif[i])
			{
				printf("%d",i);
				return 0;
			}
		printf("-1");
		return 0;
	}
	if(sum[n]>0) printf("%d",n);
	else printf("-1");
	return 0;
}
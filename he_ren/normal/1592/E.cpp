#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXA = 2e6 + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int a[MAXN], sum[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) sum[i] = sum[i-1] ^ a[i];
	
	static int bac[MAXA];
	memset(bac,-1,sizeof(bac));
	
	int ans = 0;
	for(int t=0; t<=20; ++t)
		for(int i=1,j=1; i<=n; i=j)
		{
			while(j<=n && bdig(a[j], t) == bdig(a[i], t)) ++j;
			if(!bdig(a[i], t)) continue;
			
			for(int beg=i-1; beg<=i; ++beg)
			{
				for(int k=beg; k<j; k+=2)
				{
					int cur = sum[k] >> t;
					if(bac[cur] != -1) ans = max(ans, k - bac[cur]);
					else bac[cur] = k;
				}
				for(int k=beg; k<j; k+=2)
					bac[sum[k]>>t] = -1;
			}
		}
	
	printf("%d",ans);
	return 0;
}
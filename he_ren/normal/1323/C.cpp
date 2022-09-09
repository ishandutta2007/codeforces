#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

char s[MAXN];
int sum[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<=n; ++i)
	{
		sum[i]=sum[i-1];
		if(s[i]=='(') ++sum[i];
		else --sum[i];
	}	
	if(sum[n]){ printf("-1"); return 0;}
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(sum[i]<0)
		{
			int j=i,now=0;
			do
			{
				if(s[j]=='(') ++now;
				else --now;
				++j;
			}while(now<0);
			ans += j-i;
			i=j-1;
		}
	printf("%d",ans);
	return 0;
}
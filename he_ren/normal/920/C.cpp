#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;

int a[MAXN];
char s[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	scanf("%s",s+1);
	
	for(int i=1,j; i<=n; i=j+1)
	{
		while(i<n && s[i]=='0') ++i;
		if(i==n) break;
		
		j=i;
		while(j<n && s[j]=='1') ++j;
		sort(a+i,a+j+1);
	}
	
	for(int i=1; i<=n; ++i)
		if(a[i]!=i)
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}
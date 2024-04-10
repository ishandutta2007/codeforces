#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

char s[MAXN];
int f[MAXN],g[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	for(int i=1; i<=n; ++i)
		f[i] = f[i-1] + (s[i]=='(');
	for(int i=n; i>=1; --i)
		g[i] = g[i+1] + (s[i]==')');
	
	for(int i=0; i<=n; ++i)
		if(!f[i] && !g[i+1])
		{
			printf("0");
			return 0;
		}
	for(int i=0; i<=n; ++i)
		if(f[i]==g[i+1])
		{
			printf("1\n%d\n",f[i]+g[i+1]);
			
			for(int j=1; j<=i; ++j)
				if(s[j]=='(') printf("%d ",j);
			for(int j=i+1; j<=n; ++j)
				if(s[j]==')') printf("%d ",j);
			
			return 0;
		}
	return 0;
}
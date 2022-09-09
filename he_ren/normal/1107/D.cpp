#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 5.2e3 + 5;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

char s[MAXN];
bool a[MAXN][MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s+1);
		for(int j=1; s[j]; ++j)
		{
			if(s[j]>='0'&&s[j]<='9') s[j]-='0';
			else s[j]=s[j]-'A'+10;
			for(int k=0; k<4; ++k)
				a[i][(j<<2)-k] = (s[j]>>k)&1;
		}
	}
	
	int x=0;
	for(int i=1; i<=n && x!=1; ++i)
		for(int l=1,r=1; l<=n && x!=1; l=r)
		{
			while(r<=n && a[i][r]==a[i][l]) ++r;
			x=gcd(x,r-l);
		}
	for(int j=1; j<=n && x!=1; ++j)
		for(int l=1,r=1; l<=n && x!=1; l=r)
		{
			while(r<=n && a[r][j]==a[l][j]) ++r;
			x=gcd(x,r-l);
		}
	printf("%d",x);
	return 0;
}
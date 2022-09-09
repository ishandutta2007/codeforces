#include<cstdio>
const int MAXN = 89 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int l=1,r=1; r<=n; l=r+1)
	{
		r=l;
		while(r<=n && s[r]=='1') ++r;
		printf("%d",r-l);
	}
	return 0;
}
#include<cstdio>
#include<cstring>
const int MAXN = 9 + 5;

char s[MAXN];

int main(void)
{
	int x;
	scanf("%d",&x);
	while(x%10 == 0) x/=10;
	
	sprintf(s+1,"%d",x);
	int n=strlen(s+1);
	for(int i=1; i<=(n>>1); ++i)
		if(s[i]!=s[n-i+1])
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}
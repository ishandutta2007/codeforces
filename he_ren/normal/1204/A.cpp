#include<cstdio>
#include<cstring>
const int MAXN = 100 + 5;

char s[MAXN];

int main(void)
{
	scanf("%s",s);
	int n = strlen(s);
	bool flag=0;
	if(!((n-1)&1))
		for(int i=1; i<n; ++i)
			if(s[i]=='1')
			{
				flag=1;
				break;
			}
	
	printf("%d",n/2+1-!flag);
	return 0;
}
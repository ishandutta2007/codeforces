#include<cstdio>
#include<cstring>
const int MAXN = 1e6 + 5;

char a[MAXN],b[MAXN];

int main(void)
{
	scanf("%s%s",a,b);
	int x,y;
	for(x=0; a[x]=='0'; ++x);
	for(y=0; b[y]=='0'; ++y);
	
	int n=strlen(a+x), m=strlen(b+y);
	if(n!=m)
	{
		if(n>m) printf(">");
		else printf("<");
		return 0;
	}
	
	for(int i=0; i<n; ++i)
	{
		if(a[x+i]!=b[y+i])
		{
			if(a[x+i]>b[y+i]) printf(">");
			else printf("<");
			return 0;
		}
	}
	printf("=");
	return 0;
}
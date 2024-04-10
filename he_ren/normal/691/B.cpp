#include<cstdio>
#include<cstring>
const int MAXN = 1e3 + 5;

char t[]={"-d-b----------oqp----vwx--A------HI---M-O----TUVWXY-"};
char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=((n+1)>>1); ++i)
	{
		int c;
		if(s[i]<='Z')
			c=s[i]-'A'+26;
		else
			c=s[i]-'a';
		if(s[n-i+1]!=t[c])
		{
			printf("NIE");
			return 0;
		}
	}
	printf("TAK");
	return 0;
}
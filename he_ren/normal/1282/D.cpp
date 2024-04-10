#include<cstdio>
#include<cstring>
const int MAXN = 3e2 + 5;

int ask(char s[])
{
	printf("%s\n",s+1);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

void askc(char c)
{
	printf("%c\n",c);
	fflush(stdout);
}

char s[MAXN];

int main(void)
{
	for(int i=1; i<=300; ++i) s[i]='a';
	int x=300-ask(s);
	for(int i=1; i<=300; ++i) s[i]='b';
	int y=300-ask(s);
	
	int n=x+y;
	memset(s,0,sizeof(s));
	for(int i=1; i<=n; ++i) s[i]='a';
	
	int lst = y, now;
	for(int i=1; i<n; ++i)
	{
		s[i]='b';
		now=ask(s);
		if(now>lst)
		{
			s[i]='a';
			--now;
		}
		lst=now;
		if(!lst){ ask(s); return 0;}
	}
	if(lst) s[n]='b';
	ask(s);
	return 0;
}
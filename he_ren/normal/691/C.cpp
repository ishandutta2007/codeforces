#include<cstdio>
#include<cstring>
const int MAXN = 1e6 + 5;

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	int pnt=-1;
	for(int i=1; i<=n; ++i)
		if(s[i]=='.')
		{
			pnt=i;
			break;
		}
	if(pnt==-1) pnt=++n, s[n]='.';
	
	for(int i=pnt+1; i<=n; ++i) s[i-1]=s[i];
	--n;
	
	int ans;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]>'0')
		{
			ans=pnt-i-1;
			break;
		}
	}
	
	int bgn=1;
	while(s[bgn]=='0') ++bgn;
	int end=n;
	while(s[end]=='0') --end;
	
	putchar(s[bgn]);
	if(end>bgn) putchar('.');
	for(int i=bgn+1; i<=end; ++i) putchar(s[i]);
	if(ans) printf("E%d",ans);
	return 0;
}
#include<cstdio>
#define MN 100
#define ML 250
char s[MN+5],ans[MN+5][ML+5];
int main()
{
	int n,i,j,p,l,r;
	scanf("%d%s",&n,s);
	for(i=l=r=0;i<n;++i,r=l>r?l:r)l+=s[i]=='['?2:-2;
	for(i=p=0;i<n;++i,++p)
	{
		ans[l][p]=ans[r][p]='+';
		for(j=l+1;j<r;++j)ans[j][p]='|';
		if(s[i]=='[')ans[l][p+1]=ans[r][p+1]='-';
		if(s[i]==']')ans[l][p-1]=ans[r][p-1]='-';
		if(s[i]=='['&&s[i+1]=='[')++l,--r;
		if(s[i]=='['&&s[i+1]==']')p+=3;
		if(s[i]==']'&&s[i+1]==']')--l,++r;
	}
	for(i=0;i<=r;++i,puts(""))for(j=0;j<p;++j)putchar(ans[i][j]?ans[i][j]:' ');
}
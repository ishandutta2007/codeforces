#include<cstdio>
#include<cstring>
char s[110];
int main()
{
	int now=0,cnt=0;
	scanf("%s",s);int a=strlen(s)-2;
	scanf("%s",s);int b=strlen(s)-2;
	scanf("%s",s);int c=strlen(s)-2;
	scanf("%s",s);int d=strlen(s)-2;
	int e;
	e=a;if ((e>=b*2&&e>=c*2&&e>=d*2)||(e<=b/2&&e<=c/2&&e<=d/2)) now=1,cnt++;
	e=b;if ((e>=a*2&&e>=c*2&&e>=d*2)||(e<=a/2&&e<=c/2&&e<=d/2)) now=2,cnt++;
	e=c;if ((e>=a*2&&e>=b*2&&e>=d*2)||(e<=a/2&&e<=b/2&&e<=d/2)) now=3,cnt++;
	e=d;if ((e>=a*2&&e>=b*2&&e>=c*2)||(e<=a/2&&e<=b/2&&e<=c/2)) now=4,cnt++;
	if (cnt==1) printf("%c",now+64);
	else printf("C");
	return 0;
}
#include<cstring>
#include<cstdio>
char s1[1100],s2[1100];
int main()
{
	scanf("%s",s1);int n=strlen(s1);
	scanf("%s",s2);int m=strlen(s2);
	int a=0,b=0;
	for (int i=0;i<n;i++) a+=s1[i]-'0';if (a&1) a++;
	for (int i=0;i<m;i++) b+=s2[i]-'0';if (b&1) b++;
	if (a>=b) printf("YES");else printf("NO");
	return 0;
}
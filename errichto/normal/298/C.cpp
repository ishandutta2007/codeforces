#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b;
char s[500005],r[500005];
int main()
{
	scanf("%s%s",s,r);
	for(int i=0;i<strlen(s);++i)if(s[i]=='1') a++;
	for(int i=0;i<strlen(r);++i)if(r[i]=='1') b++;
	if(a%2)a++;
	if(a>=b)printf("YES");
	else printf("NO");
	return 0;
}
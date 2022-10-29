#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[1005];
int n,i;
int main()
{
	  scanf("%d",&n);
	  for (;n--;)
	  {
	  	  scanf("%s",c);
	  	  if (strlen(c)<=10) printf("%s",c);
	  	  else printf("%c",c[0]),printf("%d",strlen(c)-2),printf("%c",c[strlen(c)-1]);
	  	  puts("");
	  }
}
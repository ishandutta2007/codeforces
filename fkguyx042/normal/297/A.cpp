#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A,B;
char c;
int main()
{  for (c=getchar();c!='\n';c=getchar()) A+=c-'0';
  if (A&1) A++;
  for (c=getchar();c!='\n';c=getchar()) B+=c-'0';
  if (A>=B) printf("YES\n"); else printf("NO\n");
}
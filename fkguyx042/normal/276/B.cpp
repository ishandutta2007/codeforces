#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int a[1001];
char c[1001];
int main()
{ scanf("%s",&c);
 int Len=strlen(c);
  for (i=0;i<Len;i++)
   a[c[i]-'a']++;
  for (i=0;i<26;i++)
   if (a[i]&1) k++;
  if (k==0||k%2==1) printf("First\n");
  else printf("Second\n");
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1001];
char c[1001];
int i,j,m,n,p,k,ans;
int main()
{scanf("%s",&c);
  for (i=0;i<strlen(c);i++)
    a[c[i]-'a']++; 
  for (i=0;i<26;i++)
   if (a[i]) ans++;
   if (ans&1) printf("IGNORE HIM!\n");
   else printf("CHAT WITH HER!\n");
}
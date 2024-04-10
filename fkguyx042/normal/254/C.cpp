#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
char c[100001],s[100001];
int x[28],X[28];
int main()
{ freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
  scanf("%s",&s);
  int Len=strlen(s);
  for (i=0;i<Len;i++) X[s[i]-'A']++;
  scanf("%s",&c);
  for (i=0;i<Len;i++) x[c[i]-'A']++;
  for (i=0;i<26;i++) ans+=abs(X[i]-x[i]);
  ans/=2;
  printf("%d\n",ans);
  for (i=0;i<Len;i++)
   if (X[s[i]-'A']-x[s[i]-'A']>0)
  {    for (j=0;j<26;j++)
       if (x[j]-X[j]>0) break;
       if (!x[s[i]-'A'])
      {  X[s[i]-'A']--;
         X[j]++;
         s[i]='A'+j;
      }
      else if (j<s[i]-'A')
      { X[s[i]-'A']--;
         X[j]++;
         s[i]='A'+j;
  }
  x[s[i]-'A']--;
  X[s[i]-'A']--;
  }
printf("%s",s);
}
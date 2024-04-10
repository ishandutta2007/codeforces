#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int len,i,j,m,n,p,k;
int f[2000001];
char c[1000001];
bool check(int x)
{  int i,j,Now=0;
     for (i=-len;i<=len;i++) f[len+i]=0;
     f[len]=1;
     for (i=0;i<len;i++)
{  if (c[i]=='L') Now--; else Now++;
   if (Now>=x) Now=x-1;
   f[Now+len]++;
}
  if (f[Now+len]>1) return false;
  return true;
}
int main()
{ scanf("%s",&c);
  len=strlen(c);
  if (c[len-1]=='R') 
  for (i=0;i<len;i++) c[i]=c[i]=='R'?'L':'R';
  if (check(len)) printf("1\n"); else {
  int l=0,r=len+2,mid=0;
  for (;(l+r)>>1!=mid;)
  { mid=(l+r)>>1;
    if (check(mid)) l=mid;
    else r=mid;
}
printf("%d\n",l); }
}
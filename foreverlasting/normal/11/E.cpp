#include <bits/stdc++.h>
#define res register int
#define ll long long
#define N 2005000
#define eps 1e-10
using namespace std;
char s[N];
string t;
double f[N][2];
int len;
int main()
{
  scanf("%s",s);
  len=strlen(s);
  for(res i=0; i<len; i++)
  {
    t+=s[i];
    if(s[i]!='X'&&i+1<len&&s[i]==s[i+1])
      t+='X';
  }
  if(s[0]!='X'&&s[0]==s[len-1])
  {
    if(s[0]=='L') t+='X';
    else t="X"+t;
  }
  len=t.size();
  register double l=0,r=1;
  while(r-l>eps)
  {
    register double mid=(l+r)/2.0;
    f[0][0]=0.0,f[0][1]=-mid;
    for(res i=0; i<len; i++)
    {
      f[i+1][0]=f[i][1]-mid;
      f[i+1][1]=f[i][0]-mid;
      if(t[i]!='X')
      {
        if(t[i]=='L')
          f[i+1][1]=max(f[i+1][1],f[i][0]+1-mid);
        else
          f[i+1][0]=max(f[i+1][0],f[i][1]+1-mid);
      }
      f[i+1][0]=max(f[i+1][0],f[i+1][1]-mid);
      f[i+1][1]=max(f[i+1][1],f[i+1][0]-mid);
    }
    if(f[len][0]>0)
      l=mid;
    else
      r=mid;
  }
  int x=(l+eps)*1e8;
  printf ("%d.%06d\n", x / 1000000, x % 1000000);
  return 0;
}
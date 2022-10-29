#include<cstdio>
#define INF 1e15
#define N 200005
#define GO {puts("Incorrect sequence");return 0;}
using namespace std;
char s[12];
int n,m,i,boo[N],p,k,cnt,t,j;long long a[N],stack[N];
long long turn(char *a)
{
  long long res=0;
  for (int i=(a[0]=='-');a[i]!='\0';i++)
    res=res*10+a[i]-'0';
  if (a[0]=='-') res*=-1;
  return res;
}
int main()
{
  scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) 
  {
    scanf("%s",s);
    if (s[0]=='?') boo[i]=1;
    else a[i]=turn(s);
  }
  for (i=n+1;i<=n+k;i++) boo[i]=0,a[i]=INF;
  for (p=1;p<=k;p++)
  {
    stack[0]=-INF;
    for (i=p;i<=n+k;i+=k)
      if (boo[i]) stack[++cnt]=i;
      else 
      {
        if (a[i]-stack[0]-1<cnt) GO
        if (!cnt) {stack[0]=a[i];continue;}
        //make (cnt+1)/2 tobe 0
        t=(cnt+1)/2;
        if (stack[0]+t>0) a[stack[t]]=stack[0]+t;
        if (cnt-t>=a[i]) a[stack[t]]=a[i]-(cnt-t)-1;
        for (j=t+1;j<=cnt;j++) a[stack[j]]=a[stack[j-1]]+1;
        for (j=t-1;j>0;j--) a[stack[j]]=a[stack[j+1]]-1;
        cnt=0;stack[0]=a[i];
      }
  }
  for (i=1;i<=n;i++)
    printf("%I64d ",a[i]);
}
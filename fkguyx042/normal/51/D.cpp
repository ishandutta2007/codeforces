#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 200005

using namespace std;
int i,j,m,n,p,k,a[N],sum,flag,b[N];
inline int read()
{
       int x,f; char c;
       while (c=getchar(),(c<'0'||c>'9')&&c!='-');
       if (c=='-') f=-1,c=getchar(); else f=1;
       x=c-'0';
       while (c=getchar(),(c>='0'&&c<='9')) x=(x<<1)+(x<<3)+c-'0';
       return x*f;
}
void li()
{
      if (flag) return;
      puts("0");
      flag=1;
}
void yi()
{
      if (flag) return;
      puts("1");
      flag=1;
}
void er()
{
       if (flag) return;
       puts("2");
       flag=1;
}
bool del(int x)
{
     int i,j,k;
     for (i=1;i<=n;++i) b[i]=a[i];
     for (i=x+1;i<=n;++i) b[i-1]=b[i];
     --n;
     for (i=2;i<n;++i) if (b[i]*b[i]!=b[i-1]*b[i+1]) break;
     ++n;
     if (i==n-1) return 1;
     return 0;
}
int main()
{
  while (scanf("%d",&n)!=EOF)
{
    sum=flag=0;
    for (i=1;i<=n;++i) 
    { 
          a[i]=read();
          if (!a[i]) ++sum;
    }
    if (n==1||sum==n) li();
    if (sum==n-1&&a[1]!=0) li();
    if (sum==0&&n==2) li();
    if (sum==n-1) yi();
    if (sum==n-2&&a[1]!=0) yi();
    if (sum==1)
    {
        for (i=1;i<=n;++i)
         if (!a[i]) break;
        if (del(i)) yi(); else er();
    }
    if (sum) er();
    for (i=2;i<n;++i) if (a[i]*a[i]!=a[i-1]*a[i+1]) break;
    if (i==n) li();
    for (j=i-1;j<=i+1;++j)
      if (del(j)) yi();
    er(); 
}
}
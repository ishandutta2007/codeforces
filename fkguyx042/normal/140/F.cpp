#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 200005
#define Mo 10000005
#define seed 13333

using namespace std;
int i,j,m,n,p,k,upx,downx,tot,R;
void jia(int &x,int y)
{
      x+=y;  if (x<0) x+=Mo; 
      else if (x>=Mo) x-=Mo;
}
struct Point
{
       int x,y;
}A[N],up[N],down[N],ans[N];
struct Hash
{
    int edx[N],edy[N],before[N],k1,fox[Mo];
    void insert(int x,int y)
    {
         int sum=0;
         jia(sum,1ll*x*seed%Mo);
         jia(sum,y%Mo);
         edx[++k1]=x;
         edy[k1]=y;
         before[k1]=fox[sum];
         fox[sum]=k1;
    }
    bool find(int x,int y)
    {
         int sum=0,i;
         jia(sum,1ll*x*seed%Mo);
         jia(sum,y%Mo);
         for (i=fox[sum];i;i=before[i])
         {
           ++R;
           if (edx[i]==x&&edy[i]==y) return 1;
          }
         return 0;
    }
    bool check(int x,int y)
    {
          int flag=0,i;
          for (i=1;i<=n;++i)
            if (!find(x-A[i].x,y-A[i].y)) 
          if (++flag>k) return 0;
          return 1;
    }
}Ans,sum;
inline bool cmp(Point a,Point b) 
{
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}
inline int read()
{
       int x,f; char c;
       while (c=getchar(),(c<'0'||c>'9')&&c!='-');
       if (c=='-') f=-1,c=getchar(); else f=1;
       x=c-'0';
       while (c=getchar(),(c>='0'&&c<='9')) x=(x<<1)+(x<<3)+c-'0';
       return x*f;
}
int main()
{
    scanf("%d%d",&n,&k);
    if (n==k)
    { 
               printf("-1\n");
               return 0;
    }
    for (i=1;i<=n;++i) A[i].x=read(),A[i].y=read();
    sort(A+1,A+n+1,cmp);
    for (i=1;i<=n&&i<=k+1;++i) up[++upx]=A[i];
    for (;i<=n&&A[i].x==up[upx].x;++i) up[++upx]=A[i];
    for (i=1;n-i>=0&&i<=k+1;++i) down[++downx]=A[n-i+1];
    for (;n-i>0&&A[i].x==down[downx].x;++i) down[++downx]=A[n-i+1];
    for (i=1;i<=n;++i) sum.insert(A[i].x,A[i].y);
    for (i=1;i<=upx;++i)
       for (j=1;j<=downx;++j)
       {
               int x=up[i].x+down[j].x,y=up[i].y+down[j].y;
               if (Ans.find(x,y)) continue;
               if (sum.check(x,y)) ans[++tot].x=x,ans[tot].y=y,Ans.insert(x,y);
       }
    sort(ans+1,ans+tot+1,cmp);
    printf("%d\n",tot);
    for (i=1;i<=tot;++i) printf("%.6lf %.6lf\n",ans[i].x/2.,ans[i].y/2.);
}
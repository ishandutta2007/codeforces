#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,p,k;
long long n,x,y,c,l,r,mid;
inline long long  Do(long long x,long long y,long long R)
{     if (R+1<=x&&R+1<=y) return 1ll*(R+2)*(R+1)/2ll;
       if (R+1<=x) return 1ll*(R+2-y+R+1)*y/2ll;
       if (R+1<=y) return 1ll*(R+2-x+R+1)*x/2ll;
       long long X=min(x,R+2-x);
       long long Last=R+2-y;
       if (Last>=x) return x*y;
       long long size=x-Last;
       return 1ll*Last*y+((y-1)+((y-1)-size+1))*size/2ll;
}
inline bool check(long long R)
{  long long sum=0;
     sum+=Do(x,y,R);
     sum+=Do(n-x+1,n-y+1,R);
     sum+=Do(n-x+1,y,R);
     sum+=Do(x,n-y+1,R);
     sum-=min(R+1,x);
     sum-=min(R+1,y);
     sum-=min(R+1,n-x+1);
     sum-=min(R+1,n-y+1);
     sum++;
     return sum>=c;
}
int main()
{ //freopen("car.in","r",stdin);
 // freopen("car.out","w",stdout);
  scanf("%I64d%I64d%I64d%I64d",&n,&x,&y,&c);
  if (c==1) { printf("0\n"); return 0;}
    else { l=1,r=(long long)1e9+1;
         for (;(l+r)/2ll!=mid;)
         {    mid=(l+r)/2ll;
           if (mid==13)
             mid=13;
              if (check(mid)) r=mid;
              else l=mid;
         }
      printf("%I64d\n",r);
      }
}
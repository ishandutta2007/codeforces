#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a,b,c,d,e,f,t;
const long long INF=((long long)1e15)*2;
bool Do(long long x)
{  long long Last=x;
        if (d>0&&c==0) return true;   
        if (a==0&&b>0&&d!=0) return true;
        if (!d) return false;
      if ((!a)&&b) x=INF;
      else if (!b) x=0;
      else x=x/a*b;
      if ((!c)&&d) x=INF;
      else if (!d) x=0;
      else {x=x/c*d;
             if (x>INF) x=INF;
           }
      if (!x) return false;
      if ((!e)&&f) x=INF;
      else if (!e) x=0;
      else x=x/e*f;
      return x>Last;
}
int main()
{ // freopen("exchange.in","r",stdin);
  // freopen("exchange.out","w",stdout);
     scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
     if (!a||!c||!e) { if (Do(100000000))printf("Ron\n"); else printf("Hermione\n");}
     else 
     if (Do(1ll*a*c*e)) printf("Ron\n"); else printf("Hermione\n");
}
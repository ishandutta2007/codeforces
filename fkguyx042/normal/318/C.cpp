#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long x,y,i,j,m,n,p,k,t;
int main()
 { scanf("%I64d%I64d%I64d",&x,&y,&m);
   if (x<y) { t=x;x=y;y=t;}
   if (m<=0)
    { if (x<m&&y<m) {printf("-1\n"); return 0;}
      while (x<m&&y<m)
        { if (x<y) x+=y; else y+=x;n++;}
        printf("%I64d\n",n);
        }
   else { if (x<=0&&y<=0) {printf("-1\n"); return 0;}
   if (x>=m) { printf("0\n"); return 0;}
     if (x>0&&y<0) if ((-y)%x==0) {n+=(-y)/x; y=0;} else { n+=(-y)/x+1;
            y=y+((-y)/x+1)*x; }      
      while (x<m&&y<m)
        { if (x<y) x+=y; else y+=x;n++;}
        printf("%I64d\n",n);
        }
  return 0;
}
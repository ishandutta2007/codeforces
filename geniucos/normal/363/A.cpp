#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int i,aux,n;
char sir[100009];
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int det(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return mod(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
if(n==0)
{
    printf("O-|-OOOO\n");
    return 0;
}
aux=n;
while(aux)
{
    n=aux%10;
    aux/=10;
    if(n>=5) {printf("-O|");n-=5;}
    else printf("O-|");
    for(i=1;i<=n;i++)
        printf("O");
    printf("-");
    for(i=n+1;i<=4;i++)
        printf("O");
    printf("\n");
}
return 0;
}
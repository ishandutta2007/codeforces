#include<cstdio>
#include<cstring>
using namespace std;
int x1,y1,x2,y2,j,s,t,n,i,ap[5],a[5];
char sir[100009];
int code(char x)
{
    if(x=='N') return 1;
    if(x=='S') return 2;
    if(x=='E') return 3;
    if(x=='W') return 4;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d ",&n);
scanf("%d ",&x1);
scanf("%d ",&y1);
scanf("%d ",&x2);
scanf("%d\n",&y2);
if(x1==x2&&y1==y2)
{
    printf("0\n");
    return 0;
}
gets(sir+1);
if(y1<y2) a[code('N')]=y2-y1;
else a[code('S')]=y1-y2;


if(x1<x2) a[code('E')]=x2-x1;
else a[code('W')]=x1-x2;
for(i=1;i<=n;i++)
{
    ap[code(sir[i])]++;
    for(j=1;j<=4;j++)
        if(ap[j]<a[j]) break;
    if(j>4) break;
}
if(i<=n) printf("%d\n",i);
else printf("-1\n");
return 0;
}
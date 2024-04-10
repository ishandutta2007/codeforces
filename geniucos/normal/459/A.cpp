#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int X,Y,x[3],y[3];
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&x[1]);
scanf("%d",&y[1]);
scanf("%d",&x[2]);
scanf("%d",&y[2]);
if(y[1]==y[2])
{
    Y=y[1]+x[2]-x[1];
    printf("%d %d %d %d\n",x[1],Y,x[2],Y);
    return 0;
}
if(x[1]==x[2])
{
    X=x[1]+y[2]-y[1];
    printf("%d %d %d %d\n",X,y[1],X,y[2]);
    return 0;
}
if(mod(x[1]-x[2])!=mod(y[1]-y[2]))
{
    printf("-1\n");
    return 0;
}
printf("%d %d %d %d\n",x[1],y[2],x[2],y[1]);
return 0;
}
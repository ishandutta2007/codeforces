#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int a,b,c,d,i;
double p,X,p1,s;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
scanf("%d",&d);
p1=(double)a/b;
X=(double)(b-a)/b*(d-c)/d;
p=1;
for(i=1;i<=10000;i++)
{
    s+=p;
    p*=X;
}
printf("%.10lf\n",(double)s*p1);
return 0;
}
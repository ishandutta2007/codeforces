#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int x,y,a,b,c,d;
int work(double x,double y,double z)
{
       if (y>z) swap(y,z);
       return (int)floor(z/x)+1-(int)ceil(y/x);
}
int main()
{
     scanf("%d%d%d%d%d%d",&x,&y,&a,&b,&c,&d);
     x*=2; y*=2;
     printf("%d\n",max(work(x,a+b,c+d),work(y,a-b,c-d)));

}
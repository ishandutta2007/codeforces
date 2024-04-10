#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
struct dot{
    int x,y;
};
bool operator<(const dot &x,const dot &y){
    if(x.x!=y.x)
    return x.x<y.x;
    else
        return x.y<y.y;
}
int main(){
   int n,x,y;
   scanf("%d %d %d",&n,&x,&y);
   dot a[1010];
   map<dot,int> m;
   for(int i=0;i<n;i++)
    scanf("%d %d",&a[i].x,&a[i].y);
   for(int i=0;i<n;i++)
   {
       dot an;
       an.x=a[i].x-x;
       an.y=a[i].y-y;
       int gcd=__gcd(an.x,an.y);
       an.x/=gcd;
       an.y/=gcd;
       m[an]=1;
   }
   printf("%d",m.size());
    return 0;
}
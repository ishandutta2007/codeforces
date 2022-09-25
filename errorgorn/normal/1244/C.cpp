#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
long long n,p,d,w;
int main(){
    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
    long long x;
    for (long long y=0;y<w;y++){
        if ((p-d*y)%w==0){
            x=(p-d*y)/w;
            if (x+y<=n && x>=0){
                printf("%lld %lld %lld\n",x,y,n-x-y);
                return 0;
            }
        }
    }
    printf("-1\n");
}
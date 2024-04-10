#include <cstdio>
#include <algorithm>
using namespace std;
long long a,b,c,d,e,f;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if (b<a) swap(a,b);
        e=c+d; 
        f=c-d;
        //printf("%lld\n",b-a-d*2);
        //printf("%lld %lld\n",max(0LL,e-b),max(0LL,a-f));
        if (e<=a || b<=f) printf("%lld\n",b-a);
        else printf("%lld\n",b-a-d*2+max(0LL,e-b)+max(0LL,a-f));
    }
}
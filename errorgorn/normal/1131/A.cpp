#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    long long a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    printf("%lld\n",(a+b+c+d-min(a,c))*2+4);
}
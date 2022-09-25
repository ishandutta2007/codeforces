#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m;
long long k;
long long _n,_m;
int q;
long long gcd(long long i,long long j){
    if (i>j) swap(i,j);
    while (i!=0){
        j%=i;
        swap(i,j);
    }
    return j;
}
int main(){
    scanf("%lld%lld%d",&n,&m,&q);
    k=gcd(n,m);
    _n=n/k;
    _m=m/k;
    long long a,b,c,d;
    while (q--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        b--,d--;
        if (a==1) b/=_n;
        else b/=_m;
        if (c==1) d/=_n;
        else d/=_m;
        printf((b==d)?"YES\n":"NO\n");
    }
}
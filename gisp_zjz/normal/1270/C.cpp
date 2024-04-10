#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const ll E=1ll<<50;
int n;
ll a,b,c,x,y,z;

int main(){
    int _; scanf("%d",&_);
    while (_--){
        scanf("%d",&n); x=0; y=0;
        for (int i=1;i<=n;i++){
            ll r; scanf("%lld",&r);
            x+=r; y^=r;
        }
        if ((x-y)&1) z=E-2; else z=E-4;
        x=z-x; y=(z/2)^y;
        assert((x&1)==(y&1));
        a=y; b=c=(x-y)/2;
        printf("3\n%lld %lld %lld\n",a,b,c);
    }
    return 0;
}
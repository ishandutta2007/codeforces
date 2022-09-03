#include<bits/stdc++.h>
#define LL long long
using namespace std;
void solve(){
    LL n;
    scanf("%lld",&n);
    for(LL i=n;;i++){
        LL tmp=i;
        LL sum=0;
        while(tmp){
            sum+=tmp%10;
            tmp/=10;
        }
        if(__gcd(i,sum)!=1){
            printf("%lld\n",i);
            return ;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
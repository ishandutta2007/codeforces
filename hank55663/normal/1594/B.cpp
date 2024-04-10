#include<bits/stdc++.h>
using namespace std;
int main(){
    int mod=1e9+7;
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        long long ans=0;
        //b--;
        for(int i = 29;i>=0;i--){
            ans=ans*a%mod;
            if(b&(1<<i))ans++;
        }
        printf("%lld\n",ans%mod);
    }
}
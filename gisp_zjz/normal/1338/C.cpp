#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+6;
typedef long long ll;
int _;
int f[4][3]={
    {0,0,0},
    {1,2,3},
    {2,3,1},
    {3,1,2}
};
ll n,m;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%lld",&n); n+=2;
        ll ans=0,m=n/3,s=1,r=1;
        while (m>s) m-=s,s*=4,r*=4;
        r+=m-1;
        for (int i=0;i<60;i+=2){
            int x=(r>>i)&3;
            ans|=(1ll<<i)*f[x][n%3];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
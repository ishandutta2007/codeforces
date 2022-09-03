#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
int mod=1e9+7;
void solve(){
    LL x,y,k;
    scanf("%lld %lld %lld",&x,&y,&k);
    LL ans=k;
    ans+=(y*k+k-1+x-2)/(x-1);
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int M=1000000007;
const int maxn=5e5+5;
int _,n,dp[32],cnt[32],m,ans;
void add(int &x,int y){
    x=(x+y)%m;
}

int main(){
    cin >> _;
    while (_--){
        cin >> n >> m; ++n;
        for (int i=1;i<=30;i++) cnt[i]=max(0,min(n,(1<<i))-(1<<(i-1)));
        memset(dp,0,sizeof(dp)); ans=0;
        for (int i=1;i<=30;i++){
            dp[i]=1;
            for (int j=1;j<i;j++) add(dp[i],dp[j]);
            dp[i]=1ll*dp[i]*cnt[i]%m;
            add(ans,dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
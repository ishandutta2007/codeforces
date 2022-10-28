#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll mn = 1, mx = n*m;
    ll ans = -1;
    // 3 6 9 12 15
    // 1 3 4 4 5
    while(mn<=mx){
        ll mid = mn + mx;
        mid/=2;
        ll mnidx=1, mxidx=0;
        for(int i=1;i<=n;i++){
            mnidx+=min((mid-1)/i, m);
            mxidx+=min(mid/i, m);
        }
        if(k < mnidx){
            mx = mid - 1;
        }
        else if(k > mxidx){
            mn = mid + 1;
        }
        else{
            ans = mid;
            break;
        }
    }
    assert(ans!=-1);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
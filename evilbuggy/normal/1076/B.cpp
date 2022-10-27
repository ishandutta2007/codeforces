#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    ll ans = 0;
    if(n%2 == 1){
        ans++;
        int fac = -1;
        for(int i = 2; i <= 100000; i++){
            if(n%i == 0){
                fac = i;
                break;
            }
        }
        if(fac == -1){
            cout<<1<<endl;
            return 0;
        }
        n -= fac;
    }
    ans += (n/2);
    cout<<ans<<endl;
}
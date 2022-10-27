#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30)<<endl;

    int t, a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(b == 0){
            cout<<1.0<<endl;
        }else if(a == 0){
            cout<<0.5<<endl;
        }else{
            ld ans;
            if(4*b < a){
                ans = 1.0 - ld(b)/ld(a);
            }else{
                ans = 0.5 + ld(a)/ld(16*b);
            }
            cout<<ans<<endl;
        }
    }
}
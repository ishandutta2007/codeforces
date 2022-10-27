#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull l, r;
    cin>>l>>r;
    ull ans = 0;
    for(int i = 63; i >= 0; i--){
        bool lc = (l>>i)&1;
        bool rc = (r>>i)&1;
        ull nl = l^(1ULL<<i);
        ull nr = r^(1ULL<<i);
        if(!lc && !rc){
            if(nl <= r){
                ans |= (1ULL<<i);
                l = nl;
            }
        }else if(lc && !rc){
            ans |= (1ULL<<i);
        }else if(!lc && rc){
            ans |= (1ULL<<i);
        }else{
            if(nr >= l){
                ans |= (1ULL<<i);
                r = nr;
            }
        }
    }
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int q;
    cin>>q;
    while(q--){
        ll d, l, r;
        cin>>l>>r>>d;
        if(d < l){
            cout<<d<<endl;
        }else{
            ll ans = r/d;
            ans++;
            cout<<ans*d<<endl;
        }
    }
}
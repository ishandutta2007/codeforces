#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int q; cin>>q; for(int l=1; l<=q; l++) {
        ll x, y; cin>>x>>y; if(abs(x-y)==1) cout<<"NO\n"; else cout<<"YES\n";
    }
}
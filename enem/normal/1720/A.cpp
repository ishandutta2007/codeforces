#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i, a, n) for(ll i=a; i<n; i++)

int main() {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    ll tc;
    cin>>tc;
    while(tc--) {
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        if(a*d == b*c) cout<<0;
        else if(a == 0 || c == 0) cout<<1;
        else if((b*c) % (a*d) == 0 || (a*d) % (b*c) == 0) cout<<1;
        else cout<<2;

        cout<<'\n';
    }
    return 0;
}
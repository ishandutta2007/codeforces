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
        ll n;
        cin>>n;
        ll mx1 = 1, mx2 = 1, mn1 = 1000000000, mn2 = 1000000000;
        REP(i,0,n) {
            ll t;
            cin>>t;
            if(mx1 < t) {mx2=mx1; mx1 = t;}
            else if(mx2 < t) mx2=t;
            if(mn1 > t) {mn2=mn1; mn1 = t;}
            else if(mn2 > t) mn2=t;
        }
        cout<<mx1+mx2-mn1-mn2;

        cout<<'\n';
    }
    return 0;
}
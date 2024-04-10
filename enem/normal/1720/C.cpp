#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, a, n) for(ll i=a; i<n; i++)

int main() {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    ll tc;
    cin>>tc;
    while(tc--) {
        ll n, m;
        cin>>n>>m;
        string s[n];
        rep(i,0,n) cin>>s[i];

        bool zro = false;
        bool dub = false;
        rep(i,0,n) rep(j,0,m) if (s[i][j] == '0') zro = true;
        rep(i,0,n) rep(j,0,m-1) if(s[i][j]=='0'&&s[i][j+1]=='0') dub=true;
        rep(i,0,n-1) rep(j,0,m) if(s[i][j]=='0'&&s[i+1][j]=='0') dub=true;
        rep(i,0,n-1) rep(j,0,m-1) if(s[i][j]=='0'&&s[i+1][j+1]=='0') dub=true;
        rep(i,0,n-1) rep(j,1,m) if(s[i][j]=='0'&&s[i+1][j-1]=='0') dub=true;

        ll cnt = 0;
        rep(i,0,n) rep(j,0,m) if(s[i][j]=='1') cnt++;

        if(dub) cout<<cnt;
        else if(zro) cout<<cnt-1;
        else cout<<cnt-2;

        cout<<'\n';
    }
    return 0;
}
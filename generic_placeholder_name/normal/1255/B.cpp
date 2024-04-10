#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int32_t main() {
    int q; cin>>q; while(q--) {
        int n, m, tmp; cin>>n>>m; pii a[n];
        for(int i=0; i<n; i++) {cin>>tmp; a[i]=mp(tmp, i);}
        if(m<n||n==2) cout<<-1<<endl;
        else {
            ll sum=0;
            vector<pii> c;
            for(int i=0; i<n; i++) {c.pb(mp(i+1, (i+1)%n+1)); sum+=a[i].fi+a[(i+1)%n].fi;}
            sort(a, a+n);
            for(int i=0; i<m-n; i++) {c.pb(mp(a[0].se+1, a[1].se+1)); sum+=a[0].fi+a[1].fi;}
            cout<<sum<<endl;
            for(int i=0; i<c.size(); i++) cout<<c[i].fi<<" "<<c[i].se<<endl;
        }
    }
}
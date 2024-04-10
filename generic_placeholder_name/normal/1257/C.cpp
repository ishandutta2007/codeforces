#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second

bool comp(pii a, pii b) {return a.fi<b.fi||(a.fi==b.fi&&a.se<b.se);}

int solve(pii a[], int n) {
    sort(a, a+n, comp);
    int ans=INT_MAX;
    for(int i=1; i<n; i++) if(a[i].fi==a[i-1].fi) ans=min(ans, a[i].se-a[i-1].se+1);
    return ans==INT_MAX?-1:ans;
}

int32_t main() {
    int q; cin>>q; while(q--) {
        int n, tmp; cin>>n; pii a[n]; for(int i=0; i<n; i++) {cin>>tmp; a[i]=(make_pair(tmp, i));}
        cout<<solve(a, n)<<endl;
    }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second

bool comp(pii a, pii b) {return a.fi<b.fi;}

int32_t main() {
    int q; cin>>q; while(q--) {
        int n; cin>>n; pii a[n]; int b[n]; for(int i=0; i<n; i++) {cin>>b[i]; a[i]=make_pair(b[i], i);}
        sort(a, a+n, comp);
        int prev=0;
        for(int curr=0; curr<n; curr++) {
            //cout<<a[curr].fi<<" "<<a[curr].se<<" "<<prev<<" "<<endl;
            if(a[curr].se>=prev) {
                cout<<a[curr].fi<<" "; for(int i=prev; i<a[curr].se-1; i++) cout<<b[i]<<" ";
                if(a[curr].se>prev) {swap(b[a[curr].se-1], b[a[curr].se]); a[b[a[curr].se]-1].se=a[curr].se;}
                prev=a[curr].se>prev?a[curr].se:prev+1;
            }
        }
        for(int i=prev; i<n; i++) cout<<b[i]<<" ";
        cout<<endl;
    }
}
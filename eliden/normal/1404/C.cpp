#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];

    int mm = 1;
    while(mm<n) mm*=2;
    struct T {
        int vr=0;
        int d=0;
    };
    vector<T> st(2*mm);
    auto get_val = [&](int i) {
        i += mm;
        int ans = 0;
        while(i>0) {
            ans += st[i].d;
            i/=2;
        }
        return ans;
    };
    function<void(int,int,int,int,int)> update = [&](int i, int nodel, int noder,
                                                 int x, int j) {
        if(i>=mm) {
            assert(nodel<=j);
            if(st[i].vr<x) return;
            ++st[i].vr;
            ++st[i].d;
            return;
        }
        x-=st[i].d;
        int mid = (nodel+noder)/2;
        if(j>=mid && st[2*i].vr>=x) {
            ++st[2*i].d;
            ++st[2*i].vr;
            update(2*i+1,mid,noder,x,j);
        }
        else update(2*i,nodel,mid,x,j);
        st[i].vr = st[i].d + st[2*i+1].vr;
    };
    vector<vector<pair<int,int>>> qs(n);
    rep(i,0,q) {
        int x, y;
        cin>>x>>y;
        qs[n-1-y].emplace_back(x,i);
    }
    vector<int> ans(q);
    rep(i,0,n) {
        // debug(i+1-a[i]);
        if(a[i]<=i+1) update(1,0,mm,i+1-a[i],i);
        // rep(j,0,i+1) cerr<<get_val(j)<<" ";
        // cerr<<endl;
        for(const auto &qe:qs[i]) {
            ans[qe.second]  = get_val(qe.first);
        }
    }
    rep(i,0,q) cout<<ans[i]<<"\n";
}
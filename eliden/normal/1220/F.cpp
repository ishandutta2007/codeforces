#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
using ll = long long;
using vi = vector<int>;
vi depth(vi &a) {
    int n = sz(a);
    vi d{1};
    vi b{a[0]};
    vi y{1};
    assert(a[0]==0);
    vi ans(n);
    ans[0] = 1;
    rep(i,1,n) {
        int x = 0;
        while(a[i]<b.back()) {
            x = max(1+x,d.back());
            d.pop_back();
            b.pop_back();
            y.pop_back();
        }
        b.push_back(a[i]);
        d.push_back(x+1);
        y.push_back(max(y.back(), x+1+sz(y)));
        ans[i] = y.back();
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    int j=-1;
    rep(i,0,n) {
        cin >> a[i];
        --a[i];
        if(a[i]==0) j = i;
    }
    vi r1(n), r2(n);
    rep(i,0,n) {
        r1[i] = a[(j+i)%n];
        r2[i] = a[(j+n-i)%n];
    }
    vi ans1 = depth(r1), ans2 = depth(r2);
    int ans = n+1, off=-1;
    rep(i,0,n) {
        int cand = max(ans1[i],ans2[n-1-i]);
        if(cand<ans) {
            ans = cand;
            off = (j+i+1)%n;
        }
    }
    cout<<ans<<" "<<off<<endl;
}
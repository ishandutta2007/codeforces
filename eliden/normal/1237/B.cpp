#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<"@"<<__LINE__<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> inv(n), timeout(n);
    rep(i,0,n) {
        int a;
        cin >> a;
        --a;
        inv[a] = i;
    }
    rep(i,0,n) {
        int b;
        cin >> b;
        --b;
        timeout[inv[b]] = i;
    }
    int ans=0;
    int latest=-1;
    rep(i,0,n) {
        if(timeout[i]>latest) latest = timeout[i];
        else ++ans;
    }
    cout<<ans<<endl;
}
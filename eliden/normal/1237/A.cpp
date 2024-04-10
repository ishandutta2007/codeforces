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
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    vector<int> floors(n);
    vector<bool> odd(n);
    rep(i,0,n) {
        if(a[i]%2==0) floors[i]=a[i]/2;
        else {
            odd[i]=true;
            floors[i]=(a[i]-1)/2;
        }
    }
    int k = 0;
    rep(i,0,n) if(a[i]%2!=0) ++k;
    assert(k%2==0);
    int j = k/2;
    auto b = floors;
    rep(i,0,n) {
        if(odd[i]) {
            ++b[i];
            --j;
        }
        if(j==0) break;
    }
    rep(i,0,n) cout<<b[i]<<"\n";
}
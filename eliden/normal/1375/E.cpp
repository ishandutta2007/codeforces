#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n) {
        // a[i] = rand()%n;
        cin>>a[i];
        --a[i];
    }
    auto b = a;
    vector<int> ans1;
    vector<int> ans2;
    rep(i,0,n) {
        vector<int> js;
        rep(j,i+1,n) if(b[j]<b[i]) js.push_back(j);
        sort(all(js), [&](int j1, int j2) { return b[j1]>b[j2] || (b[j1]==b[j2] && j1>j2); });
        for(int j:js) {
            ans1.push_back(i);
            ans2.push_back(j);
            swap(a[i],a[j]);
        }
    }
    // rep(i,0,n) cerr<<b[i]+1<<" ";
    // cerr<<endl;
    // rep(i,0,n) cerr<<a[i]+1<<" ";
    // cerr<<endl;
    // rep(i,0,n-1) assert(a[i]<=a[i+1]);
    cout<<sz(ans1)<<"\n";;
    rep(i,0,sz(ans1)) {
        cout<<ans1[i]+1<<" "<<ans2[i]+1<<"\n";
    }
}
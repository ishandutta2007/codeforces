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
    cin >> n;
    vector<int> a(n+1);
    rep(i,0,n) cin >> a[i+1];
    vector<int> diff(n);
    rep(i,0,n) diff[i]=a[i+1]-a[i];
    vector<int> ks;
    rep(k,1,n+1) {
        bool works=true;
        vector<int> x(k);
        rep(i,0,k) x[i] = diff[i];
        rep(j,k,n) {
            if(diff[j]!=x[j%k]) {
                works=false;
                break;
            }
        }
        if(works) ks.push_back(k);
    }
    cout<<ks.size()<<endl;
    for(int k:ks) cout << k << " ";
    cout<<endl;
    
}
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
    int m = 101;
    vector<bool> can(m,true);
    rep(i,0,n) {
        int k;
        cin >> k;
        vector<bool> mask(m,false);
        rep(j,0,k) {
            int r;
            cin >> r;
            mask[r] = true;
        }
        rep(j,0,m) can[j]=can[j]&&mask[j];
    }
    vector<int> ans;
    rep(i,0,m) if(can[i]) ans.push_back(i);
    for(int x:ans) cout << x << " ";
    cout << "\n";
}
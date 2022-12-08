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
    int n, k;
    cin>>n>>k;
    vector<int> ind(k+1), val(k+1);
    rep(i,0,k+1) {
        cout<<"?";
        rep(j,0,k+1) if(j!=i) {
            cout<<" "<<j+1;
        }
        cout<<endl;
        cin>>ind[i]>>val[i];
    }
    int loi = 0;
    rep(i,1,k+1) if(val[i]<val[loi]) loi = i;
    int ans = 0;
    rep(i,0,k+1) if(val[i]!=val[loi]) ++ans;
    cout<<"! "<<ans<<endl;
}
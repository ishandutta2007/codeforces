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
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n;
        cin>>n;
        vector<ll> a(n);
        rep(i,0,n) cin>>a[i];
        vector<int> b;
        int last = -1;
        rep(i,0,n) {
            if(i==n-1 || a[i]!=a[i+1]) {
                b.push_back(i-last);
                last = i;
            }
        }
        int m = b.size();
        bool good = true;
        if(m<4) good = false;
        int g,s,br;
        if(good) {
            g = b[0];
            s = b[1];
            int j = 2;
            for(; j<m && s<=g; ++j) s += b[j];
            if(s<=g) good=false;
            else {
                br = 0;
                for(; j<m && br<=g; ++j) br += b[j];
                for(; j<m && (g+s+br+b[j])*2<=n; ++j) br += b[j];
                if(br<=g || (g+s+br)*2>n) good = false;
            }
        }
        if(!good) {
            g = 0;
            s = 0;
            br = 0;
        }
        cout<<g<<" "<<s<<" "<<br<<"\n";
    }
}
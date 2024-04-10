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
    vi a(2*n);
    rep(i,0,2*n) cin >> a[i];
    int tot=0;
    
    for(int i=0; i<2*n; i+=2) {
        int j=i+1;
        while(a[j]!=a[i]) ++j;
        while(j-1>i) {
            swap(a[j-1],a[j]);
            ++tot;
            --j;
        }
    }
    cout << tot << "\n";
}
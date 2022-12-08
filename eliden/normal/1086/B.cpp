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
    int n, s;
    cin >> n >> s;
    vector<int> deg(n);
    rep(i,0,n-1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ++deg[a];
        ++deg[b];
    }
    int leaves = 0;
    rep(i,0,n) if(deg[i]==1) ++leaves;

    int edges = leaves;
    double ans = s;
    ans *= 2;
    ans/=edges;
    if(n==2) ans = s;
    cout<<setprecision(15);
    cout<<ans<<"\n";
}
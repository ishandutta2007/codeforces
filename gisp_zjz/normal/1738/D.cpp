#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0,n,l,r;
int d[maxn];
vi G[maxn];
void go(int x){
    if (x>=1&&x<=n){
        cout << x << ' ';
    }
    for (auto y:G[x]){
        if (!G[y].size()){
            cout << y << ' ';
        }
    }
    for (auto y:G[x]){
        if (G[y].size()) go(y);
    }
}
void solve(){
    cin >> n;
    for (int i=0;i<=n+1;i++) d[i]=0,G[i].clear();
    l=0; r=n+1;
    for (int i=1;i<=n;i++){
        int j; cin >> j;
        l=max(l,min(i,j));
        r=min(r,max(i,j));
        G[j].pb(i);
    }
    cout << l << endl;
    if (G[0].size()) go(0); else go(n+1);
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
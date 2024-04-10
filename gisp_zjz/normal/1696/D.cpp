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
int kase=0;
int n,p[maxn],a[maxn],lx[maxn],rx[maxn],ls[maxn],rs[maxn];
void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        p[a[i]]=i;
    }
    for (int i=2;i<=n;i++){
        lx[i]=ls[i]=a[i-1];
        if (i>2){
            lx[i]=max(lx[i-1],lx[i]);
            ls[i]=min(ls[i-1],ls[i]);
        }
    }
    for (int i=n-1;i>=1;i--){
        rx[i]=rs[i]=a[i+1];
        if (i<n-1){
            rx[i]=max(rx[i+1],rx[i]);
            rs[i]=min(rs[i+1],rs[i]);
        }
    }
    int ans=0,pos,o;
    pos=p[1]; o=0;
    while (pos>1){
        if (!o) pos=p[lx[pos]]; else pos=p[ls[pos]];
        o^=1; ans++;
    }
    pos=p[1]; o=0;
    while (pos<n){
        if (!o) pos=p[rx[pos]]; else pos=p[rs[pos]];
        o^=1; ans++;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
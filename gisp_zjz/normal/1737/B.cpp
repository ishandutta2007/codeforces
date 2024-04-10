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
int k;
ll cnt(ll x){
    if (x==0) return 0;
    ll y=sqrt(x);
    ll ret=y*3;
    if (x<y*(y+1)) ret--;
    if (x<y*(y+2)) ret--;
    return ret;
}
void solve(){
    ll l,r; cin >> l >> r;
    cout << cnt(r)-cnt(l-1) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
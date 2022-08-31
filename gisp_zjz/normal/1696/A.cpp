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
int n,z,a[maxn],mx;
void solve(){
    cin >> n >> z; mx=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        mx=max(mx,a[i]|z);
    }
    cout << mx << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
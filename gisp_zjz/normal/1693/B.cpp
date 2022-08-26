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
int n,p[maxn],ans;
ll l[maxn],r[maxn],s[maxn];
void solve(){
    cin >> n;
    for (int i=2;i<=n;i++) cin >> p[i];
    for (int i=1;i<=n;i++){
        cin >> l[i] >> r[i];
        s[i]=0;
    }
    ans=0;
    for (int i=n;i;i--){
        if (s[i]<l[i]) ans++; else r[i]=min(r[i],s[i]);
        s[p[i]]+=r[i];
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
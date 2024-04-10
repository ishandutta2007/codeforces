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
int n,op[maxn],p,q;
ll a[maxn],b[maxn];
void solve(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> op[i]; 
    p=0; q=0;
    for (int i=1;i<=n;i++){
        if (op[i]==0){
            p++;
            cin >> a[p];
        } else {
            q++;
            cin >> b[q];
        }
    }
    sort(a+1,a+p+1);
    sort(b+1,b+q+1);
    ll ans=0;
    for (int i=1;i<=p;i++) ans+=2*a[i];
    for (int i=1;i<=q;i++) ans+=2*b[i];
    if (p==q) ans-=min(a[1],b[1]);
    else if (p<q){
        for (int i=1;i<=q-p;i++) ans-=b[i];
    } else {
        for (int i=1;i<=p-q;i++) ans-=a[i];
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
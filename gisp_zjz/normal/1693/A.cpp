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
ll a[maxn];
void solve(){
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=2;i<=n;i++) a[i]+=a[i-1];
    if (a[n]!=0){puts("No");return;}
    for (int i=1;i<=n;i++) if (a[i]<0) {puts("No");return;}
    for (int i=1;i<n;i++) if (a[i]==0&&a[i+1]!=0) {puts("No");return;}
    puts("Yes");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
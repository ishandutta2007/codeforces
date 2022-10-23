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
int n,k;
ll s[maxn],a[maxn];
void solve(){
    cin >> n >> k;
    for (int i=n-k+1;i<=n;i++) cin >> s[i];
    if (k==1){puts("YES");return;}
    bool flag=0;
    int m=n-k+2;
    for (int i=m;i<=n;i++) a[i]=s[i]-s[i-1];
    for (int i=m;i<n;i++) if (a[i]>a[i+1]){
        puts("NO");return;
    }
    if (a[m]*(m-1)<s[m-1]){
        puts("NO");return;
    }
    puts("YES");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
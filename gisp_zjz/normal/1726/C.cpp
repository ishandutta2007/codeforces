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
char s[maxn];
int n,a[maxn],pre[maxn],sz[maxn];
void solve(){  
    cin >> n >> s+1;
    int ans=n;
    for (int i=1;i<n*2;i++) if (s[i]=='('&&s[i+1]==')') --ans;
    cout << ans+1 << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
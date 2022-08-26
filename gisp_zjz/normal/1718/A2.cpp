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
int _,n,a[maxn],s[maxn];
map<int,int> f;
void solve(){
    cin >> n; f.clear(); f[0]=0;
    int ans=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        s[i]=s[i-1]^a[i];
        int res=ans;
        if (f.find(s[i])!=f.end()){
            res=max(res,f[s[i]]+1);
        }
        ans=res;
        f[s[i]]=res;
    }
    cout << n-ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
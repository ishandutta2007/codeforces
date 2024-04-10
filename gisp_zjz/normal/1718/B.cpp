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
int n,m;
ll f[100],s[100],a[100];
void solve(){
    cin >> n;
    ll sum=0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    f[1]=s[1]=1; m=1;
    while (s[m]<sum){
        m++;
        f[m]=f[m-1]+f[m-2];
        s[m]=s[m-1]+f[m];
    }
    if (sum!=s[m]){puts("NO");return;}
    int last=-1;
    while (m){
        int id=-1;
        for (int i=0;i<n;i++){
            if (i==last) continue;
            if (id==-1||a[id]<a[i]) id=i;
        }
        if (id==-1||a[id]<f[m]){puts("NO");return;}
        a[id]-=f[m]; last=id;
        m--;
    }
    puts("YES");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
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
int n,m,k,p,q;
pi a[maxn],b[maxn];
void solve(){
    cin >> n >> k; p=0; q=0;
    for (int i=1;i<=n;i++){
        ll x; cin >> x;
        ll cnt=1;
        while (x%k==0) x/=k,cnt*=k;
        if (a[p].F==x) a[p].S+=cnt; 
        else {
            p++;
            a[p].F=x; a[p].S=cnt;
        }
    }
    cin >> m;
    for (int i=1;i<=m;i++){
        ll x; cin >> x;
        ll cnt=1;
        while (x%k==0) x/=k,cnt*=k;
        if (b[q].F==x) b[q].S+=cnt; 
        else {
            q++;
            b[q].F=x; b[q].S=cnt;
        }
    }
    if (p!=q){puts("No");return;}
    for (int i=1;i<=p;i++) if (a[i]!=b[i]) {puts("No");return;}
    puts("Yes");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}
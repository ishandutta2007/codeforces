#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define em emplace
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair

typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const ll INF = 1e18;
const int inf = 1e9;

int n;
int a[100010];

int chk(int s) {
    int ret = 0;
    for(int i=1; i<=n; i++) {
        if(a[i]) ret += abs(i - s), s += 2;
    }
    return ret;
} 

void solve() {
    cin >> n;

    int cnt = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] %= 2;
        if(a[i]) cnt++;
    }

    if(abs(n - 2 * cnt) > 1) {
        cout << "-1\n";
        return;
    }
    
    if(n == 2 * cnt) {
        cout << min(chk(1), chk(2)) << "\n";
    }
    else if(n/2 == cnt) {
        cout << chk(2) << "\n";
    }
    else {
        cout << chk(1) << "\n";
    }
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
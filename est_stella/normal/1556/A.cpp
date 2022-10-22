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

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        x = abs(x), y = abs(y);
        if(x % 2 != y % 2) cout << -1;
        else if(x == 0 && y == 0) cout << 0;
        else if(x == y) cout << 1;
        else cout << 2;
        cout << "\n";
    }
}
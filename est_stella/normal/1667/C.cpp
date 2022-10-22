#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf = 1e9;
const ll INF = 1e18;

int main() {
    fast;

    int n;
    cin >> n;
    int k = (n+1)/3;

    cout << n - k << "\n";
    for(int i=1; i<=n-k; i++) {
        if(i <= k) cout << i << " " << k-i+1 << "\n";
        else if(i <= 2*k-1) cout << i << " " << 3*k - i << "\n";
        else cout << i << " " << i << "\n";
    }
}
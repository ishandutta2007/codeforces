#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int scan(int x, int y) {
    cout << "SCAN " << x << " " << y << endl;
    int r;
    cin >> r;
    return r;
}

int dig(int x, int y) {
    cout << "DIG " << x << " " << y << endl;
    int r;
    cin >> r;
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int x = scan(1, 1);
    int y = scan(n, 1);

    int ans[2][2] = {};
    int w = (x - y + 2 * n + 2) / 2;
    ans[0][0] = 1 + (x - scan(w/2, 1)) / 2;
    ans[1][0] = w - ans[0][0];

    int z = 1;
    for(int i=1; i<=2*m; i++) {
        if(i-2 + w-2 == x) {
            z = i;
        }
    }

    ans[0][1] = 1 + (x - scan(1, z/2)) / 2;
    ans[1][1] = z - ans[0][1];

    if(dig(ans[0][0], ans[0][1])) {
        dig(ans[1][0], ans[1][1]);
    }
    else {
        dig(ans[1][0], ans[0][1]);
        dig(ans[0][0], ans[1][1]);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n, q;
int a[400010];
int b[400010];
int c[400010];
int ab[400010];
int bc[400010];
int abc[400010];
string s;

void update(int node, int s, int e, int i, int x) {
    if(s == e) {
        a[node] = b[node] = c[node] = ab[node] = bc[node] = abc[node] = 0;
        if(x == 0) a[node] = 1;
        else if(x == 1) b[node] = 1;
        else c[node] = 1;
        return;
    }

    int m = s + e >> 1;
    if(i <= m) update(node*2, s, m, i, x);
    else update(node*2+1, m+1, e, i, x);

    a[node] = a[node*2] + a[node*2+1];
    b[node] = b[node*2] + b[node*2+1];
    c[node] = c[node*2] + c[node*2+1];
    ab[node] = min({a[node*2] + b[node*2+1], ab[node*2] + b[node*2+1], a[node*2] + ab[node*2+1]});
    bc[node] = min({b[node*2] + c[node*2+1], bc[node*2] + c[node*2+1], b[node*2] + bc[node*2+1]});
    abc[node] = min({a[node*2] + abc[node*2+1], a[node*2] + bc[node*2+1], ab[node*2] + bc[node*2+1], ab[node*2] + c[node*2+1], abc[node*2] + c[node*2+1]});
}

int main() {
    fast;

    cin >> n >> q;
    cin >> s;

    for(int i=0; i<n; i++) {
        update(1, 1, n, i+1, s[i] - 'a');
    }

    while(q--) {
        int x;
        string C;
        cin >> x >> C;

        update(1, 1, n, x, C[0]-'a');

        cout << min({a[1], b[1], c[1], ab[1], bc[1], abc[1]}) << "\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 1e5 + 7;
const int V = 7001;
using bs = bitset <V>;

bs a[N];

bs kek[V];
bs dv[V];

bool prm(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void init() {
    for (int i = 1; i < V; ++i) {
        for (int j = i; j < V; j += i) {
            dv[j][i] = 1;
        }
    }
    vector <int> ok(V + 1, true);
    for (int i = 2; i < V; ++i) {
        for (int j = i * i; j < V; j += i * i) {
            ok[j] = false;
        }
    }
    for (int i = V - 1; i >= 1; --i) {
        for (int j = i; j < V; j += i) {
            if (ok[j / i]) {
                kek[i][j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            --x;
            a[x] = dv[v];
        }
        else if (t == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            --x, --y, --z;
            a[x] = a[y] ^ a[z];
        }
        else if (t == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            --x, --y, --z;
            a[x] = a[y] & a[z];
        }
        else {
            int x, v;
            cin >> x >> v;
            --x;
            bs cur = a[x] & kek[v];
            cout << (cur.count() & 1); 
        }
    }
}
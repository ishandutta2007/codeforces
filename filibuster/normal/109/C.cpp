#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int A = 513;

int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
/*
*/

mt19937 rnd(0);

int p[N], sz[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return ;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    for(int i = 1; i < n; i++) {
        int v, u, w;
        cin >> v >> u >> w;

        v--;
        u--;

        int x = w;
        bool fl = false;
        while(x > 0) {
            if(x % 10 != 4 && x % 10 != 7) {
                fl = true;
                break;
            }
            x /= 10;
        }
        if(fl) {
            unite(v, u);
        }
    }

    li ans = n * 1ll * (n - 1) * (n - 2);

    for(int i = 0; i < n; i++) {
        if(p[i] == i) {
            ans -= sz[i] * 1ll * (sz[i] - 1) * (n - sz[i]) * 2;
            ans -= sz[i] * 1ll * (sz[i] - 1) * (sz[i] - 2);
        }
    }

    cout << ans << endl;
}
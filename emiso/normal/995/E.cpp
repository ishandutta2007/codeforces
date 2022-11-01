#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD;

ll mypow(ll a, ll e) {
    if(!e) return 1;
    a %= MOD;
    if(e & 1) return (a * mypow(a*a, e / 2)) % MOD;
    return mypow(a*a, e / 2);
}

ll inv_mod(ll a) {
    return mypow(a, MOD - 2);
}

map<int, int> d[2], p[2];

int op(int x, int t) {
    if(t == 1) {
        x++;
        if(x == MOD) x = 0;
        return x;
    }
    if(t == 2) {
        if(x == 0) x += MOD;
        x--;
        return x;
    }
    return inv_mod(x);
}

int bfs(int u, int t) {
    queue<int> fila;
    fila.push(u);
    d[t][u] = 0;

    while(!fila.empty()) {
        if(!t && d[0].size() > 1000000 || (clock() * 1.0 / CLOCKS_PER_SEC) > 2.5) break;

        int u = fila.front(); fila.pop();
        int du = d[t][u];

        if(t && d[0].count(u)) return u;
        if(du == 100) continue;

        for(int i = 1; i <= 3; i++) {
            int v = op(u, i);
            if(!d[t].count(v)) {
                d[t][v] = du + 1;
                p[t][v] = i;
                fila.push(v);
            }
        }
    }

    assert(!t);
    return -1;
}

int main() {
    int u, v, p_, m;
    scanf("%d %d %d", &u, &v, &p_);

    MOD = p_;
    bfs(u, 0);
    m = bfs(v, 1);


    vector<int> ops;
    for(int M = m; M != u;) {
        int o = p[0][M];
        ops.push_back(o);

        if(o == 3) M = op(M, o);
        else M = op(M, 3 - o);
    }

    reverse(ops.begin(), ops.end());

    for(int M = m; M != v;) {
        int o = p[1][M];

        if(o == 3) {
            M = op(M, o);
            ops.push_back(o);
        }
        else {
            M = op(M, 3 - o);
            ops.push_back(3 - o);
        }
    }

    printf("%d\n", ops.size());
    for(int x : ops)
        printf("%d ", x);

    return 0;
}
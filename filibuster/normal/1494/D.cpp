#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 1e9 + 13;
const int N = 1000 + 13;
const int M = 1e9 + 7;

/*

*/

int a[N][N];
int par[N];
int c[N];
pair<int, pii> b[N * N];
int lca[N][N];
int anc[N];


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[i * n + j] = {a[i][j], {i, j}};
        }

        c[i] = a[i][i];
    }



    sort(b, b + n * n);
    reverse(b, b + n * n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            lca[i][j] = n;
        }
        anc[i] = n;
    }
    c[n] = b[0].f;
    par[n] = -1;

    int cur = n;
    for(int ind = 0; ind < n * n; ind++) {
        int v = b[ind].s.f, u = b[ind].s.s, x = b[ind].f;

        if(v == u)
            continue;

        if(x == c[anc[u]])
            swap(v, u);

        if(x == c[anc[v]] && x == c[anc[u]]) {
            lca[v][u] = lca[u][v] = anc[v];
//            anc[v] = anc[u] = anc[v];
        } else if(x == c[anc[v]]) {
            lca[v][u] = lca[u][v] = anc[v];
            anc[u] = anc[v];
        } else {

            cur++;
            c[cur] = x;
            par[cur] = anc[v];
            lca[v][u] = lca[u][v] = cur;
            anc[v] = anc[u] = cur;

//            cout << ind << ' ' << v << ' ' << u << ' ' << cur << ' '<< par[cur] <<endl;
        }
    }

    cout << cur + 1 << endl;
    for(int i = 0; i <= cur; i++) {
        cout << c[i] << ' ';
    }
    cout << endl;

    cout << n + 1 << endl;
    for(int i = 0; i < n; i++) {
        cout << i + 1 << ' ' << anc[i] + 1 << endl;
    }

    for(int i = n + 1; i <= cur; i++) {
        cout << i + 1 << ' ' << par[i] + 1 << endl;
    }

}
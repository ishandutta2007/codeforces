#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

bool ispr(int x){
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0)
            return false;
    }

    return true;
}

bool pr[50000];
bool b[300][300];

const int MAXN = 250;
const int INF = 1e9;

int n, c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN];
 
bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt) {
        int v = q[qh++];
        for (int to=0; to<n; ++to)
            if (d[to] == -1 && f[v][to] < c[v][to]) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
    }
    return d[t] != -1;
}
 
int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (int & to=ptr[v]; to<n; ++to) {
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
        if (pushed) {
            f[v][to] += pushed;
            f[to][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}
 
int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

int main(){

    for (int i = 2; i < 50000; i++){
        pr[i] = ispr(i);
    }

    cin >> n;
    vector<int> a(n);
    for (itn i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            b[i][j] = pr[a[i] + a[j]];
        }
    }
    s = n;
    t = n + 1;
    for (int i = 0; i < n; i++){
        if (a[i] & 1)
            c[s][i] = 2;
        else
            c[i][t] = 2;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if ((a[i] & 1) && b[i][j])
                c[i][j] = 1;
        }
    }
    n += 2;
    if (dinic() < n - 2){
        cout << "Impossible\n";
        return 0;
    } else {
        n -= 2;
        vector<vector<int> > tabl;
        vector<char> used(n, 0);
        for (int i = 0; i < n; i++){
            if (!used[i]){
                tabl.pb(vector<int>(1, i + 1));
                int v = i;
                int w = 0;
                used[v] = 1;
                while (!f[v][w])
                    w++;
                while (!used[w]){
                    used[w] = 1;
                    tabl.back().pb(w + 1);
                    int i = 0;
                    while (!f[w][i] || i == v)
                        i++;
                    v = w;
                    w = i;
                }
            }
        }
        cout << tabl.size() << "\n";
        for (auto V : tabl){
            cout << V.size() << " ";
            for (auto x : V)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
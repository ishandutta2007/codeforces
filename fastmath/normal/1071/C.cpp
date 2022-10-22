#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const int LEN = 14;

bool check(int mask) {
    for (int i = LEN - 6; i < LEN; ++i) {
        if ((mask >> i) & 1) return 0;
    }
    return 1;
}   

int dist[1 << LEN];
vector <pair <int, int> > path[1 << LEN];
int sixdist[1 << LEN];
vector <pair <int, int> > sixpath[1 << LEN];
void prec() {
    for (int i = 0; i < (1 << LEN); ++i) dist[i] = INF;
    queue <int> q;
    q.push(0);            
    dist[0] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int add = 1; add < LEN; ++add) {
            for (int i = 0; i + (add << 1) < LEN; ++i) {
                int v = u ^ (1 << i) ^ (1 << (i + add)) ^ (1 << (i + (add << 1)));
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    path[v] = path[u];
                    path[v].push_back({i, add});
                    q.push(v);
                }   
            }
        }
    }

    for (int i = 0; i < (1 << LEN); ++i) sixdist[i] = INF;
    for (int i = 0; i < (1 << LEN); ++i) {
        if (check(i)) {
            sixdist[i] = 0;
            q.push(i);
        }   
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int add = 1; add < LEN; ++add) {
            for (int i = 0; i + (add << 1) < LEN; ++i) {
                int v = u ^ (1 << i) ^ (1 << (i + add)) ^ (1 << (i + (add << 1)));
                if (sixdist[u] + 1 < sixdist[v]) {
                    sixdist[v] = sixdist[u] + 1;
                    sixpath[v] = sixpath[u];
                    sixpath[v].push_back({i, add});
                    q.push(v);
                }   
            }
        }        
    }
}

int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

vector <pair <int, int> > ans;

int smalldist[1 << LEN];
vector <pair <int, int> > smallpath[1 << LEN];
void solvesmall() {
    for (int i = 0; i < (1 << LEN); ++i) smalldist[i] = INF;
    queue <int> q;
    q.push(0);
    smalldist[0] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int add = 1; add < LEN; ++add) {
            for (int i = 0; i + (add << 1) < n; ++i) {
                int v = u ^ (1 << i) ^ (1 << (i + add)) ^ (1 << (i + (add << 1)));
                if (smalldist[u] + 1 < smalldist[v]) {
                    smalldist[v] = smalldist[u] + 1;
                    smallpath[v] = smallpath[u];
                    smallpath[v].push_back({i, add});
                    q.push(v);
                }   
            }
        }   
    }
    int mask = 0;
    for (int i = 0; i < n; ++i) mask += a[i] * (1 << i);
    if (smalldist[mask] == INF) {
        cout << "NO\n";
        exit(0);
    }
    else {
        ans = smallpath[mask];
    }   
}

void solvebig() {
    while (LEN < n) {
        int mask = 0;
        for (int i = n - 6; i < n; ++i) {
            int num = i - (n - 14);
            mask += a[i] * (1 << num);
        }
        //cout << "add " << sixpath[mask].size() << '\n';
        for (auto e : sixpath[mask]) {
            int num = (n - 14) + e.first;
            a[num] ^= 1;
            a[num + e.second] ^= 1;
            a[num + (e.second << 1)] ^= 1;
            ans.push_back({num, e.second});
        }
        n -= 6;
    }
    int mask = 0;
    for (int i = 0; i < n; ++i) {
        mask += a[i] * (1 << i);
    }
    for (auto e : path[mask]) ans.push_back(e);
}

void print() {
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto e : ans) cout << e.first + 1 << ' ' << e.first + e.second + 1 << ' ' << e.first + (e.second << 1) + 1 << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prec();
    read();
    if (n < LEN) solvesmall();
    else solvebig();
    print();

    return 0;
}
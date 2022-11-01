#include <bits/stdc++.h>

#define MN 200020
#define MOD 998244353

using namespace std;
typedef long long ll;

int n, m;
vector<int> adj[MN], radj[MN];

ll dist[MN][2];

void bfs01() {
    for(int i = 0; i < MN; i++) dist[i][0] = dist[i][1] = 1234567890123456LL;
    dist[1][0] = 0;
    priority_queue<pair<ll, pair<int, int>>> fila;
    fila.push({0, {1, 0}});
    while(!fila.empty()) {
        int u = fila.top().second.first, st = fila.top().second.second;
        ll d = -fila.top().first;
        fila.pop();

        if(d != dist[u][st]) continue;

        if(dist[u][1-st] > dist[u][st] + 1) {
            dist[u][1-st] = dist[u][st] + 1;
            fila.push({-dist[u][1-st], {u, 1-st}});
        }

        if(st == 0) {
            for(int v : adj[u]) {
                if(dist[v][st] > dist[u][st]) {
                    dist[v][st] = dist[u][st];
                    fila.push({-dist[v][st], {v, st}});
                }
            }
        } else {
            for(int v : radj[u]) {
                if(dist[v][st] > dist[u][st]) {
                    dist[v][st] = dist[u][st];
                    fila.push({-dist[v][st], {v, st}});
                }
            }
        }
    }
}

struct s {
    int no, st, rev, d;
    bool operator <(const s& o) const {
        return tie(d, no, st, rev) < tie(o.d, o.no, o.st, o.rev);
    }
};

ll dd[MN][2][21];
ll solve(int no, int st, int rev) {
    for(int i = 0; i < MN; i++)
        for(int j = 0; j < 21; j++)
            dd[i][0][j] = dd[i][1][j] = 1234567890123456LL;
    dd[no][st][rev] = 0;
    set<s> pq({{no, st, rev, 0}});

    int ans = 123456789;
    while(!pq.empty()) {
        s u = *(pq.begin());
        pq.erase(pq.begin());
        no = u.no, st = u.st, rev = u.rev;
        int d = u.d;
        if(d != dd[no][st][rev]) continue;
        if(no == n) ans = min(ans, d);

        if(rev < 20 && dd[no][1-st][rev+1] > d + (1<<rev)) {
            dd[no][1-st][rev+1] = d + (1<<rev);
            pq.insert({no, 1-st, rev+1, d + (1<<rev)});
        }
        if(st == 0) {
            for(int v : adj[no]) {
                if(dd[v][st][rev] > d + 1) {
                    dd[v][st][rev] = d + 1;
                    pq.insert({v, st, rev, d + 1});
                }
            }
        } else {
            for(int v : radj[no]) {
                if(dd[v][st][rev] > d + 1) {
                    dd[v][st][rev] = d + 1;
                    pq.insert({v, st, rev, d + 1});
                }
            }
        }
    }
    return ans;
}

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

struct s3 {
    ll no, st, d;
    bool operator <(const s3& o) const {
        return tie(d, no, st) < tie(o.d, o.no, o.st);
    }
};

ll d3[MN][2];
pair<ll, ll> otherbfs() {
    for(int i = 0; i < MN; i++) d3[i][0] = d3[i][1] = 1234567890123456LL;
    d3[1][0] = 0;
    set<s3> pq({{1, 0, 0}});
    while(!pq.empty()) {
        s3 tt = *(pq.begin());
        pq.erase(pq.begin());
        ll u = tt.no, st = tt.st, d = tt.d;
        if(d != d3[u][st]) continue;

        if(d3[u][1-st] > d + (1 << 25)) {
            d3[u][1-st] = d + (1 << 25);
            pq.insert({u, 1-st, d3[u][1-st]});
        }
        if(st == 0) {
            for(int v : adj[u]) {
                if(d3[v][st] > d + 1) {
                    d3[v][st] = d + 1;
                    pq.insert({v, st, d + 1});
                }
            }
        } else {
            for(int v : radj[u]) {
                if(d3[v][st] > d + 1) {
                    d3[v][st] = d + 1;
                    pq.insert({v, st, d + 1});
                }
            }
        }
    }
    return {min(d3[n][0], d3[n][1]) % (1 << 25), min(d3[n][0], d3[n][1]) / (1 << 25)};
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    bfs01();

    int k2 = min(dist[n][0], dist[n][1]);
    cerr << dist[n][0] << " " << dist[n][1] << endl;
    if(k2 > 20) {
        auto tt = otherbfs();
        ll ans = (0LL + tt.first + expo(2, tt.second) - 1 + MOD) % MOD;
        printf("%lld\n", ans);
    } else {
        printf("%lld\n", solve(1, 0, 0));
    }

    return 0;
}
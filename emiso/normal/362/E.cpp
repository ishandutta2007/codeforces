#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct SSP {
    ll n, source, sink;
    vector<vector<ll> > adj;

    struct edge {
        ll u, flow, cap, cost, origcost;
    };
    vector<edge> edges;

    SSP(ll n, ll source, ll sink)
        : n(n) , source(source) , sink(sink) , adj(n) {}

    ll add_edge(ll a, ll b, ll cap, ll cost) {
        ll result = edges.size();
        adj[a].push_back(edges.size());
        edges.push_back({ b, 0, cap, cost, cost });
        adj[b].push_back(edges.size());
        edges.push_back({ a, 0, 0, -cost, -cost });
        return result;
    }
    pair<ll, ll> iterate() {
        struct state_t {
            ll dist, prev, maxf;
        };
        priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
        vector<state_t> states(n, { INT_MAX / 2, -1, 0 });
        states[source] = { 0, -2, INT_MAX };
        pq.push(make_pair(states[source].dist, source));
        while (!pq.empty()) {
            ll d, v;
            tie(d, v) = pq.top();
            pq.pop();
            if (d != states[v].dist) continue;
            for (ll edid : adj[v]) {
                edge& ed = edges[edid];
                if (ed.flow < ed.cap && states[ed.u].dist > states[v].dist + ed.cost) {
                    states[ed.u].dist = states[v].dist + ed.cost;
                    states[ed.u].prev = edid;
                    states[ed.u].maxf = min(states[v].maxf, ed.cap - ed.flow);

                    pq.push(make_pair(states[ed.u].dist, ed.u));
                }
            }
        }
        ll lastid = states[sink].prev, extraflow = states[sink].maxf, atcost = 0;
        if (lastid == -1) return { 0, 0 };
        for (ll id = lastid; id != -2; id = states[edges[id ^ 1].u].prev) {
            edges[id].flow += extraflow;
            edges[id ^ 1].flow -= extraflow;
            atcost += edges[id].origcost;
        }
        for (ll id = 0; id < (ll)edges.size(); ++id) {
            ll v = edges[id ^ 1].u, u = edges[id].u;
            if (states[v].prev != -1 && states[u].prev != -1)
                edges[id].cost += states[v].dist - states[u].dist;
        }
        return { extraflow, atcost };
    }
    pair<ll, ll> mcmf() {
        ll flow = 0, cost = 0;
        ll extraflow, atcost;
        while (tie(extraflow, atcost) = iterate(), extraflow > 0)
            flow += extraflow, cost += extraflow * atcost;
        return { flow, cost };
    }
};

int n, k, c[55][55];
SSP* g;

void gen(int f) {
    g = new SSP(n+3, n+1, n);
    g->add_edge(n+1, 1, f, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(c[i][j]) {
                g->add_edge(i, j, c[i][j], 0);
                g->add_edge(i, j, 1000000000, 1);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int l = 0, r = 1000000000, m;
    while(l < r) {
       m = (l + r + 1) / 2;
       gen(m);
       auto tt = g->mcmf();
       if(tt.first == m && tt.second <= k) l = m;
       else r = m - 1;
    }
    printf("%d\n", l);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// call randint() for a random integer
mt19937 randint(3);

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

// returns a random double from 0 to 1
inline double rand01() {
    return uniform_randint(0, INT_MAX)/double(INT_MAX);
}

// randomly and uniformly select k distinct integers in the range [0..n-1]
// runs in O(klog(n/k))
vector<int> random_sample(int k, int n) {
    vector<int> r(k);
    std::iota(r.begin(), r.end(), 0);
    double w = exp(log(rand01())/k);
    int i = k-1;
    while (i < n) {
        i += 1+floor(log(rand01())/log(1-w));
        if (i < n) {
            r[uniform_randint(0, k-1)] = i;
            w *= exp(log(rand01())/k);
        }
    }
    return r;
}

// interaction
vector<vector<int>> hidden_adj;
int hidden_ops;
// vector<int> qry(int i) {
//     cout << "? " << i << endl;
//     if (++hidden_ops > 16) {
//         debug("TOO MANY");
//         exit(0);
//     }
//     debug(hidden_adj[i]);
//     return hidden_adj[i];
// }

void read_hidden(int h, int t) {
    hidden_adj.assign((1<<h)-1, {});
    hidden_ops = 0;
    vector<int> p((1<<h)-1);
    iota(all(p), 0);
    for (int i = 1; i < (1<<h)-1; i++)
        swap(p[i], p[uniform_randint(max(1, i-10), i)]);
    swap(p[0], p[t%p.size()]);
    for (int i = 1; i < (1<<h)-1; i++) {
        int x = p[i], y = p[(i+1)/2-1];
        hidden_adj[x].pb(y);
        hidden_adj[y].pb(x);
    }
    for (int i = 0; i < (1<<h)-1; i++)
        random_shuffle(all(hidden_adj[i]));
}

vector<int> qry(int i) {
    cout << "? " << i+1 << endl;
    int k; cin >> k;
    if (k == 0) exit(0);
    vector<int> r(k);
    for (int j = 0; j < k; j++)
        cin >> r[j], r[j]--;
    return r;
}

void submit(int i) {
    cout << "! " << i+1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    int test = 0;
    while (t--) {
        start:;
        int h; cin >> h;
        // read_hidden(h, test++);
        if (h == 0) exit(0);
        vector<vector<int>> adj((1<<h)-1);

        int qs = 0;
        auto upd = [&](int x) {
            if (adj[x].empty()) {
                adj[x] = qry(x);
            }
        };

        map<int, int> d;

        auto parent = [&](int x) {
            upd(x);
            if (adj[x].size() == 2) {
                d[x] = 0;
                debug(x, "2");
                return x;
            }
            if (adj[x].size() == 1) {
                d[x] = h-1;
                debug(x, adj[x], "1");
                return adj[x][0];
            }
            vector<vector<int>> a(3);
            for (int i = 0; i < 3; i++)
                a[i] = {x, adj[x][i]};
            for (int i = 1; i < 3; i++)
                if (adj[a[i][1]].size() > 0)
                    swap(a[i], a[0]);
            while (1) {
                int found = 0;
                for (int i = 0; i < 3; i++) {
                    if (i == 2 && found) {
                        if (found == 2) {
                            a[i].pb(-1);
                        }
                        break;
                    }
                    upd(a[i].back());
                    if (adj[a[i].back()].size() == 2) {
                        debug(a[i].back(), "2");
                        d[a[i].back()] = 0;
                        return a[i].back();
                    }
                    if (adj[a[i].back()].size() == 1) {
                        found++;
                    }
                    bool added = 0;
                    for (int j : adj[a[i].back()]) 
                        if (j != a[i][a[i].size()-2] && adj[j].size() > 0) {
                            a[i].push_back(j); added = 1; break;
                        }
                    if (!added)
                        for (int j : adj[a[i].back()]) 
                            if (j != a[i][a[i].size()-2]) {
                                a[i].push_back(j); break;
                            }
                }
                if (found) break;
            }
            int b = 0;
            if (a[1].size() > a[b].size()) b = 1;
            if (a[2].size() > a[b].size()) b = 2;
            debug(x, a, b);
            d[x] = h-a[b].size()+1;
            return a[b][1];
        };

        auto search = [&](int x) {
            debug("search", x);
            set<int> vis;
            int c = 0;
            queue<int> q({x});
            set<int> vv; vector<int> v;
            while (!q.empty()) {
                int i = q.front(); q.pop();
                vis.insert(i);
                vv.insert(i);
                debug(i);
                upd(i);
                if (adj[i].size() == 2)
                    return i;
                for (int j : adj[i]) {
                    if (!vis.count(j)) {
                        vv.insert(j);
                        q.push(j);
                    }
                }
                if (++c == 4) break;
            }
            for (int i : vv) v.pb(i);
            sort(all(v), [&](int i, int j){
                return adj[i].size() > adj[j].size();
            });
            debug(v);
            c = 0;
            for (int i : v) {
                if (++c == 10)
                    return i;
                upd(i);
                if (adj[i].size() == 2)
                    return i;
            }
            return -1;
        };

        int x = 0;
        while (1) {
            int b = parent(x);
            debug(x, b, d[x]);
            if (x == b) {
                submit(b);
                break;
            }
            if (d[x] <= 3) {
                int c = search(b);
                submit(c);
                break;
            }
            x = b;
        }
    }
}
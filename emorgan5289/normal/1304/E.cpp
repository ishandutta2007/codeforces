#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long

// these to_string headers are taken from tourist on codeforces

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("input.in");
#endif

// O(nlogn) to set up, O(1) to query
struct lca {

    vector<pair<int, int>> euler_walk;
    vector<vector<pair<int, int>>> range_mins;
    vector<int> walk_index;
    vector<bool> visited;

    void _label_walk(vector<vector<int>>& edges, int i, int depth) {
        visited[i] = 1;
        walk_index[i] = euler_walk.size();
        euler_walk.push_back({depth, i});
        for (int j : edges[i]) {
            if (visited[j]) continue;
            _label_walk(edges, j, depth+1);
            euler_walk.push_back({depth, i});
        }
    }

    // Accepts an adjecency list. Can include or exlude parents, it works either way.
    lca(vector<vector<int>>& edges, int root) {

        // set up the euler walk
        walk_index = vector<int>(edges.size(), 0);
        visited = vector<bool>(edges.size(), 0);
        _label_walk(edges, root, 0);

        // set up RMQ lookup table
        range_mins.push_back({});
        for (int i = 0; i < euler_walk.size(); i++)
            range_mins.back().push_back(euler_walk[i]);
        for (int len = 2; len <= euler_walk.size(); len <<= 1) {
            auto prev = range_mins.back();
            range_mins.push_back({});
            for (int i = 0; i < euler_walk.size()-len+1; i++)
                range_mins.back().push_back(min(prev[i], prev[i+len/2]));
        }
    }

    int query(int i, int j) {
        int a = min(walk_index[i], walk_index[j]);
        int b = max(walk_index[i], walk_index[j]);
        if (b == a) return i;
        int n = floor(log2(b-a));
        return min(range_mins[n][a], range_mins[n][b-pow(2, n)+1]).second;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; fin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; fin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> depth(n, -1), stack = {0};
    depth[0] = 0;
    while (!stack.empty()) {
        int i = stack.back();
        stack.pop_back();
        for (int j : adj[i])
            if (depth[j] == -1) {
                depth[j] = depth[i]+1;
                stack.push_back(j);
            }
    }
    lca l(adj, 0);

    int q; fin >> q;
    while (q--) {
        int x, y, a, b, k; fin >> x >> y >> a >> b >> k;
        a--; b--; x--; y--;
        int ab = depth[a]+depth[b]-2*depth[l.query(a, b)];
        int ax = depth[a]+depth[x]-2*depth[l.query(a, x)];
        int ay = depth[a]+depth[y]-2*depth[l.query(a, y)];
        int bx = depth[b]+depth[x]-2*depth[l.query(b, x)];
        int by = depth[b]+depth[y]-2*depth[l.query(b, y)];

        bool flag = false;
        int r = ab;
        if (r <= k && r%2 == k%2) flag = true;
        r = ax+by+1;
        if (r <= k && r%2 == k%2) flag = true;
        r = ay+bx+1;
        if (r <= k && r%2 == k%2) flag = true;
        cout << (flag ? "YES" : "NO") << "\n";
    }
}
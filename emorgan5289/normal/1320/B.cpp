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

// #define DEBUG

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("input.in");
#else
#define debug(...)
#define fin cin
#endif

vector<int> dijkstra(vector<vector<pair<int, int>>> adj, int start) {

    int size = adj.size();
    vector<bool> visited(size, 0);
    priority_queue<pair<int, int>> heap;
    heap.push({0, start});
    vector<int> out(size, inf);

    while (!heap.empty()) {
        int n = heap.top().second;
        int mincost = -heap.top().first;
        heap.pop();
        if (visited[n])
            continue;
        visited[n] = 1;
        out[n] = mincost;
        for (auto p : adj[n])
            if (!visited[p.second])
                heap.push({-(mincost+p.first), p.second});
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    fin >> N >> M;
    vector<vector<pair<int, int>>> adj(N), radj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        adj[a-1].push_back({1, b-1});
        radj[b-1].push_back({1, a-1});
    }
    fin >> K;
    vector<int> P(K);
    for (auto& x : P) fin >> x;

    vector<int> cost = dijkstra(radj, P[K-1]-1);

    int mi = 0, ma = 0;
    for (int i = 0; i < K-1; i++) {
        int a = P[i]-1, b = P[i+1]-1;
        // debug(a, b, cost[a], cost[b]);
        if (cost[b] != cost[a]-1) {
            mi++; ma++;
        } else {
            int c = 0;
            for (auto x : adj[a])
                if (cost[x.second] == cost[a]-1)
                    c++;
            if (c > 1) ma++;
        }
    }
    cout << mi << " " << ma << "\n";
}
#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long

#define all(x) (x).begin(), (x).end()

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k; fin >> n >> m >> k;
    vector<int> a(k);
    for (auto& x : a) fin >> x;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int c, b; fin >> c >> b;
        // debug(c, b);
        adj[c-1].push_back(b-1);
        adj[b-1].push_back(c-1);
    }

    vector<pair<int, int>> cost(n, {-1, -1});
    cost[0] = {0, -1};
    cost[n-1] = {-1, 0};
    deque<int> q;

    q.push_back(0);
    while (!q.empty()) {
        int i = q[0]; q.pop_front();
        for (int j : adj[i])
            if (cost[j].first == -1) {
                cost[j].first = cost[i].first+1;
                q.push_back(j);
            }
    }

    q.push_back(n-1);
    while (!q.empty()) {
        int i = q[0]; q.pop_front();
        for (int j : adj[i])
            if (cost[j].second == -1) {
                cost[j].second = cost[i].second+1;
                q.push_back(j);
            }
    }

    // debug(cost);

    vector<pair<int, int>> s; s.reserve(k);
    for (auto& x : a)
        s.push_back(cost[x-1]);
    sort(all(s), [](pair<int, int> p, pair<int, int> r){ return p.first-p.second < r.first-r.second; });

    int rmax = -inf, out = 0;
    for (int i = 0; i < k; i++) {
        out = max(out, s[i].second+rmax+1);
        rmax = max(rmax, s[i].first);
    }

    cout << min(out, cost[0].second) << endl;
}
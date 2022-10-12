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

template<typename T, T F(T, T), T identity>
struct segtree {

    int length;
    vector<T> tree, updates;

    segtree(int s) {
        length = pow(2, ceil(log2(s)));
        tree = vector<T>(2*length, identity);
        updates = vector<T>(2*length, identity);
    }

    segtree(vector<T>& v) : segtree(v.size()) {
        for (int i = 0; i < v.size(); i++)
            tree[length+i] = v[i];
        for (int i = length-1; i > 0; i--)
            tree[i] = F(tree[2*i], tree[2*i+1]);
    }

    inline void propogate(int i) {
        int val = updates[i];
        if (i < length) {
            updates[2*i] = F(updates[2*i], val);
            updates[2*i+1] = F(updates[2*i+1], val);
        }
        tree[i] = F(tree[i], val);
        updates[i] = identity;
    }

    T get_r(int j, int i, int lower, int upper) {
        propogate(i);
        if (lower == upper)
            return tree[i];
        int mid = (lower+upper)/2;
        if (j > mid)
            return get_r(j, 2*i+1, mid+1, upper);
        return get_r(j, 2*i, lower, mid);
    }

    void update_r(int a, int b, T val, int i, int lower, int upper) {
        if (a <= lower && b >= upper)
            updates[i] = F(updates[i], val);
        propogate(i);
        if (b < lower || a > upper || (a <= lower && b >= upper)) 
            return;
        int mid = (lower+upper)/2;
        update_r(a, b, val, 2*i, lower, mid);
        update_r(a, b, val, 2*i+1, mid+1, upper);
        tree[i] = F(tree[2*i], tree[2*i+1]);
    }

    T range_r(int a, int b, int i, int lower, int upper) {
        propogate(i);
        if (b < lower || a > upper)
            return identity;
        if (a <= lower && b >= upper)
            return tree[i];
        int mid = (lower+upper)/2;
        return F(range_r(a, b, 2*i, lower, mid), range_r(a, b, 2*i+1, mid+1, upper));
    }

    // gets value at index i
    inline T get(int i) {
        return get_r(i, 1, 0, length-1);
    }

    // sets every element x in [a..b] to F(x, val)
    inline void update(int a, int b, T val) {
        update_r(a, b, val, 1, 0, length-1);
    }

    // computes F over the range [a..b]
    inline T query(int a, int b) {
        return range_r(a, b, 1, 0, length-1);
    }
};

int n;
int adj[1000001][26], vin[1000001], vout[1000001], inc[1000001], nextinc[1000002];
vector<int> euler_walk;

void walk(int i) {
    vin[i] = euler_walk.size();
    euler_walk.push_back(i);
    for (int j = 0; j < 26; j++)
        if (adj[i][j] != -1) {
            walk(adj[i][j]);
        }
    vout[i] = euler_walk.size()-1;
}

int _min(int a, int b) {return min(a, b);}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    fin >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 26; j++)
            adj[i][j] = -1;
    for (int i = 0; i < n; i++) {
        int p; char c; fin >> p >> c;
        adj[p][c-'a'] = i+1;
    }
    walk(0);

    int k; fin >> k;
    vector<int> S(k);
    for (auto& x : S) fin >> x;
    for (auto x : S) inc[vin[x]] = 1;

    inc[0] = 0; int r = n;
    for (int i = 1; i <= n; i++) {
        if (inc[i]) inc[i] = --r;
        else inc[i] = 0;
        nextinc[i] = inc[i];
    }

    nextinc[n+1] = inf;
    for (int i = n; i >= 0; i--)
        if (!nextinc[i]) nextinc[i] = nextinc[i+1];

    segtree<int, _min, inf> cost(n+1);
    cost.update(0, 0, inc[0]);
    // for (int i = 0; i <= n; i++)
    //     debug(i, inc[i]);

    for (auto& i : euler_walk) {
        int v = vin[i];
        int c = cost.get(v);
        // debug(i);
        for (int j = 0; j < 26; j++) {
            int q = adj[i][j];
            if (q != -1) {
                // debug(v, q, vin[q], c+1-inc[v]+inc[vin[q]]);
                cost.update(vin[q], vin[q], c+1-inc[v]+inc[vin[q]]);
            }
        }
        cost.update(v, vout[i], c-inc[v]+nextinc[v]+1);
        // for (auto& x : cost.tree) debug(x);
        // for (int j = 0; j <= n; j++)
        //     debug(j, cost.get(vin[j])-inc[vin[j]]);
    }

    for (auto a : S) {
        cout << cost.get(vin[a])-inc[vin[a]] << " ";
    }
}
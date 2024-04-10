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

template<typename T>
int bs_index(const vector<T>& A, T x) {

    int a = 0, b = A.size()-1;
    while (a <= b) {
        int m = (a+b)/2;
        if (x > A[m])
            a = m+1;
        else
            b = m-1;
    }
    return a;
}

template<typename T>
struct fenwick {

    int length;
    vector<T> tree;

    fenwick(int s) {
        length = s+1;
        tree = vector<T>(length+1);
    }

    fenwick(vector<T>& v) {
        length = v.size()+1;
        tree = vector<T>(length+1);
        for (int i = 0; i < v.size(); i++)
            insert(i, v[i]);
    }

    // insert val at index i
    // to remove, just insert with negative val
    void update(int i, T val) {
        i++;
        while (i < length) {
            tree[i] += val;
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = 0;
        while (i > 0) {
            out += tree[i];
            i -= i & -i;
        }
        return out;
    }

    // sum over a..b, inclusive
    T query(int a, int b) {
        return prefix(b)-prefix(a-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    fin >> N;
    vector<array<ll, 2>> P(N);
    for (auto& x : P) fin >> x[0];
    for (auto& x : P) fin >> x[1];
    vector<array<ll, 2>> Q(N);
    for (int i = 0; i < N; i++) Q[i] = {P[i][1], P[i][0]};
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    // for (auto& x : Q) x = {x[1], x[0]};
    fenwick<ll> F(N), G(N);

    debug(Q);

    ll out = 0;
    for (int i = 0; i < N; i++) {
        int x = bs_index(Q, {P[i][1], inf_ull})-1;
        debug(i, x, P[i]);
        out += P[i][0]*G.prefix(x) - F.prefix(x);
        F.update(x, P[i][0]);
        G.update(x, 1);
    }

    cout << out << "\n";
}

/*
let x_a < x_b
d(a, b) = (v_a <= v_b) ? x_b-x_a : 0
*/
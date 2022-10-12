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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; fin >> N;
    vector<ll> M(N);
    for (auto& x : M) fin >> x;

    vector<ll> prefix(N), suffix(N);
    vector<ll> firstlower(N);

    firstlower[0] = -1;
    prefix[0] = M[0];
    for (int i = 1; i < N; i++) {
        int j = i-1;
        while (j >= 0 && M[j] > M[i])
            j = firstlower[j];
        firstlower[i] = j;
        prefix[i] = (i-j)*M[i] + (j >= 0 ? prefix[j] : 0);
    }

    firstlower[N-1] = N;
    suffix[N-1] = M[N-1];
    for (int i = N-2; i >= 0; i--) {
        int j = i+1;
        while (j < N && M[j] > M[i])
            j = firstlower[j];
        firstlower[i] = j;
        suffix[i] = (j-i)*M[i] + (j < N ? suffix[j] : 0);
    }

    ll best = -1, pivot;
    for (int i = 0; i < N; i++)
        if (prefix[i] + suffix[i] - M[i] > best) {
            best = prefix[i] + suffix[i] - M[i];
            pivot = i;
        }

    vector<ll> out(N);
    out[pivot] = M[pivot];
    for (int i = pivot-1; i >= 0; i--)
        out[i] = min(M[i], out[i+1]);
    for (int i = pivot+1; i < N; i++)
        out[i] = min(M[i], out[i-1]);

    for (auto& x : out) cout << x << " ";
    cout << "\n";
}

/*

1 1 2 5 1 3 3 4 4 3 1

*/
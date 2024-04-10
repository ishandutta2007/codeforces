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

#define avg(a, b) ((p[b]-p[a])/double(b-a))

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; fin >> n;
    vector<ll> v(n), b, p(n);
    for (auto& x : v) fin >> x;
    p[0] = v[0];
    for (ll i = 1; i < n; i++)
        p[i] = v[i]+p[i-1];
    for (ll i = 0; i < n; i++) {
        while (b.size() > 1 && avg(b.back(), i) < avg(b[b.size()-2], b.back()))
            b.pop_back();
        while (b.size() > 0 && avg(b.back(), i) < p[b.back()]/double(b.back()+1))
            b.pop_back();
        b.push_back(i);
    }
    ll j = 0;
    for (ll i = 0; i < b.size(); i++) {
        double a = i == 0 ? p[b[0]]/double(b[0]+1) : avg(b[i-1], b[i]);
        while (j <= b[i]) {
            cout << setprecision(18) << a << " ";
            j++;
        }
    }
}
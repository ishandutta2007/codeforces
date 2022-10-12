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
    int t; fin >> t;
    while (t--) {
        string a, b; fin >> a >> b;
        int n = a.size(), m = b.size();
        int dp[403][403];
        bool valid = false;
        for (int s = 0; s <= m; s++) {
            // debug(s);
            fill(&dp[0][0], &dp[0][0]+sizeof(dp)/sizeof(int), -inf);
            dp[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                char c = a[i-1];
                for (int j = 0; j <= s; j++) {
                    int v = dp[i-1][j];
                    if (v < 0) continue;
                    dp[i][j] = max(dp[i][j], v);
                    if (s+v < m && b[s+v] == c)
                        dp[i][j] = max(dp[i][j], v+1);
                    if (j < s && b[j] == c)
                        dp[i][j+1] = dp[i-1][j];
                }
            }
            // for (int i = 0; i <= n; i++)
            //     for (int j = 0; j <= s; j++)
            //         debug(i, j, dp[i][j]);
            if (dp[n][s] == m-s) {
                valid = true;
                cout << "YES\n";
                break;
            }
        }
        if (!valid)
            cout << "NO\n";
    }
}
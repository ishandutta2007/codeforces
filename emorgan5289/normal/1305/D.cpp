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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; fin >> n;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int a, b; fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cur = 1;
    while (1) {
        int children = 0, a = -1, b = -1, c = -1;

        for (int i : adj[cur])
            if (!visited[i])
                children++;
        if (children > 1) {
            b = cur;
            for (int i : adj[cur])
                if (!visited[i]) {
                    if (a == -1) a = i;
                    else if (c == -1) c = i;
                }
        } else {
            a = cur;
            for (int i : adj[cur])
                if (!visited[i]) {
                    b = i; break;
                }
            if (b == -1) { // win
                cout << "! " << cur << "\n";
                break;
            }
            for (int i : adj[b])
                if (!visited[i] && i != cur) {
                    c = i; break;
                }
            if (c == -1) { // win
                cout << "? " << a << " " << b << "\n";
                cout.flush();
                int r; fin >> r;
                if (r == -1) {
                    cout << "FAIL\n";
                    break;
                }
                cout << "! " << r << "\n";
                break;
            }
        }

        cout << "? " << a << " " << c << "\n";
        cout.flush();
        fin >> cur;
        if (cur == -1) {
            cout << "FAIL\n";
            break;
        }
        if (a != cur) visited[a] = 1;
        if (b != cur) visited[b] = 1;
        if (c != cur) visited[c] = 1;
    }
}
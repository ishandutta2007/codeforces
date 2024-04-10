#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("input.in");
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        vector<tuple<int, bool, int>> c(2*n);
        unordered_set<int> active;
        for (int i = 0; i < n; i++) {
            int a, b; fin >> a >> b;
            c[2*i] = {a, 0, i};
            c[2*i+1] = {b, 1, i};
        }
        sort(all(c));
        vector<int> in(n, 0), out(n, 0);
        int d = 0, m = 0, best = 0;
        bool disjointflag = true;
        for (auto& tup : c) {
            int i; bool r; tie(ignore, r, i) = tup;
            if (r) {
                m--;
                active.erase(active.find(i));
                if (m == 0) d++;
                if (m == 1) {
                    int j = *active.begin();
                    out[j]++;
                }
            } else {
                if (m == 1) {
                    int j = *active.begin();
                    if (out[j])
                        in[j]++;
                    best = max(best, in[j]);
                }
                m++;
                if (m > 1) disjointflag = false;
                active.insert(i);
            }
        }
        debug(d, best);
        if (disjointflag) best--;
        cout << d+best << "\n";
    }
}
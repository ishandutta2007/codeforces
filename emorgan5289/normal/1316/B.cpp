#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        string s; fin >> s;
        string m = s; int o = 1;
        for (int k = 1; k <= n; k++) {
            string u = s.substr(0, k-1);
            if ((n-k+1)%2 == 1) reverse(u.begin(), u.end());
            string q = s.substr(k-1, s.size()) + u;
            if (q < m) {
                m = q; o = k;
            }
        }
        cout << m << "\n" << o << "\n";
    }
}
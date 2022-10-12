#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
ifstream fin("../../input.in");
#define cin fin
#endif

template<typename T> inline T max(vector<T> X)
{ T r = *X.begin(); for (const auto& x : X) r = max(r, x); return r; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    string s; fin >> s;
    vector<int> c(n, 1), maxc(26, 0);
    for (int i = 0; i < n; i++) {
        for (int k = s[i]-'a'+1; k < 26; k++)
            c[i] = max(c[i], maxc[k]+1);
        maxc[s[i]-'a'] = max(maxc[s[i]-'a'], c[i]);
    }

    cout << max(maxc) << "\n";
    for (auto& x : c) cout << x << " ";
}
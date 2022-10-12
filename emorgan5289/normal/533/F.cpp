#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// Knuth-Morris-Pratt algorithm. Returns a list of all indices at which W appears in S.
// Runs in O(|S|+|W|) time.
template<typename it>
vector<int> kmp(it S_first, it S_last, it W_first, it W_last) {
    int n = S_last-S_first, m = W_last-W_first;
    vector<int> out, ptr(m+1);
    ptr[0] = -1;
    for (int i = 1, j = 0; i < m; i++, j++) {
        if (W_first[i] == W_first[j])
            ptr[i] = ptr[j];
        else {
            ptr[i] = j;
            do
                j = ptr[j];
            while (j >= 0 && W_first[i] != W_first[j]);
        }
        if (i == m-1) ptr[m] = j+1;
    }
    for (int i = 0, j = 0; i < n;) {
        if (W_first[j] == S_first[i]) {
            i++, j++;
            if (j == m) {
                out.push_back(i-j);
                j = ptr[j];
            }
        } else {
            j = ptr[j];
            if (j < 0) i++, j++;
        }
    }
    return out;
}

const int N = 2e5+5, A = 26;
int p[N], q[N], v[N][A];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    for (int i = 0; i < A; i++)
        for (int j = i; j < A; j++) {
            for (int k = 0; k < n; k++)
                p[k] = s[k]-'a' == i || s[k]-'a' == j ? s[k]-'a' : 27;
            for (int k = 0; k < m; k++) {
                if (t[k]-'a' == i) q[k] = j;
                else if (t[k]-'a' == j) q[k] = i;
                else q[k] = 27;
            }
            for (auto& k : kmp(p, p+n, q, q+m))
                v[k][i] = v[k][j] = 1;
        }
    vector<int> r;
    for (int i = 0; i < n-m+1; i++)
        if (accumulate(v[i], v[i]+A, 0) == A)
            r.pb(i+1);
    cout << r.size() << "\n";
    for (auto& i : r)
        cout << i << " ";
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

typedef unsigned long ulong;

/*
 *  Internal implementation of the SMAWK algorithm.
 */
template <typename T>
void _smawk(
        const vector<ulong>& rows,
        const vector<ulong>& cols,
        const function<T(ulong, ulong)>& lookup,
        vector<ulong>* result) {
    // Recursion base case
    if (rows.size() == 0) return;

    // ********************************
    // * REDUCE
    // ********************************

    vector<ulong> _cols;  // Stack of surviving columns
    for (ulong col : cols) {
        while (true) {
            if (_cols.size() == 0) break;
            ulong row = rows[_cols.size() - 1];
            if (lookup(row, col) >= lookup(row, _cols.back()))
                break;
            _cols.pop_back();
        }
        if (_cols.size() < rows.size())
            _cols.push_back(col);
    }

    // Call recursively on odd-indexed rows
    vector<ulong> odd_rows;
    for (ulong i = 1; i < rows.size(); i += 2) {
        odd_rows.push_back(rows[i]);
    }
    _smawk(odd_rows, _cols, lookup, result);

    unordered_map<ulong, ulong> col_idx_lookup;
    for (ulong idx = 0; idx < _cols.size(); ++idx) {
        col_idx_lookup[_cols[idx]] = idx;
    }

    // ********************************
    // * INTERPOLATE
    // ********************************

    // Fill-in even-indexed rows
    ulong start = 0;
    for (ulong r = 0; r < rows.size(); r += 2) {
        ulong row = rows[r];
        ulong stop = _cols.size() - 1;
        if (r < rows.size() - 1)
            stop = col_idx_lookup[(*result)[rows[r + 1]]];
        ulong argmin = _cols[start];
        T min = lookup(row, argmin);
        for (ulong c = start + 1; c <= stop; ++c) {
            T value = lookup(row, _cols[c]);
            if (c == start || value < min) {
                argmin = _cols[c];
                min = value;
            }
        }
        (*result)[row] = argmin;
        start = stop;
    }
}

/*
 *  Interface for the SMAWK algorithm, for finding the minimum value
 *  in each row of an implicitly-defined totally monotone matrix.
 */
template <typename T>
vector<ulong> smawk(
        const ulong num_rows,
        const ulong num_cols,
        const function<T(ulong, ulong)>& lookup) {
    vector<ulong> result;
    result.resize(num_rows);
    vector<ulong> rows(num_rows);
    iota(begin(rows), end(rows), 0);
    vector<ulong> cols(num_cols);
    iota(begin(cols), end(cols), 0);
    _smawk<T>(rows, cols, lookup, &result);
    return result;
}

int ans=INT_MAX;
int ask(ulong x, ulong y) {
    cout<<"? "<<x+1<<" "<<y+1<<endl;
    int ret; cin>>ret; ans=min(ans, ret); return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    ulong n, m; cin>>n>>m;
    if(n*m<=4*(n+m)) {rep(i, n) rep(j, m) ask(i, j);}
    else {auto t=smawk<int>(n, m, ask);}
    cout<<"! "<<ans<<endl;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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

#define int uint
int n, a, b;
int solve(int l, int r) {
    if((n+l-1)/l==(n+r-1)/r) {
        int seg=(n+l-1)/l;
        if(seg==1) return r-l+1;
        if(a/(seg-1)<(a+seg-1)/seg||b/(seg-1)<(b+seg-1)/seg) return 0;
        else {
            r=min(r, a/(seg-1)+b/(seg-1));
            l=max(l, (a+seg-1)/seg+(b+seg-1)/seg);
            return r>=l?r-l+1:0;
        }
    }
    else {
        int m=(l+r)/2;
        return solve(l, m)+solve(m+1, r);
    }
}

int32_t main() {
    scanf("%u%u", &a, &b); n=a+b;
    printf("%u\n", solve(1, n));
}
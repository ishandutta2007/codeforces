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

vector<pii> ans;

void match_four(int x, int y, int z, int t) {
    ans.eb(x, y);
    ans.eb(z, t);
    ans.eb(x, z);
    ans.eb(y, t);
}

void match(int l, int r) {
    if(r-l==3) {
        match_four(l, l+1, l+2, l+3);
    }
    else {
        int m=(l+r)/2;
        match(l, m);
        match(m+1, r);
        for(int i=0; i<m-l; i+=2) match_four(l+i, l+i+1, m+i+1, m+i+2);
    }
}

void solve(int n) {
    if(n==1) {
        cout<<"0\n";
        return;
    }
    else if(n<=3) {
        cout<<"1\n1 2\n";
        return;
    }
    else {
        int p=4;
        while(p<=n/2) p*=2;
        match(1, p);
        match(n-p+1, n);
        cout<<ans.size()<<endl;
        for(auto& it: ans) cout<<it.fi<<' '<<it.se<<endl;
    }
}

int32_t main() {
    fastio;
    int n; cin>>n; solve(n);
}
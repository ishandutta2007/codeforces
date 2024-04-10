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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int ask(array<int, 3>&& a) {
    cout<<"? "<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl;
    int ret; cin>>ret; return ret;
}

int rnd(int l, int r) {
    std::uniform_int_distribution<int> engine(l, r);
    return engine(rng);
}

array<int, 3> gen_rnd(int n) {
    array<int, 3> a;
    rep(i, 3) {
        a[i]=rnd(1, n);
        bool ok=0;
        while(!ok) {
            ok=1;
            rep(j, i) if(a[i]==a[j]) ok=0;
            if(!ok) a[i]=rnd(1, n);
        }
    }
    return a;
}

constexpr int EXTRA_ASKS = 420;
int32_t main() {
    ios_base::sync_with_stdio(0);
    int h; cin>>h;
    int n=(1<<h)-1;
    int occ[n+1]={0};
    rep(i, EXTRA_ASKS) {
        int p=ask(gen_rnd(n));
        occ[p]++;
    }
    int mx1=1, mx2=2; if(occ[1]<occ[2]) swap(mx1, mx2);
    for(int i=3; i<=n; i++) {
        if(occ[i]>occ[mx1]) mx2=mx1, mx1=i;
        else if(occ[i]>occ[mx2]) mx2=i;
    }
    rep1(i, n) if(i!=mx1&&i!=mx2) {
        if(ask(array<int, 3>{i, mx1, mx2})==i) {
            cout<<"! "<<i<<endl;
            return 0;
        }
    }
    assert(0);
}
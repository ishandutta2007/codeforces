#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define pcnt __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int a[200000];

int sz=450;
struct query {
    int l, r, idx;
    bool operator < (query other) const {return mp(mp(l/sz, r), l)<mp(mp(other.l/sz, other.r), other.l);}
};


vi occ(1000001, 0);
ll sum=0;

void add(int x) {
    occ[a[x]]++;
    sum+=a[x]*(2*occ[a[x]]-1LL);
}

void remove(int x) {
    occ[a[x]]--;
    sum-=a[x]*(2*occ[a[x]]+1LL);
}

void solve(vector<query> q) {
    sort(all(q));
    int l=0, r=-1;
    ll ans[q.size()];
    for(query it: q) {
        while(l>it.l) {l--; add(l);}
        while(r<it.r) {r++; add(r);}
        while(l<it.l) {remove(l); l++;}
        while(r>it.r) {remove(r); r--;}
        ans[it.idx]=sum;
    }
    for(ll it: ans) cout<<it<<'\n';
}

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    rep(i, n) cin>>a[i];
    vector<query> q(m); rep(i, m) {cin>>q[i].l>>q[i].r; q[i].l--; q[i].r--; q[i].idx=i;}
    solve(q);
}
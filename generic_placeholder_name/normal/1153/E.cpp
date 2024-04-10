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

bool query(int x1, int x2, int y1, int y2){
    cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    int resp; cin>>resp; return resp&1;
}

void answer(int x1, int y1, int x2, int y2) {
    cout<<"! "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    exit(0);
}

int32_t main() {
    int n; cin>>n;
    vi x, y;
    rep1(i, n) if(query(i, i, 1, n)) x.pb(i);
    if(!x.empty()) {
        assert(x.size()>=2);
        int l[]={1, 1}, r[]={n, n};
        rep(i, 2) while(l[i]<r[i]) {
            int m=(l[i]+r[i])/2;
            if(query(x[i], x[i], l[i], m)) r[i]=m;
            else l[i]=m+1;
        }
        answer(x[0], l[0], x[1], l[1]);
    }
    else {
        rep1(i, n) if(query(1, n, i, i)) y.pb(i);
        assert(y.size()>=2);
        int l=1, r=n;
        while(l<r) {
            int m=(l+r)/2;
            if(query(l, m, y[0], y[0])) r=m;
            else l=m+1;
        }
        answer(l, y[0], l, y[1]);
    }
}
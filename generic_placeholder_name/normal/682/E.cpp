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

using pt=pll;
#define x fi
#define y se

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0;
}

void make_convex_hull(vector<pt>& a) {
    //cp-algo graham's scan
    if (a.size()==1) return;
    sort(all(a));
    pt p1=a[0], p2=a.back();
    vector<pt> up, down;
    up.pb(p1); down.pb(p1);
    rep1(i, a.size()-1) {
        if (i==a.size()-1||cw(p1, a[i], p2)) {
            while (up.size()>=2&&!cw(up[up.size()-2], up[up.size()-1], a[i])) up.pop_back();
            up.pb(a[i]);
        }
        if (i==a.size()-1||ccw(p1, a[i], p2)) {
            while(down.size()>=2&&!ccw(down[down.size()-2], down[down.size()-1], a[i])) down.pop_back();
            down.pb(a[i]);
        }
    }
    a.clear();
    for (int i=0; i<up.size(); i++) a.pb(up[i]);
    for (int i=down.size()-2; i>0; i--) a.pb(down[i]);
}

ll area(pt a, pt b, pt c) {
    return abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));
}

tuple<pt, pt, pt> find_largest_rectangle(vector<pt>& a) {
    const int n=a.size();
    int A=0, B=1, C=2;
    int bA=A, bB=B, bC=C;
    while(1) {
        while(1) {
            while(area(a[A], a[B], a[C])<area(a[A], a[B], a[(C+1)%n])) C=(C+1)%n;
            if(area(a[A], a[B], a[C])<area(a[A], a[(B+1)%n], a[C])) B=(B+1)%n;
            else break;
        }
        if(area(a[A], a[B], a[C])>area(a[bA], a[bB], a[bC])) bA=A, bB=B, bC=C;
        A=(A+1)%n;
        if (A==B) B=(B+1)%n;
        if (B==C) C=(C+1)%n;
        if (A==0) break;
    }
    return make_tuple(a[bA], a[bB], a[bC]);
}

tuple<pt, pt, pt> refl(tuple<pt, pt, pt> a) {
    pt x, y, z;
    tie(x, y, z)=a;
    return make_tuple(mp(x.x+y.x-z.x, x.y+y.y-z.y), mp(x.x-y.x+z.x, x.y-y.y+z.y), mp(-x.x+y.x+z.x, -x.y+y.y+z.y));
}

int32_t main() {
    int n; ll S; cin>>n>>S;
    vector<pt> a(n); rep(i, n) cin>>a[i].x>>a[i].y;
    make_convex_hull(a);
    auto it=refl(find_largest_rectangle(a));
    pt x, y, z; tie(x, y, z)=it;
    cout<<x.fi<<' '<<x.se<<endl<<y.fi<<' '<<y.se<<endl<<z.fi<<' '<<z.se<<endl;
}
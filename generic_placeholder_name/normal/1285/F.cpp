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

//probably will TLE if not WA
//but it's the best I've got for now

constexpr int N=1e5+1;

struct Node {
    int sum;
    Node *l, *r;
    Node(): sum(0), l(nullptr), r(nullptr) {}
};

void add(Node* root, int pos, int val=1, int l=0, int r=N-1) {
    root->sum+=val;
    if(l==r) return;
    int m=(l+r)/2;
    if(pos<=m) {
        if(root->l==nullptr) root->l=new Node();
        add(root->l, pos, val, l, m);
    }
    else {
        if(root->r==nullptr) root->r=new Node();
        add(root->r, pos, val, m+1, r);
    }
}

int get(Node* root, int ql, int qr, int l=0, int r=N-1) {
    if (!root||l>r||ql>r||qr<l) return 0;
    if(ql<=l&&qr>=r) return root->sum;
    else {
        int m=(l+r)/2;
        return get(root->l, ql, qr, l, m)+get(root->r, ql, qr, m+1, r);
    }
}

int n; ll ans;
vi a(N), d[N];
bool vis[N];
int u[N];
Node* t[N];

int get_coprime(int l, int r, int x) {
    int ans=0;
    for(int y: d[x]) if(u[y]) ans+=u[y]*get(t[y], l, r);
    return ans;
}

void get_result() {
    rep(i, n) vis[a[i]]=1;
    for(int i=1; i<N; i++) {
        t[i]=new Node();
        for(int j=i; j<N; j+=i) {
            if(vis[j]) vis[i]=1;
            d[j].pb(i);
            if (i==1) u[i]=1;
            else if((i/d[i][1])%d[i][1]==0) u[i]=0;
            else u[i]=-u[i/d[i][1]];
        }
    }
    a.clear();
    rep1(i, N-1) if(vis[i]) ans=i, a.pb(i);
    n=a.size();
    if(a.size()>=2&&a[n-1]-a[n-2]==1) {ans=1LL*a[n-1]*a[n-2]; return;}
    rep(i, n) for(int x: d[a[i]]) add(t[x], i);
    vi idx(n); iota(all(idx), 0); shuffle(all(idx), rng);
    for(int i: idx) {
        if(ans/a[i]>=N) continue;
        int j=upper_bound(all(a), ans/a[i])-a.begin();
        if(j>=i) continue;
        if(get_coprime(j, i-1, a[i])==0) continue;
        for(int k=i; k>=j; k--) if(gcd(a[i], a[k])==1) {
            ans=1LL*a[i]*a[k];
            break;
        }
    }
}

int32_t main() {
    fastio;
    cin>>n; rep(i, n) cin>>a[i];
    get_result();
    cout<<ans<<endl;
}
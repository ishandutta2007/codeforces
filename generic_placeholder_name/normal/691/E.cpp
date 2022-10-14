

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
     
    const ll N=1e9+7;
     
    struct matrix {
        ll a[101][101]; int sz;
        void init(int n) {rep(i, n) rep(j, n) a[i][j]=0; sz=n;}
        ll* operator [] (int x) {return a[x];}
        const ll* operator [] (int x) const {return a[x];}
        friend matrix operator * (const matrix& a, const matrix& b) {
            matrix c;
            c.init(a.sz);
            rep(i, a.sz) rep(j, a.sz) rep(k, a.sz) (c[i][j]+=a[i][k]*b[k][j])%=N;
            return c;
        }
    };
     
    int32_t main() {
        fastio;
        int n; ll k; cin>>n>>k; k--;
        ll a[n]; rep(i, n) cin>>a[i];
        matrix src; src.init(n);
        rep(i, n) rep(j, n) if(pcnt(a[i]^a[j])%3==0) src[i][j]=1;
        matrix res; res.init(n); rep(i, n) res[i][i]=1;
        while(k) {
            if(k%2) res=res*src;
            src=src*src;
            k/=2;
        }
        ll ans=0;
        rep(i, n) rep(j, n) (ans+=res[i][j])%=N;
        cout<<ans;
    }
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
 
int32_t main() {
    //randomization ftw
    //so 180000*180000*2^10 doesn't get AC, but notice we can get damn close
    //so we just randomize to get most of them
    //and pray to fucking god that it's enough
    auto start = chrono::steady_clock::now();
    //clock
    constexpr int N=300001;
    int f[N+1];
    memset(f, 0, sizeof(f));
    for(int i=2; i*i<=N; i++) if(!f[i]) for(int j=i*i; j<=N; j+=i) if(!f[j]) f[j]=i;
    for(int i=1; i<=N; i++) if(!f[i]) f[i]=i;
    //sieve
    fastio;
    int n; cin>>n; vi a(n);
    rep(i, n) {
        int x, y=1; cin>>x;
        while(x>1) {
            const int p=f[x];
            y*=p;
            while(x%p==0) x/=p;
        }
        a[i]=y;
    }
    //rip out any exponents larger than one
    int s=0;
    rep(i, n) s=gcd(s, a[i]);
    if(s!=1) {
        cout<<"-1\n";
        return 0;
    }
    sort(all(a));
    //get a MIS
    bitset<N+1> vis;
    vi elim;
    for(int it: a) if(!vis[it]) {
        elim.pb(it);
        for(int i=it; i<=N; i+=it) vis[i]=1;
    }
    a=elim;
    n=a.size();
    //pray to RNGesus
    int ans=min(n, 10);
    auto end=chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::milliseconds>(end - start).count()<2969) {
        int cur=0, cnt=0;
        while(cnt<ans) {
            cnt++;
            cur=gcd(cur, a[rng()%n]);
            if(cur==1) ans=cnt;
        }
        end=chrono::steady_clock::now();
    }
    cout<<ans<<endl;
}
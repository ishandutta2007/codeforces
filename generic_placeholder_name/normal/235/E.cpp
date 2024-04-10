#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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

constexpr int N=2003;
bitset<N> cop[N];
int16_t p[N];
int8_t mu[N];

void init() {
    for(int i=0; i<N; i++) cop[i][1]=cop[1][i]=1;
    for(int i=2; i<N; i++) {
        for(int j=2; j<=i; j++) {
            cop[i][j]=cop[j][i]=cop[i-j][j];
        }
    }
    for(int i=2; i*i<N; i++) if(!p[i]) {
        for(int j=i*i; j<N; j+=i) if(!p[j]) p[j]=i;
    }
    for(int i=2; i<N; i++) if(!p[i]) p[i]=i;
    mu[1]=1;
    for(int i=2; i<N; i++) {
        if((i/p[i])%p[i]==0) mu[i]=0;
        else mu[i]=-mu[i/p[i]];
    }
}

int32_t main() {
    fastio;
    init();
    int a, b, c; cin>>a>>b>>c;
    if(b>c) swap(b, c);
    int ans=0;
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            if(cop[i][j]&&mu[j]) {
                int cur=(a/i)*mu[j];
                int db=b/j, dc=c/j;
                int mb=0, mc=0;
                for(int k=1; k<=db; k++) if(cop[i][k])mb+=db/k, mc+=dc/k;
                for(int k=db+1; k<=dc; k++) if(cop[i][k]) mc+=dc/k;
                ans+=cur*mb*mc;
            }
        }
    }
    cout<<(ans&((1<<30)-1))<<endl;
}
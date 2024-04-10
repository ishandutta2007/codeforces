#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

double get_rand(double l, double r) {
    uniform_real_distribution<double> engine(l, r);
    return engine(rng);
}

struct Solver {
    static constexpr double D=0.39;
    ll bal=1;
    int chain=0;
    
    int cnt=0;
    bool ask(ll x) {
        cnt++;
        //if(cnt>105) {while(1){}}
        cout<<"? "<<x<<endl;
        string ans; cin>>ans;
        if(ans=="Lucky!") return bal+=x, 1;
        else return bal-=x, 0;
    }
    
    void answer(ll x) {
        cout<<"! "<<x<<endl;
    }

    static constexpr int MID_T=4;
    static constexpr int CHAIN_T=3;
    ll get_mid(ll l, ll r) { //I think this is better (?)
        double DIV=2.*bal/(l+r);
        double R=D;
        if(DIV>MID_T) R+=min(0.02*pow(1.5, DIV/MID_T), 0.12);
        else if(chain>=CHAIN_T) R-=min(0.02*pow(2, 1.*chain/CHAIN_T), 0.11);
        R+=get_rand(-0.01, 0.01);
        R=min(R, 0.5);
        return max(ll(l+(r-l)*R), l+1);
    }

    void solve() {
        if(!ask(1)) return void(answer(0));
        ll p=2;
        ll l=-1, r=-1;
        while(p<=1e14) {
            if(ask(p)) p*=2;
            else {
                l=p/2, r=p-1;
                break;
            }
        }
        if(!~l) l=p/2, r=1e14;
        while(l<r) {
            ll m=get_mid(l, r);
            while(bal<m) ask(l);
            if(ask(m)) chain=0, l=m;
            else chain++, r=m-1;
        }
        answer(l);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    int T; cin>>T;
    while(T--) {
        Solver solver;
        solver.solve();
    }
}
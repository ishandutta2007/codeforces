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
    //fastio;
    int n; cin>>n;
    vi p(n); rep(i, n) cin>>p[i];
    auto try_mode = [&](int mode) {
        vi perfect(n); iota(all(perfect), 1);
        int s=0, e=0;
        vvi ans;
        vi a=p;
        auto change = [&](vi c) {
            //for(int x: c) cout<<x<<' '; cout<<endl;
            reverse(all(c));
            vi b(n);
            int idx=0, lst=n;
            for(int x: c) {
                for(int i=0; i<x; i++, idx++) {
                    b[idx]=a[lst-x+i];
                }
                lst-=x;
            }
            a=b;
            //for(int x: a) cout<<x<<' '; cout<<endl;
        };
        while(s+e<n-1) {
            vi ins;
            if(mode==1) {
                if(e) ins.pb(e);
                int tg=s+1;
                int cnt=0, cur=e;
                while(a[cur]!=tg) cur++, cnt++;
                if(cnt) ins.pb(cnt);
                ins.pb(n-s-cur);
                if(s) ins.pb(s);
                s++;
            }
            else {
                if(s) ins.pb(s);
                int tg=n-e;
                int cnt=0, cur=s;
                while(a[cur]!=tg) cur++, cnt++;
                if(cnt) ins.pb(cnt);
                ins.pb(n-e-cur);
                if(e) ins.pb(e);
                e++;
            }
            if(ins.size()>1) {
                change(ins);
                ans.pb(ins);
            }
            mode^=1;
        }
        if(a!=perfect) {
            int cnt=0;
            vi ins;
            rep(i, n) {
                if(i==0||a[i]==a[i-1]+1) cnt++;
                else {ins.pb(cnt); cnt=1;}
            }
            ins.pb(cnt);
            if(ins.size()>1) {
                change(ins);
                ans.pb(ins);
            }
        }
        if(a!=perfect) return;
        if(ans.size()>n) return;
        cout<<ans.size()<<endl;
        for(auto& v: ans) {
            cout<<v.size()<<' ';
            for(int x: v) cout<<x<<' ';
            cout<<endl;
        }
        exit(0);
    };
    try_mode(0);
    try_mode(1);
    assert(0);
}
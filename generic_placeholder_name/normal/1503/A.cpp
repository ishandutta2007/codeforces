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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        string s; cin>>s;
        int cnt[2]={0};
        rep(i, n) cnt[s[i]-'0']++;
        vb a(n), b(n);
        bool st=1;
        rep(i, n) {
            if(s[i]=='0') {
                if(st) a[i]=1, b[i]=0;
                else a[i]=0, b[i]=1;
                st^=1;
            }
            else {
                if(cnt[1]>0) a[i]=b[i]=1, cnt[1]-=2;
                else a[i]=b[i]=0;
            }
        }
        const auto check = [&n](const vb& s) -> bool {
            int st=0;
            rep(i, n) {
                if(s[i]) st++;
                else st--;
                if(st<0) return 0;
            }
            return st==0;
        };
        if(!check(a)||!check(b)) cout<<"NO\n";
        else {
            cout<<"YES\n";
            rep(i, n) cout<<(a[i]?'(':')'); cout<<endl;
            rep(i, n) cout<<(b[i]?'(':')'); cout<<endl;
        }
	}
}
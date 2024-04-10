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

vi Z(const string& s) {
    vi z(s.length(), 0); int l=0, r=0; z[0]=s.length();
    rep1(i, s.length()-1) {
        if(i<=r) z[i]=min(r-i+1, z[i-l]);
        while (i+z[i]<s.length()&&s[z[i]]==s[i+z[i]]) z[i]++;
        if (i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    return z;
}

int32_t main() {
    fastio;
    string s; cin>>s;
    vi pf=Z(s);
    int ans=0;
    vb sf(s.length()+1);
    rep(i, s.length()) if(i+pf[i]==s.length()) if(!sf[pf[i]]) ans++, sf[pf[i]]=1;
    vll in(s.length()+1, 0);
    rep(i, s.length()) in[pf[i]]++;
    for(int i=s.length()-1; i>=0; i--) in[i]+=in[i+1];
    cout<<ans<<endl;
    rep1(i, s.length()) if(sf[i]) cout<<i<<' '<<in[i]<<endl;
}
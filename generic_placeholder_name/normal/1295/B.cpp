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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int solve(int n, int x, string s) {
    int a[n+1]={0};
    rep(i, n) if(s[i]=='0') a[i+1]=a[i]+1; else a[i+1]=a[i]-1;
    if(a[n]==0) {
        rep(i, n+1) if(a[i]==x) return -1;
        return 0;
    }
    else {
        int ans=0;
        rep(i, n) if((x-a[i])%a[n]==0&&(x-a[i])/a[n]>=0) ans++;
        return ans;
    }
}

int32_t main(){
	fastio;
	int q; cin>>q; while(q--) {
        int n, x; string s; cin>>n>>x>>s;
        cout<<solve(n, x ,s)<<endl;
	}
}
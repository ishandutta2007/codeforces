#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

bool comp(string a, string b) {
    return a.length()>b.length()||(a.length()==b.length()&&a>=b);
}

string inc(string s) {
    string ans=s;
    bool c=1; int i=s.length()-1; 
    while(c==1) {
        if(ans[i]!='9') {
            ans[i]++; c=0;
        }
        else {
            ans[i]='0'; i--; c=1;
        }
    }
    return ans;
}

int32_t main() {
    fastio;
    int n, k; cin>>n>>k; string s; cin>>s;
        cout<<n<<endl;
        string f=s.substr(0, k);
        while(f.length()<n) f+=f[f.length()%k];
        if(comp(f, s)) cout<<f<<endl;
        else {
            f=s.substr(0, k);
            f=inc(f);
            while(f.length()<n) f+=f[f.length()%k];
            cout<<f<<endl;
        }
}
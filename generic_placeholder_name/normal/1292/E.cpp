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
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n";

string s;

void ask(string t) {
    cout<<"? "<<t<<endl; fflush(stdout);
    int sz; cin>>sz;
    assert(sz!=-1);
    while(sz--) {
        int pos; cin>>pos; pos--;
        rep(i, t.size()) s[pos+i]=t[i];
    }
}

void answer() {
    cout<<"! "<<s<<endl; fflush(stdout);
}

void solve_4() {
    s="xxxx";
    ask("OC");
    ask("CC");
    ask("HC");
    ask("HO");
    if(s[1]=='x'||s[2]=='x') ask("HH");
    for(int i=1; i<3; i++) if(s[i]=='x') s[i]='O';
    if(s[1]=='O'&&s[2]=='O') {
        ask("OOO");
        if(s[0]=='x') s[0]='C';
        if(s[3]=='x') s[3]='H';
    }
    else {
        if(s[0]=='x') {
            if(s[3]=='x') ask("O"+s.substr(1, 2));
            else ask("O"+s.substr(1, 3));
            if(s[3]=='x') ask("H"+s.substr(1, 2));
            else ask("H"+s.substr(1, 3));
            if(s[0]=='x') s[0]='C';
        }
        if(s[3]=='x') {
            ask(s.substr(0, 3)+"O");
            ask(s.substr(0, 3)+"H");
            if(s[3]=='x') s[3]='C';
        }
    }
    answer();
}

void solve_other(int n) {
    s=""; rep(i, n) s+='x';
    ask("OC");
    ask("CC");
    ask("HC");
    ask("HO");
    ask("HH");
    for(int i=1; i<n-1; i++) if(s[i]=='x') s[i]='O';
    if(s[0]=='x') {
        ask("C"+s.substr(1, n-2));
        if(s[0]=='x') s[0]='O';
    }
    if(s[n-1]=='x') {
        ask(s.substr(1, n-2)+"H");
        if(s[n-1]=='x') s[n-1]='O';
    }
    answer();
}

void solve(int n) {
    if(n==4) solve_4();
    else solve_other(n);
    int res; cin>>res; assert(res==1);
}

int32_t main() {
    int q; cin>>q; while(q--) {
        int n; cin>>n;
        solve(n);
    }
}
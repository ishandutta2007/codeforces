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

const int K=26; //max size
int conv(char& x) {return x-'a';} //char to int converter

template<int K, int op(char&)> //templating
struct Vertex {
    int next[K]; //children
    bool leaf=false; //leaf node
    int p=-1; char ch; //parent; current vertex char
    int link=-1, slink=-1; /*link, suffix link*/ int go[K]; //suffix with next character
    int e=0;
    Vertex(int p=-1, char ch='#'): p(p), ch(ch) { //fill shit
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

template<int K, int op(char&)>
struct Trie { //wrapper for trie
    vector<Vertex<K, op>> trie; int n=0;
    void add(const string& s, int id) { //just adding
        int v=0;
        for(char ch: s) {
            int c=op(ch);
            if(trie[v].next[c]==-1) { //if not present then add
                trie[v].next[c]=trie.size();
                trie.emplace_back(v, ch);
            }
            v=trie[v].next[c];
        }
        trie[v].leaf=true;
        trie[v].e++;
    }
    Trie() {trie=vector<Vertex<K, op>>(1);}
    Trie(vector<string>& s) {trie=vector<Vertex<K, op>>(1); for(string& it: s) add(it, n++);}
    int go(int v, char ch);
    int get_link(int v) { //get closest suffix
        if(trie[v].link==-1) { //memoize
            if(v==0||trie[v].p==0) trie[v].link=0; //case 0
            else trie[v].link=go(get_link(trie[v].p), trie[v].ch); //goto link of parent which also contains this character
        }
        return trie[v].link;
    }
    int get_suff_link(int v) { //get number of strings that end at i
        if(trie[v].slink==-1) {
            if(v==0) trie[v].slink=0;
            else trie[v].slink=get_suff_link(get_link(v))+trie[v].e;
        }
        return trie[v].slink;
    }
};

template<int K, int op(char&)>
int Trie<K, op>::go(int v, char ch) {
    int c=op(ch);
    //modding this took longer than expected
    if(trie[v].go[c]==-1) {
        if(trie[v].next[c]!=-1) trie[v].go[c]=trie[v].next[c]; //if has next then goto next
        else trie[v].go[c]=v==0?0:go(get_link(v), ch); //if v=0 then abort; else just goto link until satisfied
    }
    return trie[v].go[c];
}

template<int K, int op(char&)>
struct Aho_Corasick { //perfunctory
    Trie<K, op> t;
    Aho_Corasick(Trie<K, op> t): t(t) {}
    Aho_Corasick(vector<string>& vt): t(Trie<K, op>(vt)) {}
    const vi get(const string& s) {
        vi res(s.length(), 0);
        int v=0;
        rep(i, s.length()) {
            v=t.go(v, s[i]);
            res[i]=t.get_suff_link(v);
        }
        return res;
    }
};

int32_t main() {
    //honestly young buffalo as shit
    //why is this even
    fastio;
    string s; cin>>s;
    int n; cin>>n;
    vector<string> t(n); rep(i, n) cin>>t[i];
    n=s.length();
    Aho_Corasick<K, conv> A(t);
    n=s.length();
    vi en=A.get(s);
    for(auto& it: t) reverse(all(it)); reverse(all(s));
    Aho_Corasick<K, conv> R(t);
    vi st=R.get(s); reverse(all(st));
    ll ans=0;
    rep(i, n-1) ans+=1LL*en[i]*st[i+1];
    cout<<ans<<endl;
}
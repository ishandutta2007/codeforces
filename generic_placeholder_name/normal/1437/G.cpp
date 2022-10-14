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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

const int K=26; //max size
int conv(char& x) {return x-'a';} //char to int converter

template<int K, int op(char&)> //templating
struct Vertex {
    int next[K]; //children
    bool leaf=false; //leaf node
    int p=-1; char ch; //parent; current vertex char
    int link=-1, slink=-1; /*link, suffix link*/ int go[K]; //suffix with next character
    multiset<int, greater<int>> val;
    Vertex(int p=-1, char ch='#'): p(p), ch(ch) { //fill shit
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

template<int K, int op(char&)>
struct Trie { //wrapper for trie
    vector<Vertex<K, op>> trie; int n=0;
    vector<int> pos, cur;
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
        trie[v].val.insert(0); //push index
        if(pos.size()<=id) pos.resize(id+1); pos[id]=v;
        if(cur.size()<=id) cur.resize(id+1); cur[id]=0;
    }
    void upd(int p, int v) {
        trie[pos[p]].val.erase(trie[pos[p]].val.find(cur[p]));
        cur[p]=v;
        trie[pos[p]].val.insert(cur[p]);
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
    int get_suff_link(int v) { //get closest leaf suffix
        if(trie[v].slink==-1) { //similar to above
            if(get_link(v)==0||trie[get_link(v)].leaf) trie[v].slink=get_link(v);
            else trie[v].slink=get_suff_link(get_link(v)); //basic dp
        }
        return trie[v].slink;
    }
};

template<int K, int op(char&)>
int Trie<K, op>::go(int v, char ch) {
    int c=op(ch);
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
    inline void upd(int idx, int val) {
        t.upd(idx, val);
    }
    const int get(string s) { //return a vector of pairs; 1st element is index at end of collision, 2nd is index of colliding string
        int res=-1;
        cc_hash_table<int, bool> vis;
        int v=0;
        rep(i, s.length()) {
            v=t.go(v, s[i]);
            int _v=v;
            while(_v!=0&&!vis[_v]) {
                vis[_v]=1;
                if(t.trie[_v].leaf) res=max(res, *t.trie[_v].val.begin());
                _v=t.get_suff_link(_v);
            }
        }
        return res;
    }
};
using AC = Aho_Corasick<K, conv>;

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    vector<string> v(n);
    rep(i, n) cin>>v[i];
    AC t(v);
    while(q--) {
        int type; cin>>type;
        if(type==1) {
            int p, v; cin>>p>>v;
            t.upd(--p, v);
        }
        else {
            string s; cin>>s;
            cout<<t.get(s)<<endl;
        }
    }
}
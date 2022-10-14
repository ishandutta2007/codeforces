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

const int K=10; //max size
int conv(char& x) {return x-'0';} //char to int converter

template<int K, int op(char&)> //templating
struct Vertex {
    int next[K]; //children
    bool leaf=false; //leaf node
    int p=-1; char ch; //parent; current vertex char
    int link=-1; //no need for slink, all same length
    int go[K]; //suffix with next character
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
    }
    Trie() {trie=vector<Vertex<K, op>>(1);}
    Trie(vector<string>& s) {trie=vector<Vertex<K, op>>(1); for(string& it: s) add(it, n++);}
    Vertex<K, op>& operator [] (int x) {return trie[x];}
    const Vertex<K, op>& operator [] (int x) const {return trie[x];}
    const int size() const {return trie.size();}
    int go(int v, char ch);
    int get_link(int v) { //get closest suffix
        if(trie[v].link==-1) { //memoize
            if(v==0||trie[v].p==0) trie[v].link=0; //case 0
            else trie[v].link=go(get_link(trie[v].p), trie[v].ch); //goto link of parent which also contains this character
        }
        return trie[v].link;
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

constexpr int MOD=1e9+7;
template<typename T, typename _T>
void add(T& a, _T b) {a+=b; if(a>=MOD) a-=MOD;}

template<int K, int op(char&)>
struct Aho_Corasick { //perfunctory
    Trie<K, op> t;
    Aho_Corasick(Trie<K, op> t): t(t) {}
    Aho_Corasick(vector<string>& vt): t(Trie<K, op>(vt)) {}
    int dp(string s) {
        int n=s.size(), m=t.size();
        int pw[n]; pw[n-1]=1;
        for(int i=n-2; ~i; i--) pw[i]=(pw[i+1]*10LL)%MOD;
        int rem[n]; rem[n-1]=1; rem[n-2]=s[n-1]-'0';
        for(int i=n-3; ~i; i--) rem[i]=(rem[i+1]+pw[i+1]*1LL*(s[i+1]-'0'))%MOD;
        rep(i, n-1) add(rem[i], 1);
        int dp[2][m];
        memset(dp, 0, sizeof(dp));
        int ans=0;
        int cur=0;
        bool max_chk=0;
        rep(i, n) {
            rep(j, m) if(!t[j].leaf) {
                for(char k='0'; k<='9'; k++) {
                    add(dp[1][t.go(j, k)], dp[0][j]);
                }
            }
            if(!max_chk) {
                for(char k='0'; k<s[i]; k++) {
                    add(dp[1][t.go(cur, k)], 1);
                }
                cur=t.go(cur, s[i]);
                if(t[cur].leaf) {
                    max_chk=1;
                    add(ans, rem[i]);
                }
            }
            rep(j, m) if(t[j].leaf) add(ans, (dp[1][j]*1LL*pw[i])%MOD);
            memcpy(dp[0], dp[1], sizeof(dp[0]));
            memset(dp[1], 0, sizeof(dp[1]));
        }
        return ans;
    }
    bool has(string s) {
        int v=0;
        rep(i, s.length()) {
            v=t.go(v, s[i]);
            if(t[v].leaf) return 1;
        }
        return 0;
    }
};

typedef Aho_Corasick<K, conv> AC;

int32_t main(){
    fastio;
    string s; cin>>s;
    string a, b; cin>>a>>b;
    int n=s.size(), d=a.size()/2;
    vector<string> t;
    rep(i, n-d+1) t.pb(s.substr(i, d));
    AC ac(t);
    cout<<((ac.dp(b)-ac.dp(a)+ac.has(a))%MOD+MOD)%MOD<<endl;
}
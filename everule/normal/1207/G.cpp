#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
template<typename T>
struct segment_tree {
    int n;
    vector<T> segtree;
    function<T(const T&,const T&)> join;
    T base = T();
    segment_tree(int n, function<T(const T&,const T&)> join, T base = T()) : n(n), join(join), base(base){
        segtree.resize(n << 1, base);
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            segtree[i] = join(segtree[(i << 1)], segtree[(i << 1) | 1]);
        }
    }
    segment_tree(vector<T> seq, function<T(const T&,const T&)> join, T base = T()) : n(seq.size()), join(join), base(base){
        segtree.resize(n << 1, base);
        for (int i = 0; i < n; i++) {
            segtree[n + i] = seq[i];
        }
        build();
    }
    void calc(int pos){
        pos >>= 1;
        while (pos) {
            segtree[pos] = join(segtree[pos << 1], segtree[(pos << 1) | 1]);
            pos >>= 1;
        }
    }
    void set(int pos, T val){
        pos+=n;
        segtree[pos] = val;
        calc(pos);
    }
    void increment(int pos, T val){
        pos+=n;
        segtree[pos] = join(segtree[pos], val);
        calc(pos);
    }
    T query(int l, int r) {
        T ansl = base;
        T ansr = base;
        l += n;
        r += n + 1;
        while (l < r) {
            if (l & 1) {
                ansl = join(ansl, segtree[l++]);
            }
            if (r & 1) {
                ansr = join(segtree[--r], ansr);
            }
            l >>= 1;
            r >>= 1;
        }
        return join(ansl, ansr);
    }
};
const int AL = 26;
struct aho_corasick{
    struct node{
        int p = 0;
        array<int, AL> nx;
        array<int, AL> kmp;
        int link = -1;
        char ch;
        node(char ch) : ch(ch){
            fill(nx.begin(), nx.end(), -1);
            fill(kmp.begin(), kmp.end(), -1);
        }
        int& operator[](char c){
            return nx[c-'a'];
        }
        int& operator()(char c){
            return kmp[c-'a'];
        }
    };
    vector<node> trie;
    aho_corasick() : trie(1, '!') {
 
    }
    void add_string(const string &s){
        int cr = 0;
        for(auto &c : s){
            if(trie[cr][c] == -1){
                trie[cr][c] = trie.size();
                trie.emplace_back(c);
                trie.back().p = cr;
            }
            cr = trie[cr][c];
        }
    }
    int go(int x, char c = '-'){
        if(c == '-'){
            if(trie[x].link != -1) return trie[x].link;
            if(x == 0 || trie[x].p == 0) trie[x].link = 0;
            else trie[x].link = go(go(trie[x].p), trie[x].ch);
            go(trie[x].link);
            return trie[x].link;
        }
        if(trie[x](c) != -1) return trie[x](c);
        if(trie[x][c] != -1) return trie[x](c) = trie[x][c];
        if(x == 0) return 0;
        return trie[x](c) = go(go(x), c);
    }
    void build(){
        for(int i=0;i<trie.size();i++){
            go(i);
        }
    }
    int find(string s){
        int cr = 0;
        for(auto &c : s) cr = go(cr, c);
        return cr;
    }
    int size(){
        return trie.size();
    }
};
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<char> chr(n);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t == 1){
            char c;
            cin>>c;
            chr[i] = c;
        }
        else{
            int j;
            char c;
            cin>>j>>c;
            --j;
            adj[j].push_back(i);
            chr[i] = c;
        }
    }
    aho_corasick ac;
    vector<vector<pair<string,int>>> qry(n);
    int m;
    cin>>m;
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        int j;
        string t;
        cin>>j>>t;
        --j;
        qry[j].emplace_back(t, i);
        ac.add_string(t);
    }
    int N = ac.size();
    vector<vector<int>> tadj(N);
    for(int i=1;i<N;i++){
        int p = ac.go(i);
        tadj[p].push_back(i);
    }
    vector<int> tin(N);
    vector<int> tout(N);
    [&](){
        int t = 0;
        function<void(int)> dfs = [&](int u){
            tin[u] = t++;
            for(auto &x : tadj[u]) dfs(x);
            tout[u] = t - 1;
        };
        dfs(0);
    }();
    segment_tree<int> st(N, [&](int x,int y){
        return x + y;
    }, 0);
    vector<bool> vis(n);
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        function<void(int,int)> dfs = [&](int u,int pos){
            vis[u] = 1;
            st.increment(tin[pos], 1);
            for(const auto &[t,idx] : qry[u]){
                int p = ac.find(t);
                ans[idx] = st.query(tin[p], tout[p]);
            }
            for(auto &c : adj[u]) dfs(c, ac.go(pos, chr[c]));
            st.increment(tin[pos], -1);
        };
        dfs(i, ac.go(0, chr[i]));
    }
    for(int i=0;i<m;i++) cout<<ans[i]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
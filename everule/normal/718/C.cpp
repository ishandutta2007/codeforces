#include <bits/stdc++.h>
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
/*
struct matrix{
    vector<vector<ll>> mat;
    matrix(int n, int m){
        mat.resize(n, vector<ll>(m));
    }
    
    matrix operator*=(matrix a){
        assert(mat[0].size() == a.size());
        matrix ans(mat.size(), a[0].size());
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<a[0].size();j++){
                for(int k=0;k<a.size();k++){
                    ans[i][j] += mat[i][k] * a[k][j];
                    ans[i][j] %= p;
                }
            }
        }
        return *this = ans;
    }
    matrix operator+=(matrix a){
        assert(mat.size() == a.size());
        assert(mat[0].size() == a.size());
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j] += a[i][j];
            }
        }
        return *this;
    }
    matrix operator-=(matrix a){
        assert(mat.size() == a.size());
        assert(mat[0].size() == a.size());
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j] -= a[i][j];
            }
        }
        return *this;
    }
    matrix operator+(matrix a){return matrix(*this) += a;}
    matrix operator-(matrix a){return matrix(*this) -= a;}
    matrix operator*(matrix a){return matrix(*this) *= a;}
    matrix pow(int pw){
        assert(mat.size() == mat[0].size());
        matrix ans = matrix::identity(mat.size());
        matrix base = *this;
        while(pw){
            if(pw & 1){
                ans *= base;
            }
            base *= base;
            pw>>=1;
        }
        return ans;
    }
    int size(){
        return mat.size();
    }
    vector<ll>& operator[](int x){
        return mat[x];
    }
    static matrix identity(int n){
        matrix ans(n, n);
        for(int i=0;i<n;i++){
            ans[i][i] = 1;
        }
        return ans;
    }
};
*/

const int p = 1e9 + 7;
template<int n, int m>
struct matrix{
    array<array<ll, m>, n> mat;
    matrix(){
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) mat[i][j] = 0;
    }
    matrix operator*=(matrix<m, m> a){
        matrix<m, m> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    ans[i][j] += mat[i][k] * a[k][j];
                    ans[i][j] %= p;
                }
            }
        }
        return *this = ans;
    }
    matrix operator+=(matrix a){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j] += a[i][j];
                if(mat[i][j] >= p) mat[i][j] -= p;
            }
        }
        return *this;
    }
    matrix operator-=(matrix a){
        assert(mat.size() == a.size());
        assert(mat[0].size() == a.size());
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j] -= a[i][j];
                if(mat[i][j] < 0) mat[i][j] += p;
            }
        }
        return *this;
    }
    matrix operator+(matrix a){return matrix(*this) += a;}
    matrix operator-(matrix a){return matrix(*this) -= a;}
    template<int l>
    matrix<n, l> operator*(matrix<m, l> a){
        matrix<n, l> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                for(int k=0;k<m;k++){
                    ans[i][j] += mat[i][k] * a[k][j];
                    ans[i][j] %= p;
                }
            }
        }
        return ans;
    }
    matrix pow(int pw){
        assert(n == m);
        matrix ans = matrix::identity();
        matrix base = *this;
        while(pw){
            if(pw & 1){
                ans *= base;
            }
            base *= base;
            pw >>= 1;
        }
        return ans;
    }
    int size(){
        return mat.size();
    }
    array<ll, m>& operator[](int x){
        return mat[x];
    }
    static matrix identity(){
        matrix ans;
        for(int i=0;i<n;i++){
            ans[i][i] = 1;
        }
        return ans;
    }
};
const int AL = 26;
struct aho_corasick{
    struct node{
        int p = 0;
        array<int, AL> nx;
        array<int, AL> kmp;
        int link = -1;
        int val = 0;
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
    aho_corasick() : trie(1, '!') {}
    void add_string(const string &s,int a){
        int cr = 0;
        for(auto &c : s){
            if(trie[cr][c] == -1){
                trie[cr][c] = trie.size();
                trie.emplace_back(c);
                trie.back().p = cr;
            }
            cr = trie[cr][c];
        }
        trie[cr].val += a;
    }
    int go(int x, char c = '!'){
        if(c == '!'){
            if(trie[x].link != -1) return trie[x].link;
            if(x == 0 || trie[x].p == 0) trie[x].link = 0;
            else trie[x].link = go(go(trie[x].p), trie[x].ch);
            go(trie[x].link);
            trie[x].val += trie[trie[x].link].val;
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
        /*for(int i=0;i<trie.size();i++){
            cout<<trie[i].link<<" "<<trie[i].val<<"\n";
        }
        cout<<"\n";*/
    }
    int getpos(string s){
        int cr = 0;
        for(auto &c : s) cr = go(cr, c);
        return cr;
    }
};
template<typename T, typename U>
struct lazy_segment_tree{
    int n;
    int H;
    T base;
    vector<T> segtree;
    vector<U> lazytree;
    vector<bool> isempty;
    function<T(const T&, const T&)> join;
    function<T(int, const U&, const T&)> assign;
    function<U(const U&,const U&)> lazyassign;

    lazy_segment_tree(vector<T> &seq, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base){
        n = seq.size();
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i]=seq[i];
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }
    void calc(int pos, int h){
        segtree[pos]=join(segtree[(pos<<1)],segtree[(pos<<1)|1]);
        if(!isempty[pos]){
            segtree[pos]=assign(h,lazytree[pos],segtree[pos]);
        }
    }
    void apply(int pos, U value, int h){
        segtree[pos]=assign(h, value, segtree[pos]);
        if(pos<n){
            if(!isempty[pos]){
                lazytree[pos]=lazyassign(value, lazytree[pos]);
            }
            else{
                lazytree[pos] = value;
            }
            isempty[pos]=0;
        }
    }
    void updatenode(int pos){
        int h=0;
        pos+=n;
        while(pos>1){
            h++;
            pos>>=1;
            calc(pos, h);
        }
    }
    void push(int pos){
        int h=H;
        for(pos+=n;h;--h){
            int x=(pos>>h);
            if(!isempty[x]){
                apply((x<<1), lazytree[x], h-1);
                apply((x<<1)|1, lazytree[x], h-1);
                isempty[x]=1;
            }
        }
    }
    void updaterange(int l, int r, U value){
        push(l);
        push(r);
        int k=0;
        int l0=l, r0=r;
        for(l+=n, r+=n+1;l<r;l>>=1, r>>=1, k++){
            if(l&1){
                apply(l++, value, k);
            }
            if(r&1){
                apply(--r, value,k);
            }
        }
        updatenode(l0);
        updatenode(r0);
    }
    T query(int l, int r){
        push(l);
        push(r);
        T ansl=base;
        T ansr=base;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1){
                ansl=join(ansl, segtree[l++]);
            }        
            if(r&1){
                ansr=join(segtree[--r], ansr);
            }
        }
        return join(ansl,ansr);
    }
};
void solve(){
    matrix<2, 2> main;
    main.mat[0] = array<ll, 2>({0, 1});
    main.mat[1] = array<ll, 2>({1, 1});
    int n,m;
    cin>>n>>m;
    vector<matrix<2, 2>> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i] = main.pow(x);
    }
    lazy_segment_tree<matrix<2, 2>, matrix<2, 2>> lst(a, [&](matrix<2, 2> l, matrix<2, 2> r){
        return l + r;
    }, [&](int k, matrix<2, 2> u, matrix<2, 2> v){
        return u * v;
    }, [&](matrix<2, 2> u1, matrix<2, 2> u2){
        return u1 * u2;
    }, matrix<2, 2>::identity());
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(t == 1){
            int l,r,x;
            cin>>l>>r>>x;
            --l;--r;
            lst.updaterange(l, r, main.pow(x));
        }
        else{
            int l,r;
            cin>>l>>r;
            --l;--r;
            cout<<lst.query(l, r)[0][1]<<"\n";
        }
    }
}
//hearth
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
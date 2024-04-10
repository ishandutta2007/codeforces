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
const int INF = 1e9;
const ll INFLL = 2e18;
struct matrix{
    vector<vector<ll>> mat;
    matrix(int n, int m){
        mat.resize(n,vector<ll>(m, -INFLL));
    }
    matrix operator*(matrix a){
        matrix ans(this->mat.size(),a.mat[0].size());
        for(int i=0;i<this->mat.size();i++){
            for(int j=0;j<a.mat[0].size();j++){
                for(int k=0;k<a.mat.size();k++){
                    ans.mat[i][j]=max(ans.mat[i][j], mat[i][k] + a.mat[k][j]);
                }
            }
        }
        return ans;
    }
    vector<ll>& operator[](int x){
        return mat[x];
    }
};
matrix matpower(matrix base,ll power){
    matrix ans = base;
    --power;
    while(power){
        if(power & 1){
            ans=ans*base;
        }
        base=base*base;
        power>>=1;
    }
    return ans;
}
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
    aho_corasick() : trie(1, '!') {

    }
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
void solve(){
    int n;
    cin>>n;
    ll l;
    cin>>l;
    vector<int> a(n);
    cin>>a;
    vector<string> s(n);
    cin>>s;
    aho_corasick aho;
    for(int i=0;i<n;i++) aho.add_string(s[i], a[i]);
    int x = aho.trie.size();
    matrix base(1,x);
    matrix tr(x,x);
    base[0][0] = 0;
    aho.build();
    for(int i=0;i<x;i++){
        for(char c='a';c<='z';c++){
            int y = aho.go(i,c);
            tr[i][y] = aho.trie[y].val;
        }
    }
    matrix ans = base * matpower(tr, l);
    cout<<*max_element(ans[0].begin(), ans[0].end())<<"\n";
}
//hearth
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
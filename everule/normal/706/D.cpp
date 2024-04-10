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
const int bits = 30;
//template<int bits>
struct XorTrie{
    struct Trienode{
        array<int, 2> child = {-1, -1};
        int cnt = 0;
    };
    vector<Trienode> trie;
    XorTrie(){
        trie.emplace_back();
    }
    void add(int x){
        int curr = 0;
        ++trie[curr].cnt;
        for(int i=bits;i>=0;--i){
            bool ch = (x>>i)&1;
            if(trie[curr].child[ch] == -1){
                trie[curr].child[ch] = trie.size();
                trie.emplace_back();
            }
            curr = trie[curr].child[ch];
            ++trie[curr].cnt;
        }
    }
    void remove(int x){
        int curr = 0;
        --trie[curr].cnt;
        for(int i=bits;i>=0;--i){
            bool ch = (x>>i)&1;
            curr = trie[curr].child[ch];
            --trie[curr].cnt;
        }
    }
    int getmax(int x){
        int curr = 0;
        int ans = 0;
        for(int i=bits;i>=0;--i){
            bool ch = ((~x>>i)&1);
            int x = trie[curr].child[ch];
            if(x != -1 && trie[x].cnt != 0){
                curr = x;
                ans |= (1<<i);
            }
            else{
                curr = trie[curr].child[!ch];
            }
        }
        return ans;
    }
};
void solve(){
    XorTrie trie;
    trie.add(0);
    int q;
    cin>>q;
    while(q--){
        char t;
        cin>>t;
        if(t == '+'){
            int x;
            cin>>x;
            trie.add(x);
        }
        if(t == '-'){
            int x;
            cin>>x;
            trie.remove(x);
        }
        if(t == '?'){
            int x;
            cin>>x;
            cout<<trie.getmax(x)<<"\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
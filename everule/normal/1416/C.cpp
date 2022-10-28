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
const int AL = 2;
struct trienode{
    trienode* one;
    trienode* zero;
    int count;
    trienode(){
        one = NULL;
        zero = NULL;
        count = 0;
    }
};
const int lgA = 32;
vector<ll> inv0(lgA);
vector<ll> inv1(lgA);
struct Trie{
    trienode* begin;
    Trie(){
        begin = new trienode;
    }
    void add(ll x){
        trienode* curr = begin;
        ++curr->count;
        for(int i=lgA-1;i>=0;--i){
            if(x&(1ll<<i)){
                if(curr->zero) inv1[i]+=curr->zero->count;
                if(curr->one){
                    curr = curr->one;
                    ++curr->count;
                    continue;
                }
                curr->one = new trienode;
                curr=curr->one;
                ++curr->count;
                continue;
            }
            if(curr->one) inv0[i]+=curr->one->count;
            if(curr->zero){
                curr=curr->zero;
                ++curr->count;
                continue;
            }
            curr->zero = new trienode;
            curr = curr->zero;
            ++curr->count;
        }
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    Trie trie; 
    for(const auto &x : seq) trie.add(x);
    ll x = 0;
    ll b = 0;
    for(int i=lgA-1;i>=0;--i){
        if(inv1[i]<inv0[i]){
            x|=(1ll<<i);
        }
        b+=min(inv0[i], inv1[i]);
    }
    cout<<b<<" "<<x<<"\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
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
struct Trie{
    struct Trienode{
        array<Trienode*, 2> child = {NULL, NULL};
    };
    Trienode base;
    void add(int num){
        Trienode *curr = &base;
        for(int bit = bits ; bit>=0 ; --bit){
            int ch = ((num>>bit)&1);
            if(curr->child[ch]){
                curr = curr->child[ch];
            }
            else{
                curr->child[ch] = new Trienode();
                curr = curr->child[ch];
            }
        }
    }
    int solve(Trienode* x){
        if(x->child[0] == NULL && x->child[1] == NULL){
            return 1;
        }
        int ans = 0;
        if(x->child[0]){
            ans = max(ans, solve(x->child[0]) + (x->child[1] != NULL));
        }
        if(x->child[1]){
            ans = max(ans, solve(x->child[1]) + (x->child[0] != NULL));
        }
        return ans;
    }
    int solve(){
        return solve(&base);
    }
};
void solve(){
    int n;
    cin>>n;
    Trie solver;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        solver.add(x);
    }
    cout<<n - solver.solve()<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
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

struct XorBasis{
    private:
    vector<ll> basis;
    int lg;
    int sz = 0;

    public:
    XorBasis(int lg) : lg(lg){
        basis.resize(lg);
    }
    void add(ll x){
        if(x >= (1ll<<lg)) return;
        for(int i=0;i<lg;i++){
            if(~x&(1ll<<i)) continue;
            if(!basis[i]){
                basis[i] = x;
                ++sz;
            }
            x^=basis[i];
        }
    }
    bool contains(ll x){
        for(int i=0;i<lg;i++){
            if(~x&(1ll<<i)) continue;
            if(!basis[i]){
                return false;
            }
            x^=basis[i];
        }
        return true;
    }
    int size(){
        return sz;
    }
    const vector<ll>::iterator begin(){
        return basis.begin();
    }
    const vector<ll>::iterator end(){
        return basis.end();
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    int x = 0;
    for(int i=1;i<20;i++){
        XorBasis basis(i);
        for(const auto &x : seq) basis.add(x);
        if(basis.size()==i){
            x = i;
        }
    }
    XorBasis basis(x);
    vector<int> ele;
    ele.reserve(x);
    for(const auto &s : seq){
        if(s<(1ll<<x) && !basis.contains(s)){
            ele.pb(s);
            basis.add(s);
        }
    }
    vector<int> ans;
    ans.reserve(1<<x);
    vector<bool> vis(1<<x);

    function<void(int)> dfs = [&](int u){
        ans.pb(u);
        vis[u] = 1;
        for(const auto &x : ele){
            if(!vis[x^u]){
                dfs(x^u);
                return;
            }
        }
    };
    dfs(0);
    cout<<x<<"\n";
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
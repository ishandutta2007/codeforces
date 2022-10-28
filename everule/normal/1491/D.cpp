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
void solve(){
    int u,v;
    cin>>u>>v;
    if(u > v){
        cout<<"NO\n";
        return;
    }
    if(u == v){
        cout<<"YES\n";
        return;
    }
    if(__builtin_popcount(u) < __builtin_popcount(v)){
        cout<<"NO\n";
        return;
    }
    while(__builtin_clz(u) == __builtin_clz(v)){
        int x = 31 - __builtin_clz(u);
        u ^= (1<<x);
        v ^= (1<<x);
    }
    for(int i=30;i>=0;--i){
        if(~u & (1<<i)) continue;
        if((2 * (1<<i)) > u){
            u ^= (1<<i);
            u ^= (1<<(i+1));
            continue;
        }
        if(__builtin_popcount(u) == __builtin_popcount(v)) continue;
        u ^= (1<<i);
    }
    while(u != 0 && v != 0){
        int b1 = 31 - __builtin_clz(u);
        int b2 = 31 - __builtin_clz(v);
        if(b1 > b2){
            cout<<"NO\n";
            return;
        }
        u ^= (1<<b1);
        v ^= (1<<b2);
    }
    assert(u == 0 && v == 0);
    cout<<"YES\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
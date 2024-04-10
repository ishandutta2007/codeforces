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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    cin>>a;
    vector<int> bst(n);
    iota(bst.begin(), bst.end(), 0);
    sort(bst.begin(), bst.end(), [&](int x,int y){
        return a[x] - (n - x - 1) > a[y] - (n - y - 1);
    });
    vector<bool> to_jump(n);
    for(int i=0;i<k;i++){
        to_jump[bst[i]] = 1;
    }
    int jumps = 0;
    ll damage = 0;
    for(int i=0;i<n;i++){
        if(to_jump[i]){
            jumps++;
        }
        else{
            damage += a[i] + jumps;
        }
    }
    cout<<damage<<"\n";
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
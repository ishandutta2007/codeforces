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
struct Operation{
    array<int,3> indices;
    Operation(int n, int x,int y,int z){
        indices[0] = x%n;
        indices[1] = y%n;
        indices[2] = z%n;
        sort(indices.begin(), indices.end());
    }
    int operator[](int idx) const{
        return indices[idx];
    }
};
ostream& operator<<(ostream& out, const Operation &o){
    out<<o[0]<<" "<<o[1]<<" "<<o[2]<<"\n";
    return out;
}
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    sort(seq.begin(), seq.end());
    int u = unique(seq.begin(), seq.end()) - seq.begin();
    cout<<(u == n ? "NO" : "YES")<<"\n";
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
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
int n;
vector<int> seq;
struct Operation{
    array<int,3> indices;
    Operation(int x,int y,int z){
        indices[0] = x%n;
        indices[1] = y%n;
        indices[2] = z%n;
        const auto &[i,j,k] = indices;
        seq[i] = seq[j] = seq[k] = seq[i]^seq[j]^seq[k]; 
        sort(indices.begin(), indices.end());
    }
    int operator[](int idx) const{
        return indices[idx];
    }
};
ostream& operator<<(ostream& out, const Operation &o){
    out<<o[0] + 1<<" "<<o[1] + 1<<" "<<o[2] + 1<<"\n";
    return out;
}
void solve(){
    cin>>n;
    seq.resize(n);
    cin>>seq;
    vector<Operation> ops;
    for(int i=0;i+2<n;i+=2){
        ops.emplace_back(i,i+1,i+2);
    }
    if(n%2 == 0){
        if(seq[n-1] != seq[n-2]){
            cout<<"NO\n";
            return;
        }
    }
    for(int i=0;i+2<n;i+=2){
        ops.emplace_back(i,i+1,n-1);
    }
    cout<<"YES\n";
    cout<<ops.size()<<"\n";
    for(const auto &x : ops) cout<<x;
    //cout+seq;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
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
    int n,u,v;
    cin>>n>>u>>v;
    vector<int> seq(n);
    cin>>seq;
    for(int i=1;i<n;i++){
        if(abs(seq[i] - seq[i-1]) > 1){
            cout<<"0\n";
            return;
        }
    }
    for(int i=1;i<n;i++){
        if(abs(seq[i] - seq[i-1]) == 1){
            cout<<min(u,v)<<"\n";
            return;
        }
    }
    cout<<min(u + v, 2*v)<<"\n";
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
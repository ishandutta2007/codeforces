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
    int n,k;
    cin>>n>>k;
    vector<int> seq(n);
    cin>>seq;
    seq.resize(unique(seq.begin(), seq.end()) - seq.begin());
    n = seq.size();
    if(k==1){
        cout<<(n==1 ? 1 : -1)<<"\n";
        return;
    }
    if(k>=n){
        cout<<"1\n";
        return;
    }
    if(n==1){
        cout<<"1\n";
        return;
    }
    cout<<(n-2)/(k-1) + 1<<"\n";
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
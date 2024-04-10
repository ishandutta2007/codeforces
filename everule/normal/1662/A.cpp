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
    int n;
    cin>>n;
    vector<int> bst(11, -1);
    for(int i=0;i<n;i++){
        int b,d;
        cin>>b>>d;
        bst[d] = max(bst[d], b);
    }
    if(count(bst.begin() + 1, bst.end(), -1) > 0){
        cout<<"MOREPROBLEMS\n";
        return;
    }
    cout<<accumulate(bst.begin() + 1, bst.end(), 0)<<"\n";
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
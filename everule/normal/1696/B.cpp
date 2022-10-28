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
    vector<int> a(n);
    cin>>a;
    if(*max_element(a.begin(), a.end()) == 0){
        cout<<"0\n";
        return;
    }
    while(a.back() == 0){
        a.pop_back();
    }
    reverse(a.begin(), a.end());
    while(a.back() == 0){
        a.pop_back();
    }
    if(*min_element(a.begin(), a.end()) > 0){
        cout<<"1\n";
        return;
    }
    cout<<"2\n";
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
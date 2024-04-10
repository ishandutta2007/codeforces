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
    //odd n -> requires m >= n
    //even n -> requires m >= n and m even
    int n,m;
    cin>>n>>m;
    if(m < n){
        cout<<"No\n";
        return;
    }
    if(n % 2 == 0 & m % 2 == 1){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    vector<int> a(n, 1);
    if(n % 2){
        a[n-1] += m - n;
    }
    else{
        a[n-2] += (m - n) / 2;
        a[n-1] += (m - n) / 2;
    }
    cout+a;
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
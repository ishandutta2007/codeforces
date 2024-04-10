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
    int c1 = count(a.begin(), a.end(), 1);
    if(c1 == n){
        cout<<"Yes\n";
        return;
    }
    if(c1 == 0){
        cout<<"Yes\n";
        return;
    }
    int c0 = count(a.begin(), a.end(), 0);
    if(c0 > 0){
        cout<<"No\n";
        return;
    }
    sort(a.begin(), a.end());
    for(int i=1;i<n;i++){
        if(a[i] - a[i-1] == 1){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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
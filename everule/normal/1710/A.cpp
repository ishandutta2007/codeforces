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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(k);
    cin>>a;
    sort(a.begin(), a.end(), greater<int>());
    bool is_row = 0, is_col = 0;
    ll max_row = 0, max_col = 0;
    for(int i=0;i<k;i++){
        if(a[i] / n > 1){
            max_col += a[i] / n;
            if(m >= 2 * (i + 1) && m <= max_col) is_col = 1;
        }
        if(a[i] / m > 1){
            max_row += a[i] / m;
            if(n >= 2 * (i + 1) && n <= max_row) is_row = 1;
        }
    }
    if(is_row || is_col){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
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
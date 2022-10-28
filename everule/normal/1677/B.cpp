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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> mod_val(m);
    vector<int> ans_col(n * m);
    for(int i=0;i<n*m;i++){
        if(i > 0) ans_col[i] = ans_col[i-1];
        if(s[i] == '0') continue;
        if(s[i] == '1'){
            ans_col[i] += (mod_val[i % m] == 0);
            mod_val[i % m] = 1;
        }
    }
    vector<int> psum(n * m + 1);
    for(int i=1;i<=n*m;i++) psum[i] = psum[i-1] + (s[i-1] - '0');
    vector<int> ans_row(n * m);
    for(int i=0;i<n*m;i++){
        ans_row[i] = (psum[i+1] - psum[max(i - m + 1, 0)] > 0);
        if(i >= m) ans_row[i] += ans_row[i-m];
    }
    for(int i=0;i<n*m;i++){
        cout<<ans_row[i] + ans_col[i]<<" ";
    }
    cout<<"\n";
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
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
    string s;
    cin>>s;
    int n = s.size();
    int sum = 0;
    if(s[n-1] != 'B'){
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<n;i++){
        sum += (s[i] == 'A') - (s[i] == 'B');
        if(sum < 0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
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
    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    cin>>a>>b>>c;
    vector<int> ans(n, -1);
    ans[0] = a[0];
    for(int i=1;i<n;i++){
        for(const auto &v : {a,b,c}){
            if(v[i]!=ans[i-1] && v[i]!=ans[(i+1)%n]){
                ans[i] = v[i];
                break;
            }
        }
    }    
    cout+ans;
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
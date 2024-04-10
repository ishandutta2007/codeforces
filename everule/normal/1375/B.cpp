#include <iostream>
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> seq(n, vector<int>(m));
    vector<vector<int>> ans(n, vector<int>(m));
    cin>>seq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int mx = 4;
            if(i==0|| i==n-1){--mx;}
            if(j==0 || j==m-1){--mx;}
            if(mx < seq[i][j]){
                cout<<"NO\n";
                return;
            }
            ans[i][j] = mx;
        }
    }
    cout<<"YES\n";
    cout*ans;
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
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
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>seq[i][j];
            if(j){
                if(seq[i][j] - seq[i][j-1] != seq[0][j] - seq[0][j-1]){
                    cout<<"-1\n";
                    return;
                }
            }
        }
    }
    int ans = 1e9;
    int b_0=-1;
    auto solve = [&](int b0){
        int b = b0, curr=b0;
        for(int i=1;i<m;i++){
            b+=seq[0][i] - seq[0][i-1];
            curr+=b;
            if(b<0){
                return;
            }
        }
        for(int i=0;i<n;i++){
            if(b0 > seq[i][0]){
                return;
            }
            curr+=seq[i][0] - b0;
        }
        if(curr < ans){
            ans = curr;
            b_0 = b0;
        }
    };
    for(int i=0;i<=500;i++){
        solve(i);
    }
    vector<int> row(n), col(m);
    col[0] = b_0;
    ll fin = 0;
    for(int i=1;i<m;i++){
        col[i] = col[i-1] + seq[0][i] - seq[0][i-1];
    }
    for(int i=0;i<n;i++){
        row[i] = seq[i][0] - b_0;
    }
    for(const auto &val : row){
        fin+=val;
    }
    for(const auto &val : col){
        fin+=val;
    }
    cout<<fin<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<row[i];j++){
            cout<<"row "<<i+1<<"\n";
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<col[i];j++){
            cout<<"col "<<i+1<<"\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
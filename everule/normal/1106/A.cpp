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
    int n;
    cin>>n;
    vector<vector<char>> grid(n+2, vector<char>(n+2, '.'));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }
    int ans = 0;
    const vector<pair<int,int>> del = {{1,1},{1,-1},{-1,1},{-1,-1}};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]!='X') continue;
            bool flag = 1;
            for(const auto &[dx,dy] : del){
                if(grid[i][j]!=grid[i+dx][j+dy]) flag=0;
            }
            ans+=flag;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
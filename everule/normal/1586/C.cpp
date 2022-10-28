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
    vector<string> g(n);
    cin>>g;
    vector<int> colbad(m);
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(g[i-1][j] == 'X' && g[i][j-1] == 'X'){
                colbad[j] = 1;
            }
        }
    }
    vector<int> pcol(m+1);
    for(int i=1;i<=m;i++){
        pcol[i] = pcol[i-1] + colbad[i-1];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(pcol[y] == pcol[x]){
            cout<<"YEs\n";
        }
        else{
            cout<<"No\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
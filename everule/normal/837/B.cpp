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
    vector<string> seq(n);
    cin>>seq;
    bool row=0,col=0;
    if(n%3==0){
        int x = n/3;
        row = 1;
        set<char> color;
        for(int i=0;i<3;i++){
            char c = seq[x*i][0];
            color.insert(c);
            for(int j=0;j<x;j++){
                for(int k=0;k<m;k++){
                    row&=(c==seq[x*i + j][k]);
                }
            }
        }
        row&=(color.size()==3u);
    }
    if(m%3==0){
        col = 1;
        int x = m/3;
        set<char> color;
        for(int i=0;i<3;i++){
            char c = seq[0][x*i];
            color.insert(c);
            for(int j=0;j<x;j++){
                for(int k=0;k<n;k++){
                    col&=(c==seq[k][x*i + j]);
                }
            }
        }
        col&=(color.size()==3u);
    }
    cout<<(row|col ? "YES\n" : "NO\n");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
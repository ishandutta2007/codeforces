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
    vector<string> g(n);
    cin>>g;
    array<int,3> chk = {0,0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            chk[(i+j)%3] += (g[i][j] == 'X');
        }
    }
    int r = min_element(chk.begin(), chk.end()) - chk.begin();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%3 != r) continue;
            if(g[i][j] == 'X') g[i][j] = 'O';
        }
    }
    for(int i=0;i<n;i++) cout<<g[i]<<"\n";
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
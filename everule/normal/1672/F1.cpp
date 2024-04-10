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
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    for(auto &x : a) --x;
    vector<vector<int>> pos(n);
    for(int i=0;i<n;i++) pos[a[i]].push_back(i);
    int t_size = 0;
    for(int i=0;i<n;i++) t_size = max(t_size, (int)pos[i].size());
    vector<vector<int>> cycles(t_size);
    for(int i=0;i<n;i++){
        for(int j=0;j<pos[i].size();j++){
            cycles[j].push_back(pos[i][j]);
        }
    }
    vector<int> p(n);
    for(auto &c : cycles){
        assert(c.size() > 0);
        for(int i=0;i<c.size();i++){
            p[c[i]] = c[(i+1)%c.size()];
        }
    }
    vector<int> b(n);
    for(int i=0;i<n;i++) b[i] = a[p[i]] + 1;
    cout+b;
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
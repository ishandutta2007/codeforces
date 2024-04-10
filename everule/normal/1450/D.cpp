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
    vector<int> seq(n);
    cin>>seq;
    for(auto &x : seq) --x;
    vector<vector<int>> pos(n);
    vector<bool> ans(n+1);
    auto p = seq;
    sort(p.begin(), p.end());
    ans[1] = 1;
    for(int i=0;i<n;i++) ans[1] = ans[1] & (p[i] == i);
    for(int i=0;i<n;i++) pos[seq[i]].push_back(i);
    int l = 0, r = n-1;
    for(int i=0;i<n;i++){
        if(pos[i].size() == 0) break;
        ans[n-i] = 1;
        if(pos[i].size() > 1){
            break;
        }
        if(pos[i][0] == l){
            ++l;
        }
        else if(pos[i][0] == r){
            --r;
        }
        else{
            break;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<'\n';
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
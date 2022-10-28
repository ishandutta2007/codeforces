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
    map<int,int> last;
    map<int,int> ans;
    for(int i=0;i<n;i++){
        if(last.count(seq[i])){
            ans[seq[i]] = max(ans[seq[i]], i-last[seq[i]]);
            last[seq[i]] = i;
        }
        else{
            //cout<<seq[i]<<" "<<i<<"\n";
            ans[seq[i]] = i+1;
            last[seq[i]] = i;
        }
    }
    const int INF = 1e9;
    vector<int> fin(n+1, INF);
    for(const auto &[u,v] : ans){
        int rv = max(v, n-last[u]);
        fin[rv] = min(fin[rv], u);
    }
    for(int i=1;i<=n;i++){
        fin[i] = min(fin[i], fin[i-1]);
    }
    for(int i=1;i<=n;i++){
        if(fin[i]==INF) cout<<"-1 ";
        else cout<<fin[i]<<" ";
    }
    cout<<"\n";
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
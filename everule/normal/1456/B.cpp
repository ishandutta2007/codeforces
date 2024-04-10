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
const int INF = 1e9;
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    for(int i=2;i<n;i++){
        if(__builtin_clz(seq[i]) == __builtin_clz(seq[i-1]) && __builtin_clz(seq[i]) == __builtin_clz(seq[i-2])){
            cout<<"1\n";
            return;
        }
    }
    vector<int> psum(n+1);
    int ans = INF;
    for(int i=1;i<=n;i++) psum[i] = psum[i-1] ^ seq[i-1];
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j;k<=n;k++){
                for(int l=k+1;l<=n;l++){
                    if((psum[j]^psum[i]) > (psum[k]^psum[l])){
                        ans = min(ans, j-i-1 + l-k-1);
                    }
                }
            }
        }
    }
    if(ans == INF) ans = -1;
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
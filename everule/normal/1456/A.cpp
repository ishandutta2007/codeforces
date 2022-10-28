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
    int n,p,k;
    cin>>n>>p>>k;
    --p;
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    vector<int> psum(n);
    vector<int> cnt(k);
    vector<int> cnt0(k);
    for(int i=0;i<n;i++){
        psum[i] = 1 - (s[i] - '0');
        cnt[i%k]++;
        cnt0[i%k] += psum[i];
        if(i>=k) psum[i] += psum[i-k];
    }
    //cout+cnt+psum;
    int ans = 2e9;
    for(int i=p;i<n;i++){
        int curr = y*(i-p) + (cnt0[i%k] - psum[i] + (1 - s[i] + '0')) * x;
        //cout<<curr<<"\n";
        ans = min(ans,curr);
    }
    cout<<ans<<"\n";
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
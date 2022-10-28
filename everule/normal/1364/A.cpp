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
    int n,x;
    cin>>n>>x;
    vector<int> seq(n);
    cin>>seq;
    vector<int> prefixsum(n+1);
    for(int i=1;i<=n;i++){
        prefixsum[i]=prefixsum[i-1]+seq[i-1];
    }
    if(prefixsum[n]%x){
        cout<<n<<"\n";
        return;
    }
    int ans=-1;
    for(int i=n;i>=0;--i){
        if(prefixsum[i]%x){
            ans=max(ans, i);
        }
    }
    for(int i=0;i<n;i++){
        if((prefixsum[n]-prefixsum[i])%x){
            ans=max(ans, n-i);
        }
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
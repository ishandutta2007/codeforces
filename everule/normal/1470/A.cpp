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
    vector<int> k(n), c(m);
    cin>>k>>c;
    for(auto &x : k) --x;
    sort(k.begin(), k.end(), greater<int>());
    int mn = 0, mx = n;
    while(mn < mx){
        int mid = mn + mx + 1;
        mid >>= 1;
        if(mid==0 || k[mid-1] >= mid){
            mn = mid;
        }
        else{
            mx = mid - 1;
        }
    }
    ll ans = 0;
    for(int i=0;i<mn;i++){
        ans += c[i];
    }
    for(int i=mn;i<n;i++){
        ans+=c[k[i]];
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
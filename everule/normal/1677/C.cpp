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
    vector<int> a(n), b(n);
    cin>>a>>b;
    for(auto &x : a) --x;
    for(auto &x : b) --x;
    vector<int> ib(n);
    for(int i=0;i<n;i++) ib[b[i]] = i;
    for(int i=0;i<n;i++) b[i] = ib[b[i]], a[i] = ib[a[i]];
    vector<int> cycles;
    vector<bool> vis(n);
    //cout+a;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        vis[i] = 1;
        int cnt = 1;
        int x = i;
        while(!vis[a[x]]){
            x = a[x];
            vis[x] = 1;
            ++cnt;
        }
        cycles.push_back(cnt);
    }
    //cout+vis;
    //cout+cycles;
    int odd = 0;
    for(auto &c : cycles) odd += c % 2;
    //assert(odd % 2 == n % 2);
    ll ans = 0;
    for(int i=0;i<n/2;i++){
        ans -= 2 * (i + 1);
        ans += 2 * (n - i);
    }
    odd /= 2;
    if(n % 2 == 1){
        ans -= 1ll * (2 * odd + 2) * odd;
    }
    else{
        ans -= 1ll * 2 * odd * odd;
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
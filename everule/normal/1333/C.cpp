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
    vector<ll> psum(n+1);
    for(int i=1;i<=n;i++) psum[i] = psum[i-1] + seq[i-1];
    map<ll,int> last;
    int prev = 0;
    last[0] = 0;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(last.count(psum[i])) prev = max(prev, last[psum[i]] + 1);
        ans += i - prev;
        last[psum[i]] = i;
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
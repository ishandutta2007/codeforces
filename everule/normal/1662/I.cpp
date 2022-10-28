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
    int n,m;
    cin>>n>>m;
    vector<int> p(n), x(m);
    cin>>p>>x;
    sort(x.begin(), x.end());
    vector<array<int, 2>> events;
    for(int i=0;i<n;i++){
        int dist = 1e9;
        int idx = lower_bound(x.begin(), x.end(), 100 * i) - x.begin();
        if(idx < m) dist = min(dist, abs(100 * i - x[idx]));
        --idx;
        if(idx >= 0) dist = min(dist, abs(100 * i - x[idx]));
        if(dist == 0) continue;
        events.push_back({100 * i - dist, +p[i]});
        events.push_back({100 * i + dist, +-p[i]});
    }
    sort(events.begin(), events.end());
    //for(auto &[x, t] : events) cout<<x<<" "<<t<<"\n";
    ll ans = 0;
    ll curr = 0;
    for(auto &[t, x] : events){
        curr += x;
        ans = max(ans, curr);
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
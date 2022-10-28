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
    vector<int> a(n), c(n);
    for(int i=0;i<n;i++) cin>>a[i]>>c[i];
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x,int y){
        return a[x] < a[y];
    });
    int maxm = a[ord[0]] + c[ord[0]];
    ll ans = 0;
    for(auto &i : ord){
        if(i == ord[0]) continue;
        ans += max(0, a[i] - maxm);
        maxm = max(maxm, a[i] + c[i]);
    }
    ans += accumulate(c.begin(), c.end(), 0ll);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
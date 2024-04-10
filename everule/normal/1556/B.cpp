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
    vector<int> a(n);
    cin>>a;
    for(auto &x : a) x = x % 2;
    int count = accumulate(a.begin(), a.end(), 0);
    if(abs(n - 2 * count) > 1){
        cout<<"-1\n";
        return;
    }
    int id1 = 0, id2 = 1;
    ll ans1 = 0;
    for(int i=0;i<n;i++){
        if(a[i]) ans1 += abs(id1 - i), id1 += 2;
        else ans1 += abs(id2 - i), id2 += 2;
    }
    ll ans = 1e18;
    if(id1 - 2 < n && id2 - 2 < n) ans = min(ans, ans1);
    id1 = 1, id2 = 0;
    ll ans2 = 0;
    for(int i=0;i<n;i++){
        if(a[i]) ans2 += abs(id1 - i), id1 += 2;
        else ans2 += abs(id2 - i), id2 += 2;
    }
    if(id1 - 2 < n && id2 - 2 < n) ans = min(ans, ans2);
    cout<<ans/2<<"\n";
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
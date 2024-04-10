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
    if(n == 1){
        cout<<0<<"\n";
        return;
    }
    if(n == 2){
        cout<<max(a[0], a[1]) - min(a[0], a[1])<<"\n";
        return;
    }
    int ans = -100000;
    for(int i=0;i+1<n;i++){
        ans = max(ans, a[n-1] - a[i]);
    }
    for(int i=1;i<n;i++){
        ans = max(ans, a[i] - a[0]);
    }
    for(int i=0;i<n;i++){
        ans = max(ans, a[(i + n - 1) % n] - a[i]);
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
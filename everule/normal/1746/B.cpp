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
    vector<int> p1(n+1), s1(n+1), p0(n+1), s0(n+1);
    cin>>a;
    for(int i=1;i<=n;i++){
        p1[i] = p1[i-1] + (a[i-1] == 1);
        p0[i] = p0[i-1] + (a[i-1] == 0);
    }
    for(int i=n-1;i>=0;--i){
        s1[i] = s1[i+1] + (a[i] == 1);
        s0[i] = s0[i+1] + (a[i] == 0);
    }
    int ans = n - 1;
    for(int i=0;i<=n;i++){
        ans = min(ans, p1[i] + max(0, s0[i] - p1[i]));
    }
    cout<<ans<<'\n';
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
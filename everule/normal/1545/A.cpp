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
    vector<int> a(n);
    cin>>a;
    auto sa = a;
    sort(sa.begin(), sa.end());
    map<int, int> mp;
    for(int i=0;i<n;i++) mp[a[i]] += (i % 2 ? -1 : 1);
    for(int i=0;i<n;i++) mp[sa[i]] -= (i % 2 ? -1 : 1);
    for(auto &[x, y] : mp){
        if(y != 0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
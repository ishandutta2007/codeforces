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
    auto check = [&](int k){
        vector<int> b = a;
        for(auto &x : b) x %= k;
        for(auto &x : b) if(x < 0) x += k;
        sort(b.begin(), b.end());
        int ans = 0;
        for(int i=0;i<=n/2;i++){
            if(b[n/2 + i - 1] == b[i]){
                ans = 1;
            }
        }
        return ans;
    };
    if(check(1e6 + 7)){
        cout<<"-1\n";
        return;
    }
    int ans = 1;
    for(int i=0;i<50;i++){
        int g = a[rand() % n] - a[rand() % n] * (rand() % 2 ? -1 : 1);
        g = abs(g);
        if(g == 0) continue;
        vector<int> f;
        for(int i=1;i*i<=g;i++){
            if(g % i) continue;
            f.push_back(i);
            f.push_back(g / i);
        }
        for(auto &x : f){
            if(check(x)){
                ans = max(ans, x);
            }
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
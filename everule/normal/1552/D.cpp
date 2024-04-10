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
    for(int i=0;i<n;i++) a.push_back(-a[i]);
    n *= 2;
    vector<int> sum(1<<n);
    for(int i=1;i<(1<<n);i++){
        int mb = 31 - __builtin_clz(i);
        sum[i] = a[mb] + sum[i ^ (1<<mb)];
    }

    for(int i=0;i<n/2;i++){
        for(int j=0;j<(1<<n);j++){
            if(j & (1<<i)) continue;
            if(j & (1<<(i + n/2))) continue;
            if(sum[j] == a[i]){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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
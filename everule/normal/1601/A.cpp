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
const int lg = 30;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    array<int, lg> bc;
    fill(bc.begin(), bc.end(), 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<lg;j++){
            bc[j] += (a[i] >> j) % 2;
        }
    }
    int g = bc[0];
    for(int i=0;i<lg;i++) g = __gcd(g, bc[i]);
    for(int i=1;i<=n;i++) if(g % i == 0) cout<<i<<" ";
    cout<<"\n";

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
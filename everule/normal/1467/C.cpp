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
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<ll> a1(n1), a2(n2), a3(n3);
    cin>>a1>>a2>>a3;
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(a3.begin(), a3.end());
    ll ans = min({accumulate(a1.begin(), a1.end(), 0ll), accumulate(a2.begin(), a2.end(), 0ll), accumulate(a3.begin(), a3.end(), 0ll)});
    ans = min(ans, a1[0] + a2[0] + a3[0] - max({a1[0], a2[0], a3[0]}));
    ll sum = accumulate(a1.begin(), a1.end(), 0ll) + accumulate(a2.begin(), a2.end(), 0ll) + accumulate(a3.begin(), a3.end(), 0ll);
    cout<<sum-2*ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
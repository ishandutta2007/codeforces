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
    set<array<ll, 2>> ans;
    ll offset = 0;
    vector<int> v(n), t(n);
    cin>>v>>t;
    for(int i=0;i<n;i++){
        ans.insert({v[i] + offset, i});
        offset += t[i];
        ll curr = 0;
        while(ans.size() > 0 && (*ans.begin())[0] < offset){
            curr += (*ans.begin())[0] - offset + t[i];
            ans.erase(ans.begin());
        }
        curr += 1ll * t[i] * ans.size();
        cout<<curr<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
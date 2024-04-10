#include <iostream>
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
pair<int,ll> operator-(const pair<int,ll> &x, const pair<int,ll> &y){
    return mp(x.first - y.first, x.second - y.second);
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    cin>>a>>b;
    a.pb(a[0]);
    b.pb(b[0]);
    pair<int,ll> line;
    int mn=0, mx=b[0];
    auto check = [&](int mid){
        int x = mid;
        for(int i=1, needed = 0;i<n;i++){
            needed = max(a[i] - x, 0);
            if(needed > b[i]){
                mn = mid + 1;
                return false;
            }
            x = min(b[i]- needed, a[i+1]);
        }
        x = a[0] - x;
        if(x + mid > b[0]){
            mx = mid-1;
            return false;
        }
        mn = mx = mid;
        return true;
    };
    while(mn < mx){
        int mid = mn + mx;
        mid>>=1;
        check(mid);
    }
    if(check(mn)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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
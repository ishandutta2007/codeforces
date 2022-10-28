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
    auto OR = [&](int i,int j){
        cout<<"or "<<i+1<<" "<<j+1<<"\n";
        cout.flush();
        int ans;
        cin>>ans;
        return ans;
    };
    auto AND = [&](int i,int j){
        cout<<"and "<<i+1<<" "<<j+1<<"\n";
        cout.flush();
        int ans;
        cin>>ans;
        return ans;
    };
    int n,k;
    cin>>n>>k;
    ll x1 = OR(0, 1), x2 = OR(0, 2), x3 = OR(1, 2), y1 = AND(0, 1), y2 = AND(0, 2), y3 = AND(1, 2);
    vector<ll> a(n);
    a[0] = (x1 + x2 + y1 + y2 - x3 - y3) / 2;
    a[1] = (x1 + x3 + y1 + y3 - x2 - y2) / 2;
    a[2] = (x2 + x3 + y2 + y3 - x1 - y1) / 2;
    for(int j=3;j<n;j++){
        ll x1 = OR(0, j);
        ll x2 = AND(0, j);
        a[j] = x1 + x2 - a[0];
    }
    sort(a.begin(), a.end());
    cout<<"finish "<<a[k-1]<<"\n";
    cout.flush();
}
int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    solve();
}
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
    int n,a,b;
    cin>>n>>a>>b;
    auto check = [&](int x){
        if(min(a,b) < x) return false;
        return a/x + b/x >= n;
    };
    int mn = 1,mx = a+b;
    while(mn < mx){
        int mid = (mn + mx + 1);
        mid>>=1;
        if(check(mid)){
            mn = mid;
        }
        else{
            mx = mid - 1;
        }
    }
    cout<<mn<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
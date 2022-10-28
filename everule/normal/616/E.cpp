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
const int p = 1e9 + 7;
const int inv2 = (p+1)/2;
ll sumrange(ll l, ll r){
    l%=p;
    r%=p;
    l = l*(l-1);
    r = r*(r-1);
    l%=p;
    r%=p;
    l*=inv2;
    r*=inv2;
    l%=p;
    r%=p;
    return (r-l < 0 ? r-l+p : r-l);
}
ll solve(ll l, ll r, ll n){
    if(n/l==n/(r-1)){
        return sumrange(l,r) * (n/l) %p;
    }
    ll ans = solve(l, (l+r)/2, n) + solve((l+r)/2, r, n);
    return ans>=p ? ans-p : ans;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll ans = solve(1,m+1,n);
    ans = (n%p)*(m%p)%p - ans;
    ans%=p;
    if(ans<0){
        ans+=p;
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
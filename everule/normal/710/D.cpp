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
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
ll modpower(ll base, ll power, ll mod){
    ll ans =1;
    base%=mod;
    while(power){
        if(power&1){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        power>>=1;
    }
    return ans;
}
void solve(){
    ll a1,b1,a2,b2,L,R;
    cin>>a1>>b1>>a2>>b2>>L>>R;
    L = max({L, b1, b2});
    if(L > R){
        cout<<"0\n";
        return;
    }
    int g = gcd(a1,a2);
    if(abs(b1-b2) % g != 0){
        cout<<"0\n";
        return;
    }
    ll curr = (b1 - b2)/g;
    int ph = phi(a1/g);
    curr *= modpower(a2/g, ph-1, a1/g);
    curr %= a1/g;
    if(curr < 0) curr+=a1/g;
    ll vl = curr * a2 + b2;
    ll md = std::lcm(ll(abs(a1)),ll(abs(a2)));
    vl%=md;
    R += (abs(L)/md + 7)*md;
    L += (abs(L)/md + 7)*md;
    auto solve = [&](ll x){
        return (x-vl)/md + 1;
    };
    cout<<solve(R) - solve(L-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
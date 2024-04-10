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
    ll n;
    cin>>n;
    ll ans = 0;
    while(n){
        if((n&3)!=2 && n!=4 && n!=8){
            ans+=1;
            --n;
        }
        else{
            ans+=(n>>1);
            n>>=1;
        }
        if(n==0) continue;
        if((n&3)!=2 && n!=4 && n!=8){
            --n;
        }
        else{
            n>>=1;
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
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
vector<int> primes;
vector<bool> prime;
void sieve(const int n){
    prime.resize(n + 1, 1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            primes.pb(i);
            for(int j=2*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
}
void solve(){
    int n,e;
    cin>>n>>e;
    vector<int> a(n);
    cin>>a;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        if(a[i] == 1){
            b[i] = 0;
        }
        else if(prime[a[i]]){
            b[i] = 1;
        }
        else{
            b[i] = 2;
        }
    }
    ll ans = 0;
    for(int m=0;m<e;m++){
        vector<int> am;
        for(int i=m;i<n;i+=e){
            am.push_back(b[i]);
        }
        int n = am.size();
        vector<int> pam(am.size() + 1);
        for(int i=1;i<=n;i++){
            pam[i] = pam[i-1] + am[i-1];
        }
        vector<int> psumcount(2 * am.size() + 1);
        psumcount[0] = 1;
        for(int i=1;i<=n;i++){
            if(pam[i] > 0) ans += psumcount[pam[i] - 1];
            psumcount[pam[i]]++;
        }
    }
    for(int i=0;i<n;i++) if(b[i] == 1) --ans;
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1e6 + 7);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
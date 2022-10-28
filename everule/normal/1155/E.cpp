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
const int p = 1e6 + 3;
ll modpower(ll base, ll power, ll mod=p){
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
vector<ll> fact;
vector<ll> invfact;
void computefactorial(int n){
    ++n;
    fact.resize(n);
    invfact.resize(n);
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=p;
    }
    invfact[n-1]=modpower(fact[n-1],p-2);
    for(int i=n-2;i>=0;i--){
        invfact[i]=(i+1)*invfact[i+1];
        invfact[i]%=p;
    }
}
const int k = 10;
void solve(){
    auto query = [&](int x){
        cout<<"? "<<x<<endl;
        int ans;
        cin>>ans;
        return ans;
    };
    vector<vector<ll>> q(k + 1);
    for(int i=0;i<=k;i++) q[i].assign(k+1-i, 0);
    for(int i=0;i<=k;i++) q[0][i] = query(i);
    auto comp = [&](){
        for(int i=1;i<=k;i++){
            for(int j=0;j<=k-i;j++){
                q[i][j] = q[i-1][j+1] - q[i-1][j];
                if(q[i][j] < 0) q[i][j] += p;
            }
        }
    };
    vector<ll> poly(k + 1);
    for(int deg=k;deg>=0;--deg){
        comp();
        poly[deg] = q[deg][0];
        poly[deg] *= invfact[deg];
        poly[deg] %= p;
        for(int i=0;i<=k;i++){
            q[0][i] -= 1LL * poly[deg] * modpower(i, deg) % p;
            if(q[0][i] < 0) q[0][i] += p;
        }
    }
    auto eval = [&](int x){
        ll curr = 1;
        ll ans = 0;
        for(int i=0;i<=k;i++){
            ans += curr * poly[i];
            curr *= x;
            curr %= p;
        }
        return ans%p;
    };
    for(int i=0;i<p;i++){
        if(eval(i) == 0){
            cout<<"! "<<i<<endl;
            return;
        }
    }
    cout<<"! "<<-1<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(20);
    solve();
}
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
ll ncr(int n,int r){
    if(n<0 || r>n) return 0;
    return fact[n]*invfact[n-r]%p * invfact[r]%p;
}
struct Snake{
    int x,y,b;
    Snake(int x,int y,int b) : x(x), y(y), b(b) {}
    Snake(){}
};
const int MAXN = 2e3 + 7;
void solve(){
    int n,m,r;
    cin>>n>>m>>r;
    vector<Snake> snakes(n);
    for(auto &[x,y,b] : snakes){
        cin>>x>>y>>b;
    }
    ll ans = 0;
    vector<bitset<MAXN>> seq(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            seq[i][j] = (max(abs(snakes[i].x-snakes[j].x), abs(snakes[i].y-snakes[j].y))<=r);
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<seq[i][j];
        }
        cout<<"\n";
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(i==j) continue;
            int c1 = seq[i].count();
            int c2 = seq[j].count();
            int cnt = (seq[i]|seq[j]).count();
            //cout<<i<<" "<<j<<" "<<c1<<" "<<c2<<" "<<cnt<<"\n";
            ll ways = ncr(n,m) - ncr(n-c1,m) - ncr(n-c2,m) + ncr(n-cnt,m);
            //cout<<ways<<"\n";
            ways%=p;
            ways*=2*snakes[i].b;
            ways%=p;
            ways*=snakes[j].b;
            ways%=p;
            ans+=ways;
            ans%=p;
        }
        int cnt = seq[i].count();
        ans+=(ncr(n,m) - ncr(n-cnt,m))*snakes[i].b%p*snakes[i].b%p;
        ans%=p;
    }
    if(ans<0) ans+=p;
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(2e3 + 7);
    solve();
}
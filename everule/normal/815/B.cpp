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
const ll p =1e9 + 7;
ll modpower(ll base, ll power, ll mod=p){
    ll ans =1;
    base%=p;
    while(power){
        if(power&1){
            ans*=base;
            ans%=p;
        }
        base*=base;
        base%=p;
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
ll ncr(int n, int r){
    if(n<0 || r>n || r<0){
        return 0;
    }
    return fact[n] * invfact[r]%p * invfact[n-r]%p;
}
void solve(){
    int n;
    cin>>n;
    int N=n;
    vector<int> seq(n);
    cin>>seq;
    if(n==1){
        cout<<seq[0]<<"\n";
        return;
    }
    ll ans = 0;
    if(seq.size()%2){
        vector<int> seq2(n-1);
        for(int i=0;i<n-1;i++){
            seq2[i] = seq[i+1]  + seq[i]*(i&1 ? -1 : 1); 
        }
        seq = seq2;
        --n;
    }
    vector<int> seq1(n/2), seq2(n/2);
    for(int i=0;i<n;i+=2){
        seq1[i/2] = seq[i];
        seq2[i/2] = seq[i+1];
    }
    auto solve = [&](const vector<int> &s){
        int n = s.size();
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans+=ncr(n-1, i) * s[i]; 
            ans%=p;
        }
        return ans;
    };
    if((n>>1)%2 ^ N%2){
        ans = solve(seq1) + solve(seq2);
    }
    else{
        ans = solve(seq1) - solve(seq2);
    }
    ans%=p;
    if(ans<0){
        ans+=p;
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(2e5 + 7);
    solve();
}
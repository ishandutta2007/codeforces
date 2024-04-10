#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll, int>> f;

void factorize(ll n) {
    for(ll i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            f.push_back(make_pair(i, 0));
            while(n%i==0) {n/=i; f[f.size()-1].second++;}
        }
    }
    if(n!=1) if(f.size()!=0&&f[f.size()-1].first==n) f[f.size()-1].second++; else f.push_back(make_pair(n, 1));
}

ll solve(ll n) {
    if(n==1) return 1;
    factorize(n);
    if(f.size()>1) return 1;
    else if(f[0].second>1) return f[0].first;
    else return n;
}

int32_t main() {
    ll n; cin>>n; cout<<solve(n);
}
//https://codeforces.com/contest/1350/problem/C
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define int long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
vector<vector<pair<int, int>>> factors;
vector<int> primes;
void sieve(const int n){
    factors.resize(n + 1);
    vector<bool> prime(n+1, 1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=2*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]){
            primes.pb(i);
            factors[i].pb(mp(i,1));
            for(int j=2*i;j<=n;j+=i){
                factors[j].pb(mp(i, 1));
            }
            int diff=i*i;
            while(diff<=n){
                for(int j=diff;j<=n;j+=diff){
                    ++factors[j][factors[j].size()-1].second;
                }
                diff*=i;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> ans(3e5 + 1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(const auto &y : factors[x]){
            ans[y.first].pb(y.second);
        }
    }
    int fin=1;
    for(const auto &p : primes){
        int s=ans[p].size();
        if(s<n-1){
            continue;
        }
        if(s==n-1){
            int po=*min_element(ans[p].begin(), ans[p].end());
            while(po--){
                fin*=p;
            }
            continue;
        }
        if(s==n){
            sort(ans[p].begin(), ans[p].end());
            int po=ans[p][1];
            while(po--){
                fin*=p;
            }
        }
    }
    cout<<fin<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(3e5);
    solve();
}
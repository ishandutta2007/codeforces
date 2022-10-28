//https://codeforces.com/contest/1343/problem/D
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> seq(n);
    vector<int> sums(2*k + 1);
    vector<int> begin(n/2);
    vector<int> end(n/2);
    for(auto &x : seq){
        cin>>x;
    }
    for(int i=0;i<n/2;i++){
        ++sums[seq[i] + seq[n-i-1]];
        begin[i]=(min(seq[i], seq[n-i-1]) + 1);
        end[i]=max(seq[i], seq[n-i-1])  + k;
    }
    sort(begin.begin(), begin.end());
    sort(end.begin(), end.end());
    int ans=1e9;
    for(int i=2, j=0, l=0, poss=0;i<=2*k;i++){
        while(j<n/2 && i>=begin[j]){
            poss++;
            j++;
        }
        while(l<n/2 && i>end[l]){
            poss--;
            l++;
        }
        ans=min(ans, poss - sums[i] + 2*(n/2 -poss));
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    //precompute();
    while(t--){
        //init();
        solve();
    }
}
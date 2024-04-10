//https://codeforces.com/contest/1328/problem/B
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
ll solve(){
    int n;
    ll k;
    cin>>n>>k;
    char s[n];
    for(int i=0;i<n;i++){
        s[i]='a';
    }
    int pos1=n-1;
    for(int i=1;i<n;i++){
        if(k>i){
            k-=i;
        }
        else{
            pos1=n-i-1;
            break;
        }
    }
    int pos2=n-k;
    s[pos1]='b';
    s[pos2]='b';
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    cout<<'\n';
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
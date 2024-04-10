//https://codeforces.com/contest/1350/problem/D
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
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>k){
            seq[i]=1;
        }
        else if(x<k){
            seq[i]=-1;
        }
        else{
            seq[i]=0;
        }
    }
    bool present=(seq[0]==0);
    bool flag=0;
    if(n==1){
        cout<<(present ? "Yes\n" : "No\n");
        return;
    }
    for(int i=1;i<n;i++){
        if(seq[i]==0){
            present=1;
        }
        if(seq[i]!=-1 && seq[i-1]!=-1){
            flag=1;
        }
    }
    if(flag && present){
        cout<<"Yes\n";
        return;
    }
    if(!present){
        cout<<"No\n";
        return;
    }
    for(int i=1;i<n-1;i++){
        if(seq[i]==-1 && seq[i+1]!=-1 && seq[i-1]!=-1){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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
//https://codeforces.com/contest/1352/problem/G
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
    int a,b,c;
    cin>>c>>b>>a;
    if(a==0 && b==0 && c==0){
        cout<<'\n';
        return;
    }
    if(b==0 && c==0){
        for(int i=0;i<=a;i++){
            cout<<"1";
        }
        cout<<'\n';
        return;
    }
    if(b==0 && a==0){
        for(int i=0;i<=c;i++){
            cout<<"0";
        }
        cout<<'\n';
        return;
    }
    if(b==0){
        cout<<"-1\n";
        return;
    }
    for(int i=0;i<=a;i++){
        cout<<"1";
    }
    for(int i=0;i<=c;i++){
        cout<<"0";
    }
    for(int i=0;i<b-1;i++){
        cout<<(i&1 ? "0" : "1");
    }
    cout<<'\n';
    return;
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
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
    int n;
    cin>>n;
    if(n<4){
        cout<<"-1\n";
        return;
    }
    if(n==4){
        cout<<"3 1 4 2\n";
        return;
    }
    if(n==5){
        cout<<"1 3 5 2 4\n";
        return;
    }
    if(n==6){
        cout<<"1 3 5 2 6 4\n";
        return;
    }
    if(n%2==0){
        int i=1;
        for(;i<=n;i+=2){
            cout<<i<<" ";
        }
        cout<<n-4<<" ";
        cout<<n<<" ";
        cout<<n-2<<" ";
        for(int i=n-6;i>0;i-=2){
            cout<<i<<" ";
        }
        cout<<'\n';
        return;
    }
    int i=1;
    for(;i<=n;i+=2){
        cout<<i<<" ";
    }
    cout<<n-3<<" ";
    cout<<n-1<<" ";
    for(int i=n-5;i>0;i-=2){
        cout<<i<<" ";
    }
    cout<<'\n';
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
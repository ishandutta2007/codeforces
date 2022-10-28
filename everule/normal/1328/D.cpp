//https://codeforces.com/problemset/problem/1328/D
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
    int seq[n];
    int pair=-5;
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    int count=0;
    for(int i=1;i<n;i++){
        if(seq[i]!=seq[i-1]){
            count++;
        }
        else{
            pair=i;
        }
    }
    if(seq[0]!=seq[n-1]){
        count++;
    }
    else{
        pair=0;
    }
    if(count==0){
        cout<<"1"<<'\n';
        for(int i=0;i<n;i++){
            cout<<"1"<<" ";
        }
        cout<<'\n';
        return;
    }
    if(count == n){
        if(n%2){
            cout<<"3"<<"\n";
            for(int i=0;i<n-1;i++){
                cout<<i%2 + 1<<" ";
            }
            cout<<"3"<<" ";
            cout<<'\n';
            return;
        }
        else{
            cout<<"2"<<"\n";
            for(int i=0;i<n;i++){
                cout<<i%2 + 1<<' ';
            }
            cout<<"\n";
            return;
        }
    }
    int ans[n];
    cout<<"2"<<"\n";
    for(int i=0;i<n;i++){
        int idx=(pair+i)%n;
        ans[idx]=i%2+1;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return;
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
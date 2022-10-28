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
    cin>>n;
    int seq[n];
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    int ans=1;
    sort(seq,seq+n);
    for(int i=1;i<n;i++){
        if(seq[i]!=seq[i-1]){
            ans++;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    //precompute();
    while(t--){
        //init();
        cout<<solve()<<"\n";
    }
}
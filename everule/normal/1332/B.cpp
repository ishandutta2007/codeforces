#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
vector<int> primes={2,3,5,7,11,13,17,19,23,29,31};
ll solve(){
    int n;
    cin>>n;
    int seq[n];
    int color[n]={0};
    int m=0;
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    for(int i=0;i<primes.size();i++){
        int x=primes[i];
        bool used=0;
        for(int i=0;i<n;i++){
            if(seq[i]%x==0  && color[i]==0){
                if(!used){
                    ++m;
                    used=1;
                }
                color[i]=m;
            }
        }
    }
    cout<<m<<"\n";
    for(int i=0;i<n;i++){
        cout<<color[i]<<" ";
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
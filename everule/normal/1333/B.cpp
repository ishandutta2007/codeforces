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
    vector<int> a(n);
    int cnt1=0,cnt2=0;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
        }
        if(a[i]==-1){
            cnt2++;
        }
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==1){
            cnt1--;
        }
        if(a[i]==-1){
            cnt2--;
        }
        if(b[i]==a[i]){
            continue;
        }
        if(b[i]>a[i]){
            if(cnt1){
                continue;
            }
            cout<<"NO\n";
            return;
        }
        if(b[i]<a[i]){
            if(cnt2){
                continue;
            }
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
//https://codeforces.com/contest/1341/problem/0
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
    int n, a, b, c, d;
    cin>>n>>a>>b>>c>>d;
    a*=n;
    b*=n;
    int mxg=a+b;
    int mng=a-b;
    int mxval=c+d;
    int mnval=c-d;
    if(mxg < mnval || mng>mxval){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
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
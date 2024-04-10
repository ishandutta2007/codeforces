#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans=0;
    if(n&1){
       ans|=16;
    }
    if(n&2){
        ans|=2;
    }
    if(n&4){
        ans|=8;
    }
    if(n&8){
        ans|=4;
    }
    if(n&16){
        ans|=1;
    }
    if(n&32){
        ans|=32;
    }
    cout<<ans;
}
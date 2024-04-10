//https://codeforces.com/contest/1343/problem/0
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
int solve(){
    int n;
    cin>>n;
    int i=2;
    while(true){
        int x=(1<<i) - 1;
        if(n%x==0){
            return n/x;
        }
        i++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}
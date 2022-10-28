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

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    if(x%2==0){
        cout<<2<<x/2;
        return 0;
    }
    if(x%3==0){
        cout<<3<<x/3;
        return 0;
    }
    for(int i=5;i*i<=x;i+=6){
         if(x%i==0){
             cout<<i<<x/i;
             return 0;
         }
         if(x%(i+2)==0){
             cout<<i+2<<x/(i+2);
             return 0;
         }
    }
}
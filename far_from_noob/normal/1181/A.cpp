#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define pb push_back
#define mp make_pair
#define fo(i,n) for(int i=0;i<n;i++)
ll n,k,t,m,q,flag=0,count=0;
int main() {
    cin>>n>>m>>k;
    if(n/k + m/k == (n+m)/k)cout<<n/k + m/k<<" "<<0;
    else cout<<(n+m)/k<<" "<<k- max(n%k, m%k);
    
    
    return 0;
}
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define fo(i,n) for(int i=0;i<n;i++)




ll n,k,t,m,q,flag=0,countans=0;
int main() {
    int c[3],d;
    cin>>c[0]>>c[1]>>c[2]>>d;
    sort(c,c+3);
    int ans=0;
    if(c[1]-c[0]<d)ans+=d-c[1]+c[0];
    if(c[2]-c[1]<d)ans+=d-c[2]+c[1];
    cout<<ans;
    return 0;
}
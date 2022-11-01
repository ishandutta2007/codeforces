#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll n,k,t,m,p,q,a,b,flag=0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //cin>>t;
    t=1;
    while(t--){
            cin>>n;
            cin>>a>>b>>p>>q;
            ll lcm = (a*b)/__gcd(a,b);
            ll countans=0;
            countans+= n/a * p;
            countans+= n/b * q;
            countans -= n/lcm * min(p,q);
            cout<<countans;

    }

    return 0;
}
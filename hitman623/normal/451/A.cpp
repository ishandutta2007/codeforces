#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
main()
{
    io
    long n,m;
    cin>>n>>m;
    if(min(n,m)%2==0) cout<<"Malvika";
    else cout<<"Akshat";
    return 0;
}
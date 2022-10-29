#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,x[1003],i,u=1e9+7,l=-1e9-7,j,l1,l2,r1,r2;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>x[i];
    for(i=0;i<n-1;++i)
    for(j=0;j<n-1;++j)
    if(i!=j)
    {
        l1=x[i];
        r1=x[i+1];
        if(l1>r1) swap(l1,r1);
        l2=x[j];
        r2=x[j+1];
        if(l2>r2) swap(l2,r2);
        if(l2>=r1 || l1>=r2 || (l1<=r2 && l1>=l2 && r1>=l2 && r1<=r2) || (l2<=r1 && l2>=l1 && r2>=l1 && r2<=r1)) ;
        else {cout<<"yes";exit(0);}
    }
    cout<<"no";
    return 0;
}
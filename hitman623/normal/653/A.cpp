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
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    long n,i,j,k,a[55];
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    for(k=0;k<n;++k)
    if(i!=j && j!=k && i!=k)
    {
        if(abs(a[i]-a[j])<=2 && abs(a[i]-a[k])<=2 && abs(a[k]-a[j])<=2 && abs(a[i]-a[j])>0 && abs(a[i]-a[k])>0 && abs(a[k]-a[j])>0) {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}
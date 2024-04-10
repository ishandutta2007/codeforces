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
    long n,i,j;
    cin>>n;
    cout<<(n*n+1)/2<<"\n";
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        if((i+j)%2==0) cout<<"C";
        else cout<<".";
        cout<<"\n";
    }
    return 0;
}
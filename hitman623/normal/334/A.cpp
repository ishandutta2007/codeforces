#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    io
    long n,i,cur=1,cur2,j;
    cin>>n;
    cur2=n*n;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n/2;++j,cur++)
        cout<<cur<<" ";
        for(j=1;j<=n/2;++j,cur2--)
        cout<<cur2<<" ";
        cout<<endl;
    }
    return 0;
}
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
    long n,m,a[100005],i,j,t,sum=0,x,y;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    cin>>a[i];
    for(i=0;i<m;++i)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            a[x]=y-sum;
        }
        else if(t==2)
        {
            cin>>y;
            sum+=y;
        }
        else
        {
            cin>>x;
            cout<<a[x]+sum<<endl;
        }
    }
    return 0;
}
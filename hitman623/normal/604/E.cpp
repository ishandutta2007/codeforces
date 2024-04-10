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
long n,k,i,a[100005],g[6],j,ans=0;
int main()
{
    io
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    if(k%2==0)
    {
        for(i=0;i<n;++i)
        if(a[i]==2) ans^=2;
        else if(a[i]%2==0 || a[i]==1)
        ans^=1;
    }
    else
    {
        g[0]=0;
        g[1]=1;
        g[2]=0;
        g[3]=1;
        g[4]=2;
        for(i=0;i<n;++i)
        {
            long c=0;
            if(a[i]<=4)
            {
                ans^=g[a[i]];
                continue;
            }
            if(a[i]%2) continue;
            while(a[i]%2==0)
            {
                a[i]/=2,c++;
                if(a[i]<=4) break;
            }
            if(a[i]<=4)
            {
                int r=g[a[i]];
                while(c--)
                {
                    r++;
                    if(r==3) r=1;
                }
                ans^=r;
            }
            else if(c%2) ans^=1;
            else ans^=2;
        }
    }
    if(ans) cout<<"Kevin";
    else cout<<"Nicky";
    return 0;
}
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
    long n,v[4004],d[4004],p[4004],i,c=0,j,k,dd;
    cin>>n;
    vl vv;
    for(i=0;i<n;++i)
    cin>>v[i]>>d[i]>>p[i];
    for(i=0;i<n;++i)
    {
        if(p[i]<0)
        continue;
        else
        {
            c++;
            vv.pb(i+1);
            k=0;
            dd=0;
            for(j=i+1;j<n;++j)
            if(p[j]>=0)
            {
                p[j]-=dd;
                p[j]-=v[i]-k;
                k++;
                k=min(k,v[i]);
                if(p[j]<0) dd+=d[j];
            }
        }
    }
    cout<<c<<"\n";
    for(i=0;i<c;++i)
    cout<<vv[i]<<" ";
    return 0;
}
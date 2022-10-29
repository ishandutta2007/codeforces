#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
long ans[2000006];
int main()
{
    long n,x,y,a[100005],i,l=0,r=0;
    cin>>n>>x>>y;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]%=(x+y);
    }
    ans[0]=-1;
    for(i=1;i<=x+y;++i)
    {
        if((l+1)*y<(r+1)*x)
        {
            l++;
            ans[i]=1;
        }
        else if((l+1)*y>(r+1)*x)
        {
            r++;
            ans[i]=0;
        }
        else
        {
            ans[i]=-1;
            ans[++i]=-1;
            l++;r++;
        }
    }
    for(i=0;i<n;++i)
    {
        if(ans[a[i]]==1) cout<<"Vanya";
        else if(ans[a[i]]==0) cout<<"Vova";
        else cout<<"Both";
        cout<<endl;
    }
    return 0;
}
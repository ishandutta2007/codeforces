#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int n,m=-1E9,ans=0;
        cin>>n;
        while(n--)
        {
            int t;
            cin>>t;
            if(t>m)m=t;
            else ans=max(ans,m-t);
        }
        int i=0;
        while(1ll<<i<=ans)++i;
        cout<<i<<endl;
    }
}
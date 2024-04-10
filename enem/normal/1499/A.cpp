#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,k1,k2,w,b;
        cin>>n>>k1>>k2>>w>>b;

        if(w<=min(k1,k2)+abs(k1-k2)/2 && b<=min(n-k1,n-k2)+abs(k1-k2)/2) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
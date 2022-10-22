#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos,l,r,ans=0;
    cin>>n>>pos>>l>>r;
    if(l==1&&r==n)
        ans=0;
    else if(pos<=l&&r==n)
        ans+=l-pos+1;
    else if(pos>l&&r==n)
        ans+=pos-l+1;
    else if(pos>=r&&l==1)
        ans+=pos-r+1;
    else if(pos<r&&l==1)
        ans+=r-pos+1;
    else
        ans+=min(abs(l-pos)+r-l,abs(pos-r)+(r-l))+2;
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;
int n,a[1005],m,b1[10005],b2[10005],c[10005],ans[1005],S;
set<int>A;
int main()
{
    int i,j;
    for(i=1;i<=1005;i++)ans[i]=10000000;
    cin>>n;for(i=1;i<=n;i++)cin>>a[i];
    cin>>m;for(i=1;i<=m;i++)
    {
        cin>>b1[i]>>b2[i]>>c[i];
        A.insert(b2[i]);
        if(a[b1[i]]<=a[b2[i]]){cout<<"-1";return 0;}
    }
    if(A.size()!=(n-1)){cout<<"-1";return 0;}
    for(i=1;i<=m;i++)if(c[i]<ans[b2[i]])ans[b2[i]]=c[i];
    for(i=1;i<=n;i++)if(ans[i]!=10000000)S+=ans[i];
    cout<<S;
    return 0;
}
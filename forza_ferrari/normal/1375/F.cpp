#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int a[3],b[3];
inline void solve()
{
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    sort(b,b+3);
    cout<<b[2]-b[1]+b[2]-b[0]<<endl;
    int x;
    cin>>x;
    if(!x)
        return;
    --x;
    a[x]+=b[2]-b[1]+b[2]-b[0];
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    sort(b,b+3);
    cout<<b[1]-b[0]<<endl;
    cin>>x;
}
signed main()
{
    cin>>a[0]>>a[1]>>a[2];
    cout<<"First"<<endl;
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    sort(b,b+3);
    cout<<b[2]-b[1]<<endl;
    int x;
    cin>>x;
    if(!x)
        return 0;
    --x;
    if(a[x]==b[2])
    {
        a[x]+=b[2]-b[1];
        solve();
        return 0;
    }
    a[x]+=b[2]-b[1];
    cout<<b[2]-b[1]<<endl;
    cin>>x;
    if(!x)
        return 0;
    --x;
    a[x]+=b[2]-b[1];
    solve();
    return 0;
}
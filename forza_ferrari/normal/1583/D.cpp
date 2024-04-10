#include<iostream>
#include<cstdio>
using namespace std;
int n,a[101],ans;
int main()
{
    cin>>n;
    for(register int i=1;i<=n;++i)
    {
        cout<<"? ";
        for(register int j=1;j<n;++j)
            cout<<i<<" ";
        cout<<"1"<<endl;
        int pos;
        cin>>pos;
        if(pos)
            ++ans;
    }
    ++ans;
    a[n]=ans;
    for(register int i=1;i<=n;++i)
    {
        if(i==a[n])
            continue;
        cout<<"? ";
        for(register int j=1;j<n;++j)
            cout<<n+1-i<<" ";
        cout<<n+1-a[n]<<endl;
        int pos;
        cin>>pos;
        a[pos]=i;
    }
    cout<<"! ";
    for(register int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
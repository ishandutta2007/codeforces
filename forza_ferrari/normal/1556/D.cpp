#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,k,a[10001],val,tmp;
signed main()
{
    cin>>n>>k;
    for(register int i=2;i<=n;++i)
    {
        cout<<"and 1 "<<i<<endl;
        cin>>val;
        cout<<"or 1 "<<i<<endl;
        cin>>tmp;
        val+=tmp;
        a[i]=val;
    }
    cout<<"and 2 3"<<endl;
    cin>>val;
    cout<<"or 2 3"<<endl;
    cin>>tmp;
    val+=tmp;
    a[1]=(a[2]+a[3]-val)>>1;
    for(register int i=2;i<=n;++i)
        a[i]-=a[1];
    sort(a+1,a+n+1);
    cout<<"finish "<<a[k]<<endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,a[100005],visi[100005]={0},cur=0,i;
    char x[100005];
    cin>>n;
    for(i=0;i<n;++i)
    cin>>x[i];
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    a[i]*=((x[i]=='>')?1:-1);
    visi[0]=1;
    for(i=0;i<n;++i)
    {
        if(cur+a[cur]<0 || cur+a[cur]>=n) break;
        if(visi[cur+a[cur]]==1) {cout<<"INFINITE";exit(0);}
        else {visi[cur+a[cur]]=1;cur+=a[cur];}
    }
    cout<<"FINITE";
    return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100001],pos[100001][2],ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        pos[i][0]=m+1;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i];
        if(pos[a[i]][0]==m+1)
            pos[a[i]][0]=i;
        pos[a[i]][1]=i;
    }
    for(int i=1;i<=n;++i)
    {
        if(!pos[i][1])
            ++ans;
        if(i>1&&pos[i-1][1]<pos[i][0])
            ++ans;
        if(i<n&&pos[i+1][1]<pos[i][0])
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
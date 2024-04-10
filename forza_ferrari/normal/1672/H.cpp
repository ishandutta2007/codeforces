#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[200001],sum[200001][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        char c;
        cin>>c;
        a[i]=c^48;
        if(i==1)
            continue;
        sum[i][0]=sum[i-1][0];
        sum[i][1]=sum[i-1][1];
        if(a[i]==0&&a[i-1]==0)
            ++sum[i][0];
        if(a[i]==1&&a[i-1]==1)
            ++sum[i][1];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        if(l==r)
        {
            cout<<"1"<<endl;
            continue;
        }
        cout<<max(sum[r][0]-sum[l][0],sum[r][1]-sum[l][1])+1<<endl;
    }
    return 0;
}
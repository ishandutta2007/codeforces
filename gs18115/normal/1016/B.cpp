#include<iostream>
using namespace std;
char s[200000],t[200000];
int n,m,q,l,r,i,j;
int sum[200000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    cin>>s+1;
    cin>>t;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
            if(s[i+j]!=t[j])
                break;
        if(j==m)
            sum[i]=sum[i-1]+1;
        else
            sum[i]=sum[i-1];
    }
    while(q--)
    {
        cin>>l>>r;
        if(r-l<m-1)
            cout<<0<<'\n';
        else
            cout<<sum[r-m+1]-sum[l-1]<<'\n';
    }
    return 0;
}
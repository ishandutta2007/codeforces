#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,ta,N,tb,M,a[110][110],j;
string s1,s2,st;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>ta;
        N=N^ta;
        a[i][m]=ta;
    }
    for(i=1;i<=m;i++)
    {
        cin>>tb;
        M=M^tb;
        a[n][i]=tb;
    }
    if(N==M)
    {
        N=N^ta;
        a[n][m]=(tb^N);
        cout<<"YES\n";
        for(i=1;i<=n;i++)
        {
            for(j=1;j<m;j++)
                cout<<a[i][j]<<" ";
            cout<<a[i][m]<<"\n";
        }
    }
    else
        cout<<"NO\n";
}
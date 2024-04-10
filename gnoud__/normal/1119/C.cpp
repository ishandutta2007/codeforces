#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
const int N=510;
int m,n,a[N][N],b[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>m>>n;
    forinc(i,1,m) forinc(j,1,n) cin>>a[i][j];
    forinc(i,1,m) forinc(j,1,n) cin>>b[i][j];
    forinc(i,1,m)
    {
        int s=0;
        forinc(j,1,n) s^=(a[i][j]!=b[i][j]);
        if(s) return cout<<"No",0;
    }
    forinc(j,1,n)
    {
        int s=0;
        forinc(i,1,m) s^=(a[i][j]!=b[i][j]);
        if(s) return cout<<"No",0;
    }
    cout<<"Yes";
}
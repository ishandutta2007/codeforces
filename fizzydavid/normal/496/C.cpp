#include<bits/stdc++.h>
using namespace std;
#define R(i,n) for(i=0;i<n;i++)
int n,m,i,j,r;
char c[111][111];
bool f[111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;R(i,n)f[i]=1,cin>>c[i];
    R(i,m){
        R(j,n-1)if(f[j]&&c[j][i]>c[j+1][i])break;
        if(j==n-1){r++;R(j,n-1)f[j]&=(c[j][i]==c[j+1][i]);}
    }
    cout<<m-r;
}
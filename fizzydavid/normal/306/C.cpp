#include<bits/stdc++.h>
using namespace std;
#define R(i,x) for(int i=1;i<=x;i++)
#define M 1000000009
long long n,w,b,C[4011][4011],ans;
int main()
{
    C[0][1]=1;
    R(i,4000)R(j,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
    cin>>n>>w>>b;
    R(i,min(n-2,b))ans=(ans+C[b][i]*C[w][n-i]%M*(n-i-1)%M)%M;
    R(i,w)ans=ans*i%M;
    R(i,b)ans=ans*i%M;
    cout<<ans;
}
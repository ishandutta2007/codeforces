#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 36
int N,M;ll f[MAXN][MAXN];
int main()
{
    cin>>N>>M;For(i,0,N)f[0][i]=1;
    For(j,1,N)For(i,1,N)For(k,0,i-1)f[i][j]+=f[k][j-1]*f[i-k-1][j-1];
    cout<<f[N][N]-f[N][M-1]<<endl;return 0;
}
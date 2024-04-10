#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5001
int N,M,f[MAXN][MAXN],ans;string a,b;
int main(){cin>>N>>M>>a>>b,a=" "+a,b=" "+b;For(i,1,N)For(j,1,M)f[i][j]=max(f[i-1][j],f[i][j-1])-1,a[i]==b[j]?f[i][j]=max(f[i][j],f[i-1][j-1]+2):0,ans=max(ans,f[i][j]=max(f[i][j],0));cout<<ans<<endl;return 0;}
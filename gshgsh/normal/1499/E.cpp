#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 1001
int N,M,f[MAXN][MAXN][2],x[MAXN],y[MAXN],ans;string a,b;void upd(int &x,int y){x=(x+y)%P;}
int main()
{
	cin>>a>>b,N=a.length(),M=b.length(),a=" "+a,b=" "+b;For(i,1,N)x[i]=(a[i]!=a[i-1])*x[i-1]+1;For(i,1,M)y[i]=(b[i]!=b[i-1])*y[i-1]+1;
	For(i,1,N)For(j,1,M){if(a[i]!=a[i-1])upd(f[i][j][0],f[i-1][j][0]);if(b[j]!=b[j-1])upd(f[i][j][1],f[i][j-1][1]);if(a[i]!=b[j])upd(f[i][j][0],f[i-1][j][1]+y[j]),upd(f[i][j][1],f[i][j-1][0]+x[i]);}
	For(i,1,N)For(j,1,M)upd(ans,f[i][j][0]),upd(ans,f[i][j][1]);cout<<ans<<endl;return 0;
}
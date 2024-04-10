#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 101
int T,N,a[MAXN],f[MAXN][MAXN*25];
int main()
{
	N=MAXN-1;f[0][0]=1;For(i,1,N)For(j,0,i*25)For(k,0,min(j,25))f[i][j]=(f[i][j]+f[i-1][j-k])%P;
	cin>>T;while(T--){string s;cin>>s;N=s.length();int sum=0;For(i,0,N-1)sum+=s[i]-'a';cout<<f[N][sum]-1<<endl;}return 0;
}
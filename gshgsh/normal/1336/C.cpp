#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 4001
int N,M,s[MAXN],t[MAXN],f[MAXN][MAXN];
int main()
{
	string a,b;cin>>a>>b;N=a.length(),M=b.length();For(i,1,N)s[i]=a[i-1]-'a';For(i,1,M)t[i]=b[i-1]-'a';
	For(i,1,M)if(t[i]==s[1])f[i][i]=2;For(i,M+1,N)f[i][i]=2;
	For(l,1,N-1){For(i,1,N-l){int j=i+l;if(i>M||s[l+1]==t[i])f[i][j]=(f[i][j]+f[i+1][j])%P;if(j>M||s[l+1]==t[j])f[i][j]=(f[i][j]+f[i][j-1])%P;}}
	int ans=0;For(i,M,N)ans=(ans+f[1][i])%P;cout<<ans<<'\n';return 0;
}
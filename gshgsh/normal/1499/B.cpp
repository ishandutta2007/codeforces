#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 201
int T,N,a[MAXN],f[MAXN],g[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		string s;cin>>s;N=s.length();For(i,1,N)a[i]=s[i-1]-'0';For(i,0,N+1)f[i]=g[i]=0;f[0]=g[N+1]=1;
		f[1]=1;For(i,2,N)if(a[i-1]&&a[i]){f[i]=0;break;}else f[i]=1;g[N]=1;FOR(i,N-1,1)if(!a[i+1]&&!a[i]){f[i]=0;break;}else g[i]=1;
		bool flag=0;For(i,0,N)if(f[i]&&g[i+1]){cout<<"YES\n";flag=1;break;}if(!flag)cout<<"NO\n";
	}
	return 0;
}
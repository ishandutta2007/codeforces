#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 20
ll a[MAXN],b[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get();For(i,1,N)a[i]=get();ll ans=0;
		For(i,1,N){For(j,1,N)b[j]=a[j];For(j,1,N)if(j!=i){while(b[j]%2==0)b[j]/=2,b[i]*=2;}ll sum=0;For(j,1,N)sum+=b[j];ans=max(ans,sum);}
		cout<<ans<<'\n';
	}
	return 0;
}
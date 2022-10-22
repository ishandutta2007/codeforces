#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501

int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get(),K=get();
		if(K==1){cout<<"YES\n";For(i,1,N)cout<<i<<'\n';continue;}
		if(N&1){cout<<"NO\n";continue;}
		cout<<"YES\n";
		For(i,1,N/2){int x=(i-1)*2*K+1;For(j,1,K)cout<<x+(j-1)*2<<" \n"[j==K];For(j,1,K)cout<<x+j*2-1<<" \n"[j==K];}
	}
	return 0;
}
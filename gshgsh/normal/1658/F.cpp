#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,M,a[MAXN],s[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c=='1';}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=getc();int cnt=0;For(i,1,N)cnt+=a[i];if(1ll*cnt*M%N){cout<<"-1\n";continue;}
		int x=1ll*cnt*M/N;For(i,1,N)s[i]=s[i-1]+a[i];
		bool flag=0;For(i,M,N)if(s[i]-s[i-M]==x){cout<<"1\n"<<i-M+1<<' '<<i<<'\n';flag=1;break;}if(flag)continue;
		cout<<"2\n";For(i,1,M-1)if(s[i]+s[N]-s[N-M+i]==x){cout<<"1 "<<i<<'\n'<<N-M+i+1<<' '<<N<<'\n';break;}
	}
}
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int T,N,a[MAXN],x;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check0(){For(i,1,N)if(a[i]!=x)return 0;return 1;}
int check1(){For(i,1,N){bool flag=1;for(int j=i;j<=N;j+=i)flag&=a[j]==x;if(flag)return i;}return 0;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();char c;cin>>c;x=c-'a';For(i,1,N)cin>>c,a[i]=c-'a';
		if(check0()){cout<<"0\n";continue;}int x=check1();if(x){cout<<"1\n"<<x<<'\n';continue;}
		cout<<"2\n"<<N<<' ';For(i,1,N)if(N%i){cout<<i<<'\n';break;}
	}
	return 0;
}
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
ll pow(int a,int b){ll ans=1;For(i,1,b)ans*=a;return ans;}
char cmp(ll a,ll b){return a==b?'=':a>b?'>':'<';}
int main()
{
	int T=get();
	while(T--)
	{
		int x1=get(),p1=get(),x2=get(),p2=get();
		if(p1>p2+8)cout<<">\n";else if(p1<p2-8)cout<<"<\n";else cout<<cmp(x1*pow(10,p1-min(p1,p2)),x2*pow(10,p2-min(p1,p2)))<<'\n';
	}
	return 0;
}
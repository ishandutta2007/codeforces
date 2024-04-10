#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001

int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get(),cnt0=0,cnt1=0;For(i,1,N){char c;cin>>c;c=='1'?cnt1++:cnt0++;}
		if(abs(cnt1-cnt0)<=1&&cnt1<=1&&cnt0<=1)cout<<"YES\n";else cout<<"NO\n";
	}
	return 0;
}
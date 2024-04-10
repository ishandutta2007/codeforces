#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,M,a[MAXN];int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	cin>>N>>M;For(i,1,N){char c;cin>>c;a[i]=c-'a'+1+a[i-1];}
	For(i,1,M){int l=get(),r=get();cout<<a[r]-a[l-1]<<endl;}return 0;
}
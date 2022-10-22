#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 10001
int T,N,a[MAXN];
int ask(int a,int b,int c){cout<<"? "<<a<<" "<<b<<" "<<c<<endl;int x;cin>>x;return x;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		int lst=-1,y,z;For(i,1,N){int x=ask(i,i%N+1,(i+1)%N+1);if(lst!=-1&&x!=lst){y=i-1;z=(i+1)%N+1;break;}lst=x;}
		For(i,1,N)if(i!=y&&i!=z)a[i]=ask(i,y,z);
		int u=0,v=0;For(i,1,N)if(a[i]&&i!=y&&i!=z){u=i;break;}For(i,1,N)if(!a[i]&&i!=y&&i!=z){v=i;break;}
		a[y]=ask(u,v,y);a[z]=ask(u,v,z);int cnt=0;For(i,1,N)cnt+=!a[i];cout<<"! "<<cnt<<' ';For(i,1,N)if(!a[i])cout<<i<<' ';cout<<endl;
	}
	return 0;
}
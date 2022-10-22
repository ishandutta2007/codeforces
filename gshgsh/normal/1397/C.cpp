#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N;ll a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();
	if(N==1){cout<<"1 1\n"<<-a[1]<<"\n1 1\n0\n1 1\n0\n";return 0;}
	cout<<"1 "<<N<<"\n0 ";For(i,2,N)cout<<1ll*(N-1-a[i])*N<<" \n"[i==N],a[i]+=1ll*(N-1-a[i])*N;
	cout<<"1 1\n"<<-a[1]<<'\n';cout<<"2 "<<N<<'\n';For(i,2,N)cout<<-a[i]<<" \n"[i==N];return 0;
}
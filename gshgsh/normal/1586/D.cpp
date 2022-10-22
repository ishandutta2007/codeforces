#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
int N,a[MAXN];
int main()
{
	cin>>N;
	FOR(i,N,2){cout<<"? ";For(j,1,N-1)cout<<i<<' ';cout<<1<<endl;int x;cin>>x;if(!x)continue;if(!a[N])a[N]=i,a[x]=1;else a[x]=a[N]-i+1;}
	For(i,2,N){cout<<"? ";For(j,1,N-1)cout<<"1 ";cout<<i<<endl;int x;cin>>x;if(!x)continue;if(!a[N])a[N]=1,a[x]=i;else a[x]=i+a[N]-1;}
	cout<<"! ";For(i,1,N)cout<<a[i]<<' ';cout<<endl;return 0;
}
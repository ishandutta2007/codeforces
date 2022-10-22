#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 10001
int N,a[MAXN],pos[MAXN];int ask(int x,int y){cout<<"? "<<x<<' '<<y<<endl;int a;cin>>a;return a;}
int main()
{
	cin>>N;For(i,1,N-1)For(j,i+1,N)if(!a[i]&&!a[j]){int x=ask(i,j),y=ask(j,i);if(x>y)a[i]=x,pos[x]=i;else a[j]=y,pos[y]=j;}
	For(i,1,N)if(!a[i]){if(pos[N])a[i]=ask(i,pos[N]);else a[i]=N;}cout<<"! ";For(i,1,N)cout<<a[i]<<' ';cout<<endl;return 0;
}
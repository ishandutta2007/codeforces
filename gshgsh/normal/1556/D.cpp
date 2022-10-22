#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,K,a[MAXN];
int Or(int x,int y){cout<<"or "<<x<<' '<<y<<endl;int a;cin>>a;return a;}
int And(int x,int y){cout<<"and "<<x<<' '<<y<<endl;int a;cin>>a;return a;}
int main()
{
	cin>>N>>K;
	For(i,1,N/3)
	{
		int x=i*3-2,y=i*3-1,z=i*3;
		int XorY=Or(x,y),XorZ=Or(x,z),XandY=And(x,y),XandZ=And(x,z),YorZ=Or(y,z);
		a[x]=(XandY|XandZ)^(XorY|XorZ)^YorZ;a[y]=a[x]^XorY^XandY;a[z]=a[x]^XorZ^XandZ;
	}
	if(N>=N/3*3+1)a[N/3*3+1]=a[1]^Or(1,N/3*3+1)^And(1,N/3*3+1);if(N>=N/3*3+2)a[N/3*3+2]=a[1]^Or(1,N/3*3+2)^And(1,N/3*3+2);
	sort(a+1,a+N+1);cout<<"finish "<<a[K]<<endl;return 0;
}
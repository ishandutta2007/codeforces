#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int l,r,M,u[MAXN],v[MAXN],w[MAXN];
void add(int x,int y,int z){u[++M]=x,v[M]=y,w[M]=z;}
int main()
{
	cin>>l>>r;int sum=r-l;For(i,2,22){add(1,i,1);For(j,2,i-1)add(j,i,1<<j-2);}add(1,23,l);For(i,0,20)if((sum>>i)&1)sum^=1<<i,add(i+2,23,l+sum);
	cout<<"YES\n23 "<<M<<endl;For(i,1,M)cout<<u[i]<<' '<<v[i]<<' '<<w[i]<<endl;return 0;
}
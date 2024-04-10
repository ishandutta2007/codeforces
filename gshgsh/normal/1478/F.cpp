#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5001
int N,x[MAXN],y[MAXN],p[MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>x[i]>>y[i],p[i]=i;
	For(i,1,N){cout<<p[i]<<' ';For(j,i+2,N)if(1ll*(x[j]-x[i])*(x[j]-x[i])+1ll*(y[j]-y[i])*(y[j]-y[i])>1ll*(x[i+1]-x[i])*(x[i+1]-x[i])+1ll*(y[i+1]-y[i])*(y[i+1]-y[i]))swap(x[i+1],x[j]),swap(y[i+1],y[j]),swap(p[i+1],p[j]);}return 0;
}
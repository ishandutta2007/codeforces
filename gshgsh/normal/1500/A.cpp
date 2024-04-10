#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5000001
int N,a[MAXN],x[MAXN],y[MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];
	For(i,1,N)For(j,i+1,N){int s=a[i]+a[j];if(x[s]&&i!=x[s]&&i!=y[s]&&j!=x[s]&&j!=y[s]){cout<<"YES\n"<<i<<' '<<j<<' '<<x[s]<<' '<<y[s]<<endl;return 0;}x[s]=i,y[s]=j;}
	cout<<"NO\n";return 0;
}
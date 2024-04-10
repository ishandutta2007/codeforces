#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN],b[MAXN],c[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i]>>b[i];For(i,1,N)cin>>c[i];
		int x=0;For(i,1,N){x+=a[i]-b[i-1]+c[i];if(i<N)x=max(b[i],x+(b[i]-a[i]+1)/2);}cout<<x<<endl;
	}
	return 0;
}
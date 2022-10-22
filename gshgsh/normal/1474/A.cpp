#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN],c[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';}
		b[1]=1,c[1]=a[1]+b[1];For(i,1,N){if(a[i]+1!=c[i-1])b[i]=1,c[i]=a[i]+1;else b[i]=0,c[i]=a[i];}
		For(i,1,N)cout<<b[i];cout<<endl;
	}
	return 0;
}
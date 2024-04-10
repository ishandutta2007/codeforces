#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,A,B,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N,A=B=0;For(i,1,N)cin>>a[i];For(i,1,N)cin>>b[i],b[i]?c[++A]=a[i]:d[++B]=a[i];sort(d+1,d+B+1,greater<int>());
		int j=1,k=1;For(i,1,N)cout<<(b[i]?c[j++]:d[k++])<<' ';cout<<endl;
	}
	return 0;
}
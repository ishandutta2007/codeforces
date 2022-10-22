#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define P 1000000007
#define MAXN 100001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];int x=1;For(i,2,N)a[i]<a[x]?x=i:0;
		cout<<N-1<<endl;For(i,1,N)if(i!=x)cout<<i<<' '<<x<<' '<<P-1+abs(i-x)<<' '<<a[x]<<endl;
	}
	return 0;
}
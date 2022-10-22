#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,x,y,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>x>>y;For(i,1,N)cin>>a[i];bool flag=0;For(i,2,N)if(max(a[i]-a[i-1],a[i-1]-a[i])>1){cout<<0<<endl;flag=1;break;}if(flag)continue;
		For(i,2,N)if(a[i]!=a[i-1]){cout<<min(x,y)<<endl;flag=1;break;}if(flag)continue;cout<<y+min(x,y)<<endl;
	}
	return 0;
}
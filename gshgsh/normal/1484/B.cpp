#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int mx=0;For(i,1,N)cin>>a[i],mx=max(mx,a[i]);if(N==1){cout<<0<<endl;continue;}int v1=0,v2=0,v3=0,flag=1;For(i,2,N)a[i]>a[i-1]?v1&&v1!=a[i]-a[i-1]?flag=0:v1=a[i]-a[i-1]:a[i]<a[i-1]?v2&&v2!=a[i-1]-a[i]?flag=0:v2=a[i-1]-a[i]:v3=1;
		if(!flag||(v3&&(v1||v2)))cout<<-1<<endl;else if(v3||(v1&&!v2)||(v2&&!v1))cout<<0<<endl;else if(v1+v2<=mx)cout<<-1<<endl;else cout<<v1+v2<<' '<<v1<<endl;
	}
	return 0;
}
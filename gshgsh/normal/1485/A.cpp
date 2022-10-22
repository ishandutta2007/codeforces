#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,a,b;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b;int ans=b==1;int tmp=a;while(tmp)tmp/=max(b,2),ans++;
		For(i,b+1,b+10000){if(i-b>ans)break;int tmp=a,sum=i-b;while(tmp)tmp/=i,sum++;ans=min(ans,sum);}cout<<ans<<endl;
	}
	return 0;
}
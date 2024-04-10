#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,a,b;string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>s;int N=s.length(),id=N,cnt=0,ans=0;For(i,0,N-1)if(s[i]=='1'&&(i==N-1||s[i+1]=='0')){id=i+1;ans=a;break;}
		For(i,id,N-1)if(s[i]=='0')cnt++;else if(i==N-1||s[i+1]=='0')ans+=min(a,b*cnt),cnt=0;cout<<ans<<endl;
	}
	return 0;
}
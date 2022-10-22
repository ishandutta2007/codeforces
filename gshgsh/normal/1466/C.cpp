#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T;string a;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a;int N=a.length(),ans=0;a=" "+a;a=a+" ";
		For(i,2,N)if(a[i]==a[i-1]||a[i]==a[i-2]){ans++;For(j,'a','z')if(a[i-1]!=j&&a[i-2]!=j&&a[i+1]!=j&&a[i+2]!=j){a[i]=j;break;}}
		cout<<ans<<endl;
	}
	return 0;
}
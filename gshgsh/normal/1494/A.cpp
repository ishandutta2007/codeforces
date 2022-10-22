#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int T;string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;int N=s.length();
		bool flag=0;For(i,0,7){int sum=0;For(j,0,N-1){sum+=(i>>s[j]-'A')&1?1:-1;if(sum<0)break;}if(sum==0){cout<<"YES\n";flag=1;break;}}
		if(!flag)cout<<"NO\n";
	}
	return 0;
}
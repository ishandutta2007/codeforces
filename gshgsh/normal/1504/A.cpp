#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T;string s;bool check(string s){int N=s.length();For(i,1,N/2)if(s[i-1]!=s[N-i])return 1;return 0;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;int N=s.length();bool flag=0;For(i,0,N-1)if(s[i]!='a')flag=1;
		cout<<(flag?"YES\n":"NO\n");if(flag){string t1="a"+s,t2=s+"a";if(check(t1))cout<<t1<<endl;else cout<<t2<<endl;}
	}
	return 0;
}
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
int T,x,y;string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x>>y>>s;int N=s.length(),sum1=0,sum2=0;For(i,0,N-1)sum1+=(x>0?s[i]=='R':s[i]=='L'),sum2+=(y>0?s[i]=='U':s[i]=='D');
		if(sum1>=abs(x)&&sum2>=abs(y))cout<<"YES\n";else cout<<"NO\n";
	}
	return 0;
}
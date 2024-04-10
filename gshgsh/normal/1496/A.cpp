#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,K;string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K>>s;if(K*2==N){cout<<"NO\n";continue;}
		bool flag=1;For(i,0,K-1)if(s[i]!=s[N-i-1]){flag=0;break;}cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}
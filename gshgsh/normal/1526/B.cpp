#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,x;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x;if(x>11*111){cout<<"YES\n";continue;}
		bool flag=0;For(i,0,x/111)if((x-i*111)%11==0){flag=1;break;}cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}
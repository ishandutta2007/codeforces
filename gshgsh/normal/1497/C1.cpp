#include<iostream>
using namespace std;
#define ll long long
int T,N,K;
int GCD(int a,int b){return b?GCD(b,a%b):a;}ll lcm(int a,int b){return 1ll*a*b/GCD(a,b);}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;
		int x=1;while(x<N){if(N-x&1){x<<=1;continue;}if(lcm(x,N-x>>1)*2<=N)break;x<<=1;}
		cout<<x<<' '<<(N-x>>1)<<' '<<(N-x>>1)<<endl;
	}
	return 0;
}
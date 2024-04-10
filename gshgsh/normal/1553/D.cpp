#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,M;string a,b;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b;N=a.length(),M=b.length();a=" "+a,b=" "+b;if(N<M){cout<<"NO\n";continue;}
		int i=(N-M&1)+1,j=1;while(i<=N&&j<=M)if(a[i]==b[j])i++,j++;else i+=2;
		if(j>M)cout<<"YES\n";else cout<<"NO\n";
	}
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,tot,ans,sta[MAXN];string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;N=s.length();s=" "+s;ans=N,tot=0;FOR(i,N,1){if(s[i]=='B')sta[++tot]=1;else if(sta[tot]==1)tot--,ans-=2;else sta[++tot]=-1;}
		while(tot>=2&&sta[tot]==1&&sta[tot-1]==1)ans-=2,tot-=2;cout<<ans<<endl;
	}
	return 0;
}
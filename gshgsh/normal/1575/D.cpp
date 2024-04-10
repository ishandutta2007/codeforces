#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
bool check(int val,string s)
{
	int N=s.length();int tmp=val;
	int x=-1;FOR(i,N-1,0){if(s[i]=='X'){if(x!=-1&&x!=val%10)return 0;x=val%10;}else if(s[i]!='_'&&s[i]!=val%10+'0')return 0;val/=10;}
	return 1;
}
int main()
{
	string s;cin>>s;int N=s.length();if(N>1&&s[0]=='0'){cout<<0;return 0;}int mx=1;For(i,1,N)mx*=10;
	int ans=0;for(int i=N==1?0:(mx/10+24)/25*25;i<mx;i+=25)if(check(i,s))ans++;cout<<ans<<'\n';return 0;
}
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(string s){int M=s.length();For(i,1,M-1)if(s[i]!=s[i-1])return 0;return 1;}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get();string s;cin>>s;if(check(s)){cout<<N<<'\n';continue;}if(s[0]=='D')for(auto&i:s)i='D'+'R'-i;
		ll ans=1ll*N*N;int sum1=0,sum2=0;for(auto i:s)if(i=='D')sum1++;sum2=sum1;
		int now=1;for(auto i:s){if(i=='R')ans-=N-now;else{while(sum1<N-1)now++,sum1++;now++;}}
		now=N-sum2;reverse(s.begin(),s.end());for(auto i:s){if(i=='R')ans-=N-now;else now++;}
		cout<<ans<<'\n';
	}
	return 0;
}
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int T,N,cnt[26];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,0,25)cnt[i]=0;For(i,1,N){string s;cin>>s;for(auto j:s)cnt[j-'a']++;}
		bool flag=1;For(i,0,25)if(cnt[i]%N){cout<<"NO\n";flag=0;break;}if(flag)cout<<"YES\n";
	}
	return 0;
}
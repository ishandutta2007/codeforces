#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,K,cnt1[26],cnt2[26];string a;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;For(i,0,25)cnt1[i]=cnt2[i]=0;cin>>a;For(i,0,N-1)cnt1[a[i]-'a']++;cin>>a;For(i,0,N-1)cnt2[a[i]-'a']++;
		int sum=0;bool flag=1;For(i,0,25){if(cnt1[i]+sum<cnt2[i]||(cnt1[i]+sum-cnt2[i])%K){cout<<"NO\n";flag=0;break;}sum+=cnt1[i]-cnt2[i];}if(flag)cout<<"YES\n";
	}
	return 0;
}
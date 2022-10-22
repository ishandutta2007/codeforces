#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005,P=31,mod=98244353;
int h1[N],h2[N],p[N]={1},n;
string s;
int is_p(int l,int r)
{
	return ((h1[r]-h1[l-1]*p[r-l+1]%mod+mod)%mod)==((h2[l]-h2[r+1]*p[r-l+1]%mod+mod)%mod);
}
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=1;i<=1000000;i++)
		p[i]=p[i-1]*P%mod;
	while(t--)
	{
		cin>>s;
		n=s.size();
		s="#"+s;
		for(int i=1;i<=n;i++)
			h1[i]=(h1[i-1]*P+s[i]-'a')%mod;
		h2[n+1]=0;
		for(int i=n;i>=1;i--)
			h2[i]=(h2[i+1]*P+s[i]-'a')%mod;
		int l=1,r=n;
		while(s[l]==s[r])
		{
			l++;
			r--;
		}
		if(r<l)
		{
			cout<<s.substr(1,n)<<endl;
			continue;
		}
		int mxl=1,mxr=1;
		for(int i=l;i<=r;i++)
		{
			if(is_p(l,i))
				mxl=i-l+1;
		}
		for(int i=r;i>=l;i--)
		{
			if(is_p(i,r))
				mxr=r-i+1;
		}
		if(mxl>mxr)
		{
			for(int i=1;i<=l+mxl-1;i++)
				cout<<s[i];
			for(int i=r+1;i<=n;i++)
				cout<<s[i];
		}
		else
		{
			for(int i=1;i<l;i++)
				cout<<s[i];
			for(int i=r-mxr+1;i<=n;i++)
				cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
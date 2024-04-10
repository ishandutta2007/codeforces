#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
char has[1000005];
string s[1000005];
char c[1000005];
vector<string>t;
map<string,char>mp;
char ans[1000005];
bool check()
{
	for(int i=1;i<=n+n-2;i++)
	{
		if(mp.find(s[i])!=mp.end())
		{
			if(mp[s[i]]=='S')return false;
			int vis=0;
			int p=s[i].size();
			for(int j=0;j<p;j++)
			{
				if(has[n-p+j+1]!=s[i][j])
				{
					vis=1;
					break;
				}
			}
			if(!vis)
			{
				mp[s[i]]='S';
				ans[i]='S';
				continue;
			}
			return false;
		}
		int p=s[i].size();
		int vis=0;
		for(int j=0;j<p;j++)
		{
			if(has[j+1]!=s[i][j])
			{
				vis=1;
				break;
			}
		}
		if(!vis)
		{
			mp[s[i]]='P';
			ans[i]='P';
			continue;
		}
		vis=0;
		for(int j=0;j<p;j++)
		{
			if(has[n-p+j+1]!=s[i][j])
			{
				vis=1;
				break;
			}
		}
		if(!vis)
		{
			mp[s[i]]='S';
			ans[i]='S';
			continue;
		}
		return false;
	}
	return true;
}
signed main() {
	n=read();
	for(int i=1;i<=n+n-2;i++)
	{
		scanf("%s",c);
		s[i]=c;
		if(s[i].size()==n-1)t.push_back(s[i]);
	}
	mp.clear();
	int vis=0;
	for(int i=1;i<=n-1;i++)has[i]=t[0][i-1];
	for(int i=2;i<=n;i++)
	{
		if(i<n&&has[i]!=t[1][i-2])vis=1;
		has[i]=t[1][i-2];
	}
	has[0]=']';
//	cout<<has<<endl;
//	return 0;
	if(!vis)
	{
//		cout<<"QWeqeqe"<<endl;
		if(check())
		{
			for(int i=1;i<=2*n-2;i++)cout<<ans[i];
			puts("");
			return 0;
		}
	}
	mp.clear();
	for(int i=1;i<=n-1;i++)has[i]=t[1][i-1];
	for(int i=2;i<=n;i++)
	{
		if(i<n&&has[i]!=t[0][i-2])vis=1;
		has[i]=t[0][i-2];
	}
	if(check())
	{
		for(int i=1;i<=2*n-2;i++)cout<<ans[i];
		puts("");
		return 0;
	}
	return 0;
}
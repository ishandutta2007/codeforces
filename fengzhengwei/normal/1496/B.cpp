#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int T;
int n,m;
int a[xx];
map<int,int>mp;
signed main(){
	T=read();
	while(T--)
	{
		mp.clear();
		n=read();
		m=read();
		int maxx=0;
		int ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),mp[a[i]]++,maxx=max(maxx,a[i]),(mp[a[i]]==1?ans++:0);
		int now=0;
		for(int i=0;i<=n;i++)
		{
			if(!mp[i])
			{
				now=i;break;
			}
		}
		if(now==n)
		{
			cout<<n+m<<"\n";
			continue;
		}
		if(m<=n)
		{
			for(int i=1;i<=m;i++)
			{
				mp[(1+maxx+now)>>1]++;
				if(mp[(1+maxx+now)>>1]==1)ans++;
				maxx=max(maxx,((1+maxx+now)>>1));
				while(mp[now])now++;
			}
			cout<<ans<<'\n';
		}
		else 
		{
			for(int i=1;i<=n;i++)
			{
				mp[(1+maxx+now)>>1]++;
				if(mp[(1+maxx+now)>>1]==1)ans++;
				maxx=max(maxx,((1+maxx+now)>>1));
				while(mp[now])now++;
			}
			m-=n;
			if(now==maxx+1)cout<<ans+m<<'\n';
			else cout<<ans<<'\n';
		}
	}
	return 0;
}
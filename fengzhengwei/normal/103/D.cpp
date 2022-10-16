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
const int xx=3e5+5;
int n,a[xx];
ll ans[xx];
ll sum[xx];
vector<pair<int,int> >v[505];//tid 
signed main(){
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int B=500;
	int m=read();
	for(int i=1;i<=m;i++)
	{
		int t,s;
		t=read();
		s=read();
		if(s<=B)v[s].push_back(make_pair(t,i));
		else 
		{
			ll now=t,res=0;
			while(now<=n)res+=a[now],now+=s;
			ans[i]=res;
		}
	}
	for(int i=1;i<=B;i++)
	{
		memset(sum,0,sizeof(sum));
		for(int j=n;j>=1;j--)
		{
			sum[j]+=a[j];
//			cout<<j<<" "<<i<<" "<<j-i<<"\n";
			if(j>i)sum[j-i]+=sum[j];
		}
		for(int j=0;j<v[i].size();j++)ans[v[i][j].second]=sum[v[i][j].first];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
map<int,int>mp;
void add(int x,int y)
{
	if(mp.find(x)==mp.end())mp[x]=y;
	else mp[x]=min(mp[x],y);
}
const int xx=305;
int n,v[xx],c[xx];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main(){
	n=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)
	{
		add(v[i],c[i]);
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)add(gcd(it->first,v[i]),c[i]+it->second);
	}
	if(mp.find(1)==mp.end())puts("-1");
	else cout<<mp[1]<<"\n";
	return 0;
}
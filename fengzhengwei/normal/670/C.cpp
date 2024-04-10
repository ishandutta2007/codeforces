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
int n;
int m;
int tot;
int s[1000005];
int p[1000005];
int a[1000005];
int b[1000005];
int t[1000005];
signed main(){
	m=read();
	for(int i=1;i<=m;i++)p[i]=s[++tot]=read();
	n=read();
	for(int i=1;i<=n;i++)a[i]=s[++tot]=read();
	for(int i=1;i<=n;i++)b[i]=s[++tot]=read();
	sort(s+1,s+tot+1);
	tot=unique(s+1,s+tot+1)-s-1;
	for(int i=1;i<=m;i++)p[i]=lower_bound(s+1,s+tot+1,p[i])-s,t[p[i]]++;
	int maxx=0;
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(s+1,s+tot+1,a[i])-s;
		b[i]=lower_bound(s+1,s+tot+1,b[i])-s;
		if(maxx<t[a[i]])
		{
			v.clear();
			maxx=t[a[i]];
		}
		if(maxx==t[a[i]])v.push_back(i);
	}
	int pos=0;
	maxx=-1;
	for(int i=0;i<v.size();i++)
	{
		if(maxx<t[b[v[i]]])maxx=t[b[v[i]]],pos=v[i];
	}
	cout<<pos<<endl;
	return 0;
}
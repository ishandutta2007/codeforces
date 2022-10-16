#include<bits/stdc++.h>
#define ll long long
using namespace std;
//char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=5e5+5;
struct nod{int val,t;};
struct xxj
{
	nod s[22];
	void insert(nod w)
	{
		for(int i=20;i>=0;i--)
		if(w.val>>i&1)
		{
			if(!s[i].val||s[i].t<w.t)swap(s[i],w);
			w.val^=s[i].val;
		}
	}
	int get(int x)
	{
		int t=0;
		for(int i=20;i>=0;i--)if(s[i].t>=x&&(t<(t^s[i].val)))t^=s[i].val;
		return t;
	}
}e[xx];
int n;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)e[i]=e[i-1],e[i].insert((nod){read(),i});
	int q=read();
	while(q--)
	{
		int l=read(),r=read();
		cout<<e[r].get(l)<<"\n";
	}
	return 0;
}
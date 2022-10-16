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
const int xx=2e5+5;
struct node{int next,to;}e[xx<<1];
int rd[xx],h[xx],vis[xx],cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	rd[y]++;
}
signed main(){
	int T=read();
	while(T--)
	{
		memset(e,0,sizeof(e[0])*(cnt+1));
		int n=read();
		memset(h,0,sizeof(h[0])*(n+1));
		memset(rd,0,sizeof(rd[0])*(n+1));
		cnt=0;
		memset(vis,0,sizeof(vis[0])*(n+1));
		for(int i=1;i<=n;i++)
		{
			int s=read();
			while(s--)add(read(),i);
		}
		multiset<int>s;
		for(int i=1;i<=n;i++)if(!rd[i])s.insert(i);
		int tt=0,last=1;
		while(!s.empty())
		{
			multiset<int>::iterator it=s.lower_bound(last);
			if(it==s.end())last=1,tt++,it=s.lower_bound(last);
			last=*it;
			int x=*it;
			vis[x]=1;
//			cout<<x<<'\n';
			s.erase(it);
			for(int i=h[x];i;i=e[i].next)
			{
				rd[e[i].to]--;
				if(!rd[e[i].to])s.insert(e[i].to);
			}
		}
		int op=1;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				op=0;
				puts("-1");
				break;
			}
		}
		if(!op)continue;
		cout<<tt+1<<"\n";
	}
    return 0;
}
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
const int xx=1e6+5;
int n;
ll a[xx];
ll val[xx];
int dist[xx];
int size[xx];
int c[xx][2];
ll ans[xx];
void ph(int x)
{
	size[x]=size[c[x][0]]+1+size[c[x][1]];
}
int merge(int x,int y)
{
	if(!x||!y)return ph(x+y),x+y;
	if(val[x]<val[y])swap(x,y);
	c[x][1]=merge(c[x][1],y);
	if(dist[c[x][0]]<dist[c[x][1]])swap(c[x][0],c[x][1]);
	dist[x]=dist[c[x][1]]+1;
	ph(x);
	return x;
}
signed main(){
	dist[0]=-1;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()-i,val[i]=a[i],size[i]=1;
	deque<int>q1,q2;//q2?size 
	int tot=1;
	while(tot<=n)
	{
		int now=tot;
		tot++;
//		cout<<now<<" "<<tot<<" "<<size[now]<<endl;
		int s=size[now];
		while(q1.size()&&val[q1.back()]>=val[now])
		{
			s+=q2.back();
			now=merge(now,q1.back());
			while(size[now]!=(s+2)/2)now=merge(c[now][0],c[now][1]);
			q1.pop_back();
			q2.pop_back();
		}
		q1.push_back(now);
		q2.push_back(s);
//		cout<<size[now]<<" "<<val[now]<<endl;
	}
	tot=0;
	while(q1.size())
	{
		int size=q2.front();
		for(int i=1;i<=size;i++)
		{
			tot++;
			ans[tot]=val[q1.front()];
		}
		q1.pop_front();
		q2.pop_front();
	}
	ll res=0;
	for(int i=1;i<=n;i++)res+=abs(ans[i]-a[i]);
	cout<<res<<"\n";
	return 0;
}
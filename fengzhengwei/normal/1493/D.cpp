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
int vis[xx];
vector<int>v[xx];
ll gcd;
void pre()
{
	int n=xx-1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			for(int j=1;;j++)
			{
				if(j*i>n)break;
				vis[j*i]=1;
				int now=j*i;
				while(now%i==0)v[j*i].push_back(i),now/=i;
			}
		}
	}
}
int n,m;
struct node
{
	int l,r,minn;
}e[xx<<6];
map<int,int>root;
int cst;
void insert(int &k,int l,int r,int x,int y)
{
	if(!k)k=++cst;
	if(l==r)return e[k].minn+=y,void();
	int mid=l+r>>1;
	if(x<=mid)insert(e[k].l,l,mid,x,y);
	else insert(e[k].r,mid+1,r,x,y);
	e[k].minn=min(e[e[k].l].minn,e[e[k].r].minn);
}
const int mod=1e9+7;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	pre();
	gcd=1;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int j=0;
		int s=read();
		if(s==1)continue;
		while(1)
		{
			int now=v[s][j];
			int tot=0;
//			cout<<j<<"qweqe"<<endl;
			while(j<v[s].size()&&v[s][j]==now)j++,tot++;
			insert(root[now],1,n,i,tot);
			if(i==n)
			{
				int o=e[root[now]].minn;
				while(o--)gcd*=now,gcd%=mod;
			}
			if(j==v[s].size())break;
		}
	}
//	cout<<"qweqe"<<endl;
	for(int i=1;i<=m;i++)
	{
		int a;
		a=read();
		int s=read();
		if(s==1)
		{
			cout<<gcd<<"\n";
			continue;
		}
		int j=0;
		while(1)
		{
			int now=v[s][j];
			int tot=0;
			while(j<v[s].size()&&v[s][j]==now)j++,tot++;
			int o=e[root[now]].minn;
			insert(root[now],1,n,a,tot);
			o=e[root[now]].minn-o;
			while(o--)gcd*=now,gcd%=mod;
			if(j==v[s].size())break;
		}
		cout<<gcd<<"\n";
	}
	return 0;
}
/*
4 3
123123 45564 13113 55548
1 12
2 3
3 3
*/
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
int n,k,m;
ll sum[4000005];
ll sss[4000005];
vector<pair<int,int> >v[1000005];//q;
void insert(int k,int l,int r,ll v,ll q)//v 
{
	sss[k]+=q*v;
	sum[k]+=q;
	if(l==r)return;
	int mid=l+r>>1;
	if(v<=mid)insert(k<<1,l,mid,v,q);
	else insert(k<<1|1,mid+1,r,v,q);
}
ll ans=0;
void ask(int k,int l,int r,ll s)
{
	if(!s)return;
	if(l==r)
	{
		ans+=s*l;
		return;
	}
	int mid=l+r>>1;
	if(sum[k<<1]>=s)ask(k<<1,l,mid,s);
	else ans+=sss[k<<1],ask(k<<1|1,mid+1,r,s-sum[k<<1]);
}
int main(){
	n=read();
	k=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int l,r,c,p;
		l=read();
		r=read();
		c=read();
		p=read();
		v[l].push_back(make_pair(c,p));
		v[r+1].push_back(make_pair(-c,p));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)insert(1,1,1e6,v[i][j].second,v[i][j].first);
		if(sum[1]<=k)ans+=sss[1];
		else ask(1,1,1e6,k);
	}
	cout<<ans<<endl;
	return 0;
}
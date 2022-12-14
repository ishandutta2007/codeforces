#include<bits/stdc++.h> 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,G,mxg,mng=2e9,Ans[300005];
char s[10];
vector<int> g;
vector<pair<int,int> > b,r;
long long ans;
void Solve(vector<pair<int,int> >&r)
{
	for(int i=0,j;i<r.size();i=j+1)
	{
		for(j=i;j<r.size()&&r[j].second==0;++j);
		if(j>=r.size()) ans+=r.back().first-r[i-1].first;
		else if(!i) ans+=r[j].first-r[0].first;
		else 
		{
			int mx=0;
			for(int k=i;k<=j;++k) mx=max(mx,r[k].first-r[k-1].first);
			ans+=r[j].first-r[i-1].first-mx;
			Ans[r[j].second]+=r[j].first-r[i-1].first-mx;
		}
	}	
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();scanf("%s",s+1);
		if(s[1]=='G') G=1,mxg=max(mxg,x),mng=min(mng,x),g.push_back(x);
		if(s[1]=='R'||s[1]=='G') r.push_back(make_pair(x,s[1]=='G'?g.size():0));
		if(s[1]=='B'||s[1]=='G') b.push_back(make_pair(x,s[1]=='G'?g.size():0)); 
	}
	if(!G)
	{
		ans=(r.size()?r.back().first-r[0].first:0)+(b.size()?b.back().first-b[0].first:0);
		printf("%lld\n",ans);
		return 0;
	}
	ans=mxg-mng;
	Solve(r);Solve(b);
	for(int i=1;i<g.size();++i) 
		if(Ans[i+1]>g[i]-g[i-1]) ans-=Ans[i+1]-(g[i]-g[i-1]); 
	cout<<ans;
	return 0;
}
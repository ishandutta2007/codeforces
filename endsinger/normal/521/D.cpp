#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
struct fen
{
	int p,q,id;
	fen(){}
	fen(int _p,int _q,int _id):p(_p),q(_q),id(_id){}
	bool operator<(const fen k)const
	{
		return (__int128)p*k.q<(__int128)q*k.p;
	}
};
int k,n,m,a[N],ty[N];
pair<int,int>mx[N];
vector<pair<int,int>>e[N];
vector<fen>g;
vector<int>r;
bool cmp(int x,int y)
{
	return ty[x]<ty[y];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>k>>n>>m;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int t,x,y;
		cin>>t>>x>>y;
		ty[i]=t;
		if(t==1)
			mx[x]=max(mx[x],make_pair(y,i));
		if(t==2)
			e[x].emplace_back(y,i);
		if(t==3)
			g.emplace_back(fen(y,1,i));
	}
	for(int i=1;i<=k;i++)
		if(mx[i].first>a[i])
			e[i].emplace_back(mx[i].first-a[i],mx[i].second);
	for(int i=1;i<=k;i++)
	{
		sort(e[i].begin(),e[i].end());
		reverse(e[i].begin(),e[i].end());
		int r=a[i];
		for(auto x:e[i])
		{
			g.emplace_back(fen(r+x.first,r,x.second));
			r+=x.first;
		}
	}
	sort(g.begin(),g.end());
	reverse(g.begin(),g.end());
	int q=min(m,(long long)g.size());
	cout<<q<<endl;
	for(int i=0;i<q;i++)
		r.push_back(g[i].id);
	sort(r.begin(),r.end(),cmp);
	for(auto i:r)
		cout<<i<<' ';
	return 0;
}
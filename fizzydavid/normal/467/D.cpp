//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int N=300111;
int n,m,num;
pair<int,int>r[N];
bool vis[N];
map<string,int>id;
vector<int>essay,con[N];
priority_queue<pair<pair<int,int>,int> > pq;
int getid(string s)
{
	string t;int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if('A'<=s[i]&&s[i]<='Z')t.PB(s[i]-'A'+'a');
		else t.PB(s[i]);
		if(t[i]=='r')cnt++;
	}
	if(id[t])return id[t];
	id[t]=++num;
	r[id[t]]=MP(-cnt,(int)-t.size());
	pq.push(MP(r[id[t]],id[t]));
	return id[t];
}
void dijkstra()
{
	while(!pq.empty())
	{
		int ind=pq.top().SS;pq.pop();
		if(vis[ind])continue;
		vis[ind]=1;
		for(int i=0;i<con[ind].size();i++)
		{
			int u=con[ind][i];
			if(r[ind]>r[u])
			{
				r[u]=r[ind];
				pq.push(MP(r[u],u));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		essay.PB(getid(s));
	}
	cin>>m;
	string s1,s2;
	for(int i=1;i<=m;i++)
	{
		cin>>s1>>s2;
		con[getid(s2)].PB(getid(s1));
	}
	dijkstra();
	ll ansr=0,anssz=0;
	for(int i=0;i<essay.size();i++)
	{
		ansr-=r[essay[i]].FF;
		anssz-=r[essay[i]].SS;
	}
	cout<<ansr<<" "<<anssz<<endl;
	return 0;
}
/*
3
AbRb r Zz
4
xR abRb
aA xr
zz Z
xr y

2
RuruRu fedya
1
ruruRu fedor

*/
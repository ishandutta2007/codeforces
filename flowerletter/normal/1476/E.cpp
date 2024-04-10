#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
string a[100005];
int p[100005],ans[100005];
int qwq[5],qaq;/*
inline void dfs(int now)
{
	if(now==4)
	{
		p[qaq]=max(p[qaq],mn[qwq[0]][qwq[1]][qwq[2]][qwq[3]]);
		return ;
	}
	if(a[qaq][now]!='_')
	{
		qwq[now]=a[qaq][now]-'a';
		dfs(now+1);
	}
	else
	{
		for(int j=0;j<26;j++)
			qwq[now]=j,dfs(now+1);
	}
}*/
queue <int> q;
vector <int> e[100005],Ans;
unordered_map <string,int> mp;
int deg[100005];
int main(int argc, char** argv) {
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		while(a[i].size()<4) a[i]+='a';
		mp[a[i]]=i;
	}
	while(m--)
	{
		string x;
		cin >> x;
		while(x.size()<4) x+='a';
		vector <int> v;
		for(int i=0;i<16;i++)
		{
			string b=x;
			for(int j=0;j<4;j++)
				if(i&(1<<j)) b[j]='_';
			v.push_back(mp[b]);
		}
		int y;
		cin >> y;
		int flag=0;
		for(auto t:v)
		{
			if(!t) continue;
			if(t==y) flag=1;
			else e[y].push_back(t),++deg[t];
		}
		if(!flag)
		{
			puts("NO");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(!deg[i]) q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		Ans.push_back(x);
		for(auto v:e[x]) if(!--deg[v]) q.push(v);
	}
	if(Ans.size()<n) puts("NO");
	else
	{
		puts("YES");
		for(auto t:Ans) cout << t << " ";
	}
	return 0;
}
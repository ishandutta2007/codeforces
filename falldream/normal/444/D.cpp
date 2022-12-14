#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#define K 80
#define MN 50000
#define MX 540000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<pair<int,int> >v[MX+5];vector<int> s[MX+5];
char st[MN+5],S[10];map<int,int>mp[MX+5];
int last[MX+5],n,Q,num[MX+5],len[MX+5],flag[MN*2+5],Ans[MN*2+5];

int Bl(int x,int y)
{
	int res=1e9;
	for(int i=0;i<s[x].size();++i)
	{
		int pos=lower_bound(s[y].begin(),s[y].end(),s[x][i])-s[y].begin();
		if(pos<s[y].size())	res=min(res,max(s[y][pos]+len[y]-1,s[x][i]+len[x]-1)-s[x][i]+1);
		if(pos>0) res=min(res,max(s[y][pos-1]+len[y]-1,s[x][i]+len[x]-1)-s[y][pos-1]+1);
	}
	return res;
}

void Solve(int x)
{
	for(int i=0;i<v[x].size();++i) last[v[x][i].first]=0;
	for(int i=1;i<=n;++i) 
	{
		for(int j=i,k=0;j<=min(i+3,n);++j)	
			last[k=k*27+st[j]-'a'+1]=i;
		if(last[x]==i) 
			for(int j=0;j<v[x].size();++j) if(last[v[x][j].first])
				Ans[v[x][j].second]=min(Ans[v[x][j].second],max(i+len[x]-1,last[v[x][j].first]+len[v[x][j].first]-1)-last[v[x][j].first]+1);
	}
	for(int i=0;i<v[x].size();++i) last[v[x][i].first]=0;
	for(int i=n;i;--i) 
	{
		for(int j=i,k=0;j<=min(i+3,n);++j)	
			last[k=k*27+st[j]-'a'+1]=i;
		if(last[x]==i) 
			for(int j=0;j<v[x].size();++j) if(last[v[x][j].first])
				Ans[v[x][j].second]=min(Ans[v[x][j].second],max(i+len[x]-1,last[v[x][j].first]+len[v[x][j].first]-1)-i+1);
	}
}

int main()
{
	scanf("%s",st+1);memset(Ans,63,sizeof(Ans));
	n=strlen(st+1);Q=read();
	for(int i=1;i<=n;++i)
		for(int j=i,k=0;j<=min(i+3,n);++j)
			++num[k=k*27+st[j]-'a'+1],len[k]=j-i+1,s[k].push_back(i);
	for(int ii=1;ii<=Q;++ii) 
	{
		scanf("%s",S+1);int j=0,k=0;
		for(int i=1;S[i];++i) j=j*27+S[i]-'a'+1;
		scanf("%s",S+1);
		for(int i=1;S[i];++i) k=k*27+S[i]-'a'+1;
		if(min(num[j],num[k])==0) {Ans[ii]=-1;continue;}
		if(num[j]>num[k]) swap(j,k);
		if(mp[j][k]) flag[ii]=mp[j][k];
		else 
		{
			mp[j][k]=ii;
			v[j].push_back(make_pair(k,ii));
		}
	}
	for(int i=0;i<MX;++i) if(v[i].size()) 
		if(num[i]>K) Solve(i);
		else for(int j=0;j<v[i].size();++j) Ans[v[i][j].second]=Bl(i,v[i][j].first);
	for(int i=1;i<=Q;++i) printf("%d\n",flag[i]?Ans[flag[i]]:Ans[i]);
	return 0;
}
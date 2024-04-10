#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
//char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=3e4+5;
vector<int>v[xx];
int n,m,vis[xx];
deque<int>q;
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		v[a].push_back(b);
	}
	q.push_back(1);
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)vis[v[i][j]]=1;
		if(vis[q.back()])q.push_back(i);
		else if(!vis[q.front()])q.push_front(i);
		else // 
		{
			stack<int>s;
			while(vis[q.front()])s.push(q.front()),q.pop_front();
			q.push_front(i);
			while(s.size())q.push_front(s.top()),s.pop();
		}
		for(int j=0;j<v[i].size();j++)vis[v[i][j]]=0;
	}
	while(q.size())cout<<q.front()<<" ",q.pop_front();
	puts("");
	return 0;
}
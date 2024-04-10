#include <bits/stdc++.h>
#define SIZE 260
using namespace std;
typedef pair <int,int> P;

int A[SIZE],B[SIZE];
bool ans[SIZE];
vector <int> nd[10];
int rep[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int now=0;
		for(int j=0;j<3;j++)
		{
			now*=2;
			int c;
			scanf("%d",&c);
			now+=c;
		}
		A[i]=now;
		nd[A[i]].push_back(i);
	}
	for(int i=0;i<n;i++)
	{
		int now=0;
		for(int j=0;j<3;j++)
		{
			now*=2;
			int c;
			scanf("%d",&c);
			now+=c;
		}
		B[i]=now;
	}
	memset(rep,-1,sizeof(rep));
	vector <P> edge;
	queue <int> que;
	que.push(0);
	while(1)
	{
		while(!que.empty())
		{
			int v=que.front();que.pop();
			if(nd[A[v]].size()>1)
			{
				rep[A[v]]=v;
				ans[v]=false;
				for(int i=0;i<nd[A[v]].size();i++)
				{
					int nxt=nd[A[v]][i];
					if(nxt==v) continue;
					edge.push_back(P(v,nxt));
					que.push(nxt);
				}
			}
			else
			{
				ans[v]=true;
				int c=A[v]&B[v];
				rep[c]=v;
				if(c!=A[v]&&nd[c].size()>0)
				{
					for(int i=0;i<nd[c].size();i++)
					{
						int nxt=nd[c][i];
						edge.push_back(P(v,nxt));
						que.push(nxt);
					}
				}
				nd[c].clear();
			}
			nd[A[v]].clear();
		}
		bool up=false;
		for(int i=0;i<10;i++)
		{
			if(nd[i].empty()) continue;
			vector <int> bit;
			for(int j=0;j<3;j++) if(i>>j&1) bit.push_back(j);
			if(bit.size()==2)
			{
				int v=nd[i][0];
				int a=bit[0],b=bit[1];
				if(rep[1<<a]!=-1&&rep[1<<b]!=-1)
				{
					up=true;
					edge.push_back(P(rep[1<<a],v));
					edge.push_back(P(rep[1<<b],v));
					que.push(v);
				}
			}
		}
		if(!up) break;
	}
	for(int i=0;i<10;i++)
	{
		if(!nd[i].empty())
		{
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	for(int i=0;i<n;i++) printf("%d ",ans[i]);puts("");
	printf("%d\n",edge.size());
	for(int i=0;i<edge.size();i++) printf("%d %d\n",edge[i].first+1,edge[i].second+1);
	return 0;
}
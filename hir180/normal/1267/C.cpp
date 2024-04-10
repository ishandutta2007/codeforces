#include <bits/stdc++.h>
#define SIZE 2005
using namespace std;
typedef pair <int,int> P;
typedef pair <P,int> PP;

int deg[SIZE];
vector <int> zan[SIZE];
bool act[SIZE];

void print(vector < vector <int> > ans)
{
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d",ans[i].size());
		for(int j=0;j<ans[i].size();j++) printf(" %d",ans[i][j]+1);
		puts("");
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&deg[i]);
		sum+=deg[i];
	}
	int c=sum/2-n+1;
	if(sum%2==1||c<0||c>(n-1)/2)
	{
		puts("-1");
		return 0;
	}
	vector < vector <int> > ans;
	for(int i=0;i<n;i++) act[i]=true;
	while(c--)
	{
		vector <PP> vec;
		for(int i=0;i<n;i++)
		{
			if(act[i]&&deg[i]>=2)
			{
				vec.push_back(PP(P(deg[i],zan[i].size()),i));
			}
		}
		if(vec.size()<=2)
		{
			puts("-1");
			return 0;
		}
		sort(vec.begin(),vec.end());
		int p=vec[0].second,q=vec[1].second,r=vec[vec.size()-1].second;
		if(vec[vec.size()-1].first==P(2,0))
		{
			vector <int> now;
			for(int i=0;i<vec.size();i++) now.push_back(vec[i].second);
			now.push_back(vec[0].second);
			ans.push_back(now);
			print(ans);
			return 0;
		}
		act[p]=act[q]=false;
		deg[p]-=2;
		deg[q]-=2;
		deg[r]-=2;
		for(int i=0;i<deg[p];i++) zan[r].push_back(p);
		for(int i=0;i<deg[q];i++) zan[r].push_back(q);
		for(int i=0;i<zan[p].size();i++) zan[r].push_back(zan[p][i]);
		for(int i=0;i<zan[q].size();i++) zan[r].push_back(zan[q][i]);
		zan[p].clear();
		zan[q].clear();
		vector <int> now{p,q,r,p};
		ans.push_back(now);
	}
	set <P> st;
	set <P>::iterator it;
	for(int i=0;i<n;i++)
	{
		if(!act[i]) continue;
		for(int j=0;j<deg[i];j++) zan[i].push_back(i);
		st.insert(P(zan[i].size(),i));
	}
	while(st.size()>=2)
	{
		it=st.begin();
		P p=*it;
		st.erase(it);
		it=st.end();it--;
		P q=*it;
		st.erase(it);
		vector <int> now{zan[p.second][p.first-1],zan[q.second][q.first-1]};
		ans.push_back(now);
		q.first--;
		st.insert(q);
	}
	print(ans);
	return 0;
}
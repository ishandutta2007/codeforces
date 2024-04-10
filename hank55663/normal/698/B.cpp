#include<bits/stdc++.h>
#define time Time
using namespace std;
vector<int> v[200005];
int ans=0;
int f[200005];
int visit[200005];
int root=0;
int time=1;
void dfs(int n,int t){
	visit[n]=t;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++)
	{
		if(!visit[*it])
		dfs(*it,t);
		else if(visit[*it]==t) f[*it]=root,ans++;
	}
}
void dfs2(int n,int t){
	visit[n]=t;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++)
	{
		if(visit[*it]==0)
		dfs2(*it,t);
		else if(visit[*it]==t) root=*it,f[*it]=*it,ans++;
	}
}
main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		if(f[i]!=i)
		v[f[i]].push_back(i);
		else if(root==0)
		root=i;
		else
		ans++,f[i]=root,v[root].push_back(i);
	} 
	if(root!=0)
	dfs(root,time),time++;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!visit[i]){ 
				dfs2(i,time);
				time++;
				if(root!=0)
				break;
			} 
		}
	}
	for(int i=1;i<=n;i++)
	if(!visit[i])
	dfs(i,time),time++;
	printf("%d\n",ans);
	printf("%d",f[1]);
	for(int i=2;i<=n;i++)
	printf(" %d",f[i]);
	printf("\n");
}
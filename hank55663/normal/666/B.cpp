#include<bits/stdc++.h>
#define N 3005
using namespace std;
vector<int> v[N];
int m[N][N];
int main(){
	int n,M;
	scanf("%d %d",&n,&M);
	memset(m,0,sizeof(m));
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		queue<pair<int,int> >q;
		while(!q.empty())
		q.pop();
		q.push(make_pair(i,0));
		while(!q.empty()){
			pair<int,int> p=q.front();
			q.pop();
			for(vector<int>::iterator it=v[p.first].begin();it!=v[p.first].end();it++)
			if(m[i][*it]==0&&*it!=i){
				q.push(make_pair(*it,p.second+1));
				m[i][*it]=p.second+1;
			}
		}		
	} 
	pair<int,int> to[N][N];
	pair<int,int> front[N][N];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		to[i][j-1]=make_pair(m[j][i],j);
		front[i][j-1]=make_pair(m[i][j],j);
	}
	for(int i=0;i<n;i++){
		sort(to[i],to[i]+n);
		sort(front[i],front[i]+n);
	}
	int max=0,ans[4];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		for(int k=n-1;k>=n-3;k--)
		for(int l=n-1;l>=n-3;l--)
		if(to[i][k].first+m[i][j]+front[j][l].first>max&&m[i][j]&&m[j][front[j][l].second]&&m[to[i][k].second][i]&&to[i][k].second!=j&&to[i][k].second!=front[j][l].second&&front[j][l].second!=i){
			ans[0]=to[i][k].second,ans[1]=i,ans[2]=j,ans[3]=front[j][l].second,max=to[i][k].first+m[i][j]+front[j][l].first;
		}
	}
	printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
	return 0;
}
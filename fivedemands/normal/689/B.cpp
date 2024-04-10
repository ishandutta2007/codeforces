#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int>edge[200001];
int dis[200001];
bool vis[200001];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		edge[i].push_back(a[i]);
		dis[i]=-1;
	}
	for(int i=1; i<n ;i++){
		edge[i].push_back(i+1);
		edge[i+1].push_back(i);
	}
	queue<int>q;
	q.push(1);
	dis[1]=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(int i=0; i<edge[cur].size() ;i++){
			if(dis[edge[cur][i]]==-1){
				dis[edge[cur][i]]=dis[cur]+1;
				q.push(edge[cur][i]);
			}
		}
	}
	for(int i=1; i<=n ;i++) cout << dis[i] << ' ';
}
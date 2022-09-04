//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
//#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
vector<pii> v[300005];
vector<int> sta;
int station[300005];
int del[300005];
set<int> ans; 
void dfs(int a,int f,int d){
	if(d==0){
		for(vector<pii>::iterator it=v[a].begin();it!=v[a].end();it++){
			if(it->x!=f){
				ans.insert(it->y);
				del[it->y]=1;
			}
		}
		return;
	}
	for(vector<pii>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(it->x!=f&&!del[it->y]){
			if(station[it->x])
			{
				ans.insert(it->y);
				del[it->y]=1;
			//	printf("%d %d %d",it->x,it->y,a);
			}
			else
			dfs(it->x,a,d-1);
		} 
	}
}
int dis[1000005];
int main(){
	int n,k,d;
	scanf("%d %d %d",&n,&k,&d);
	int count=0;
	queue<pii> q;
	for(int i=0;i<k;i++){
		int a;
		scanf("%d",&a);
		if(station[a]==0){
			count++;
			station[a]=1;
			sta.pb(a);
			q.push(mp(a,0));
		}
	}
	printf("%d\n",count-1);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(mp(b,i));
		v[b].pb(mp(a,i));
	}
	while(!q.empty()){
		pii p=q.front();q.pop();
		for(vector<pii>::iterator it=v[p.x].begin();it!=v[p.x].end();it++){
			if(dis[it->x]==0&&station[it->x]==0){
				q.push(mp(it->x,p.y+1));
				dis[it->x]=p.y+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int first=1;
		for(vector<pii>::iterator it=v[i].begin();it!=v[i].end();it++){
			if(dis[i]==dis[it->x])
			ans.insert(it->y);
			else if(dis[i]==dis[it->x]+1){
				if(first==0){
					ans.insert(it->y); 
				}
				first=0;
			}
		}
	}
	int i=1;
	for(set<int>::iterator it=ans.begin();it!=ans.end()&&i<count;it++,i++){
		if(it!=ans.begin())
		printf(" ");
		printf("%d",*it);
	}
}
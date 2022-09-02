#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long l;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000000000
l cost[505][505];
l rev_cost[505][505];
l c[505][505];
l rev_c[505][505];
l a[505][505];
l d[505];
l rev_d[505];
bool used[505]={};
bool rev_used[505]={};
vector<int>node;
int n; 
int V;
void dijkstra(int s){
	fill(d,d+n,INF);
	memset(used,0,sizeof(used));
	d[node[s]]=0;
	while(1){
		int v=-1;
		for(int u=0;u<V;u++){
			if(!used[node[u]] && (v==-1 || d[node[u]]<d[node[v]])){
				v=u;
			}
		}
		if(v==-1){
			break;
		}
		used[node[v]]=true;
		for(int i=0;i<V;i++){
			d[node[i]]=min(d[node[i]],d[node[v]]+cost[node[v]][node[i]]);
		}
	}
}
void rev_dijkstra(int s){
	fill(rev_d,rev_d+n,INF);
	memset(rev_used,0,sizeof(rev_used));
	rev_d[node[s]]=0;
	while(1){
		int v=-1;
		for(int u=0;u<V;u++){
			if(!rev_used[node[u]] && (v==-1 || rev_d[node[u]]<rev_d[node[v]])){
				v=u;
			}
		}
		if(v==-1){
			break;
		}
		rev_used[node[v]]=true;
		for(int i=0;i<V;i++){
			rev_d[node[i]]=min(rev_d[node[i]],rev_d[node[v]]+rev_cost[node[v]][node[i]]);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cost[i][j]=INF;
			rev_cost[i][j]=INF;
			a[i][j]=INF;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%lld",&c[i][j]);
			if(i==j) c[i][j]=INF;
			rev_c[j][i]=c[i][j];
		}
	}
	vector<long long>ans;
	for(int i=0;i<n;i++){
		int ru; scanf("%d",&ru); ru--;
		node.pb(ru);
	}
	reverse(node.begin(),node.end());
	ans.pb(0LL);
	l behind=0;
	V=1;
	for(int i=1;i<node.size();i++){
		for(int j=0;j<i;j++){
			cost[node[j]][node[i]]=c[node[j]][node[i]];
			cost[node[i]][node[j]]=c[node[i]][node[j]];
			rev_cost[node[j]][node[i]]=rev_c[node[j]][node[i]];
			rev_cost[node[i]][node[j]]=rev_c[node[i]][node[j]];
		}
		V++;
		dijkstra(i);
		rev_dijkstra(i);
		for(int j=0;j<i;j++){
			for(int k=0;k<i;k++){
				if(j!=k){
					if(a[node[j]][node[k]]!=INF && a[node[j]][node[k]]>rev_d[node[j]]+d[node[k]]){
						behind-=(a[node[j]][node[k]]-(rev_d[node[j]]+d[node[k]]));
						a[node[j]][node[k]]=rev_d[node[j]]+d[node[k]];
					}
					if(a[node[j]][node[k]]==INF){
						a[node[j]][node[k]]=rev_d[node[j]]+d[node[k]];
					}
				}
			}
		}
		for(int j=0;j<i;j++){
			a[node[j]][node[i]]=rev_d[node[j]];
			behind+=a[node[j]][node[i]];
		}
		for(int j=0;j<i;j++){
			a[node[i]][node[j]]=d[node[j]];
			behind+=a[node[i]][node[j]];
		}
		ans.pb(behind);
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<n;i++){
		printf("%lld%c",ans[i],i==n-1?'\n':' ');
	}
}
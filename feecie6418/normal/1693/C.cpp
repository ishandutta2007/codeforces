#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m,f[200005],vst[200005],cnt[200005];
vector<int> g[200005],g2[200005];
struct Node{
	int x,val;
};
bool operator <(Node x,Node y){
	return x.val>y.val;
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g2[y].push_back(x); 
	}
	for(int i=1;i<=n;i++)f[i]=1e9;
	f[n]=0;
	priority_queue<Node> q;
	q.push({n,0});
	while(!q.empty()){
		Node w=q.top();
		q.pop();
		if(vst[w.x])continue;
		vst[w.x]=1;
		int x=w.x;
		for(int y:g2[x]){
			cnt[y]++;
			if(!vst[y]&&f[y]>f[x]+1+g[y].size()-cnt[y]){
				f[y]=f[x]+1+g[y].size()-cnt[y];
				q.push({y,f[y]});
			}
		}
	}
	cout<<f[1];
}
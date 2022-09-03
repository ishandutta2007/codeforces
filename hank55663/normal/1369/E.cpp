#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int val[100005];
pii p[200005];
vector<int> v[100005];
int vis[200005];
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for(int i = 0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(i);
		v[y].pb(i);
		val[x]--;
		val[y]--;
		p[i]=mp(x,y);
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(val[i]>=0)q.push(i);
	}
	int cnt=0;
	vector<int> ans;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cnt++;
		for(auto it:v[x]){
			if(!vis[it]){
				ans.pb(it);
				vis[it]=1;
				if(++val[p[it].x]==0)q.push(p[it].x);
				if(++val[p[it].y]==0)q.push(p[it].y);
			}
		}
	}
	if(cnt!=n){
		printf("DEAD\n");
	}
	else{
		printf("ALIVE\n");
		reverse(ans.begin(),ans.end());
		for(auto it:ans){
			printf("%d " ,it+1);
		}
		printf("\n");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define index Index
map<int,vector<pii> > v;
map<int,int> index;
int vis[100005];
deque<int> q;
void dfs(int x){
	q.push_back(x);
	while(index[x]!=v[x].size()){
		auto it=v[x][index[x]++];
		if(!vis[it.y]){
			vis[it.y]=1;
			dfs(it.x);
		}
	}
	q.push_front(x);
	q.pop_back();
}
int main(){
	int n;
	scanf("%d",&n);
	int b[100005];
	for(int i = 0;i<n-1;i++){
	//	b[i]=i+1;
		scanf("%d",&b[i]);
	}
	int c[100005];
	for(int i =0;i<n-1;i++){
	//	c[i]=i+2;
		scanf("%d",&c[i]);
	}
	for(int i = 0;i<n-1;i++){
		if(b[i]>c[i]){
			printf("-1\n");
			return 0;
		}
		v[b[i]].pb(mp(c[i],i));
		v[c[i]].pb(mp(b[i],i));
	}
	vector<int> odd;
	for(auto it:v){
		if(it.y.size()&1){
			odd.pb(it.x);
		}
	}
	if(odd.size()>2){
		printf("-1\n");
		return 0;
	}
	if(odd.size()){
		dfs(odd[0]);
	}
	else
	dfs(v.begin()->x);
	if(q.size()!=n){
		printf("-1\n");
		return 0;
	}
	while(!q.empty()){
		printf("%d ",q.front());
		q.pop_front();
	}
	printf("\n");
}
#include<bits/stdc++.h>
using namespace std;
#define time Time
struct edge{
	int num,x,y,cost;
	edge(int _num,int _x,int _y,int _cost):num(_num),x(_x),y(_y),cost(_cost){
	}
};
vector<edge> v[1005];
stack<edge> st;
stack<edge> sp;
int visit[1005];
int depth[1005];
int ok=0;
int time=0;
int bridge[30005];
void dfs(int n,int t,int dv){
	visit[n]=1;
	if(n==t){
		ok=1;
	}
	for(vector<edge>::iterator it=v[n].begin();it!=v[n].end()&&!ok;it++){
		if(it->num==dv)
		continue;
		if(!ok)
		st.push(*it);
		if(!visit[it->y])
		dfs(it->y,t,dv);
		if(!ok)
		st.pop();
	}
}
void dfs2(int n,int dv,int dv2){
	visit[n]=depth[n]=++time;
	for(vector<edge>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(it->num==dv||it->num==dv2)
		continue;
		if(!visit[it->y]){
			dfs2(it->y,dv,it->num);
		}
		depth[n]=min(depth[n],depth[it->y]);
		if(visit[n]<depth[it->y]){
			bridge[it->num]=1;
		}
	}
}
main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int s,t;
	scanf("%d %d",&s,&t);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(edge(i,a,b,c));
		v[b].push_back(edge(i,b,a,c));
	}
	dfs(s,t,0);
	if(!ok){
		printf("0\n0\n");
		return 0; 
	}
	while(!st.empty()){
		sp.push(st.top());
		st.pop();
	}
	sp.push(edge(0,0,0,0));
	int ans=2e9+1,ansx,ansy;
	while(!sp.empty()){
		int sum=2e9+1,mnum=0;
		memset(visit,0,sizeof(visit));
		memset(bridge,0,sizeof(bridge));
		dfs2(s,sp.top().num,0);
		memset(visit,0,sizeof(visit));
		ok=0;
		dfs(s,t,sp.top().num);
		if(ok)
		while(!st.empty()){
			if(bridge[st.top().num]){
				if(sum>st.top().cost){
					sum=st.top().cost;
					mnum=st.top().num;
				}
			}
			st.pop();
		}
		if(ans>sum+sp.top().cost&&sum!=2e9+1&&mnum!=0){
			ans=sum+sp.top().cost;
			ansx=sp.top().num;
			ansy=mnum;
		}
		sp.pop();
	}
	if(ans==2e9+1)
	printf("-1\n");
	else{
	printf("%d\n",ans);
		if(ansx==0)
		printf("1\n%d\n",ansy);
		else if(ansy==0)
		printf("1\n%d\n",ansx);
		else
		printf("2\n%d %d\n",ansx,ansy);
	}
}
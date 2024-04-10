#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
	int u,v;
	long long int len;
	int build;
	Edge(int _u,int _v,long long int _len,int _build):u(_u),v(_v),len(_len),build(_build){
	}
};
bool operator<(const Edge &a,const Edge &b ){
	return a.len<b.len;
}
bool operator>(const Edge &a,const Edge &b ){
	return a.len>b.len;
}
vector<Edge>  v[1005];
long long int ma[1005][1005];
int f[1005];
int main(){
	int n,m,s,t;
	long long int l;
	scanf("%d %d %I64d %d %d",&n,&m,&l,&s,&t);
	memset(ma,0,sizeof(ma));
	for(int i=0;i<m;i++){
		int u,V;
		long long len;
		scanf("%d %d %I64d",&u,&V,&len);
		if(len==0){
			v[u].push_back(Edge(u,V,1,0));
			v[V].push_back(Edge(V,u,1,0));
			ma[u][V]=ma[V][u]=-1;
		}
		else
		{
			v[u].push_back(Edge(u,V,len,1));
			v[V].push_back(Edge(V,u,len,1));
		}
	}
	priority_queue<Edge,vector< Edge >,greater<Edge > > pq;
	int visit[1005];
	memset(visit,0,sizeof(visit));
	pq.push(Edge(0,s,0,1));
	long long int d[1005];
	d[s]=0;
	while(!pq.empty()){
		Edge p=pq.top();pq.pop();
		if(visit[p.v])
		continue;
		visit[p.v]=1;
		d[p.v]=p.len;
		for(vector<Edge>::iterator it=v[p.v].begin();it!=v[p.v].end();it++){
			if(visit[it->v]||it->build==0)
			continue;
			else
			pq.push(Edge(p.v,it->v,p.len+it->len,1));
		}
	}
	if(visit[t]&&d[t]<l){
		//printf("%d\n",d[t]);
		printf("NO\n");
		return 0;
	}
	if(d[t]==l&&visit[t]){
		printf("YES\n");
		for(int i=0;i<n;i++){
			for(vector<Edge >::iterator it=v[i].begin();it!=v[i].end();it++){
				if(it->v>i)
				{
					if(it->build==1)
					printf("%d %d %I64d\n",it->u,it->v,it->len);
					else
					printf("%d %d 1000000009\n",it->u,it->v);
				}
			}
		}
		return 0;
	}
	memset(visit,0,sizeof(visit));
	memset(f,0,sizeof(f));
	pq.push(Edge(-1,s,0,1));
	memset(d,0,sizeof(d));
	d[s]=0;
	while(!pq.empty()){ 
		Edge p=pq.top();pq.pop();
		if(visit[p.v])
		continue;
		f[p.v]=p.u;
		visit[p.v]=1;
		d[p.v]=p.len;
		for(vector<Edge>::iterator it=v[p.v].begin();it!=v[p.v].end();it++){
			if(visit[it->v])
			continue;
			else
			pq.push(Edge(p.v,it->v,p.len+it->len,1));
		}
	}
	if(!visit[t]||d[t]>l){
		printf("NO\n");
		return 0;
	}
	long long int now_len=d[t];
	stack<pair<int,int> > st;
	int num=t;
	while(f[t]!=-1){
		st.push(make_pair(t,f[t]));
		if(ma[t][f[t]]==-1)
		ma[t][f[t]]=ma[f[t]][t]=-2;
		t=f[t];
	//	printf("%d %d %d\n",t,f[t],ma[f[t]][t]); 
	}
	for(int i=0;i<n;i++)
	{
		for(vector<Edge>::iterator it=v[i].begin();it!=v[i].end();it++)
		{
			if(ma[it->u][it->v]==-1){
				it->len=1e10;
			}
			if(ma[it->u][it->v]!=-2)
			ma[it->u][it->v]=it->len;
			else
			ma[it->u][it->v]=-1;
		}
	}
	memset(visit,0,sizeof(visit));
	memset(f,0,sizeof(f));
	pq.push(Edge(-1,s,0,1));
	memset(d,0,sizeof(d));
	d[s]=0;
	while(!pq.empty()){ 
		Edge p=pq.top();pq.pop();
		if(visit[p.v])
		continue;
		f[p.v]=p.u;
		visit[p.v]=1;
		d[p.v]=p.len;
		for(vector<Edge>::iterator it=v[p.v].begin();it!=v[p.v].end();it++){
			if(visit[it->v])
			continue;
			else if(ma[it->u][it->v]==-1)
			pq.push(Edge(p.v,it->v,p.len+1,1));
			else
			pq.push(Edge(p.v,it->v,p.len+ma[it->u][it->v],1));
		}
	//	printf("%d %d\n",p.v,d[p.v]);
	}
	if(now_len!=d[num])
	printf("%d %d",now_len,d[num]);
	while(!st.empty()){
		pair<int,int> p=st.top();st.pop();
		if(ma[p.first][p.second]!=-1)
		continue;
		memset(visit,0,sizeof(visit));
		pq.push(Edge(-1,p.first,0,1));
		memset(d,0,sizeof(d));
		d[p.first]=0;
		while(!pq.empty()){
			Edge e=pq.top();pq.pop();
			if(visit[e.v])
			continue;
			//f[p.v]=p.u;
			visit[e.v]=1;
			d[e.v]=e.len;
			for(vector<Edge>::iterator it=v[e.v].begin();it!=v[e.v].end();it++){
				if(visit[it->v]||(it->u==p.first&&it->v==p.second)||(it->u==p.second&&it->v==p.first))
				continue;
				else if(ma[it->u][it->v]==-1)
				pq.push(Edge(e.v,it->v,e.len+1,1));
				else
				pq.push(Edge(e.v,it->v,e.len+ma[it->u][it->v],1));
			}
		}
		ma[p.first][p.second]=ma[p.second][p.first]=l-(now_len-1);
		memset(visit,0,sizeof(visit));
		pq.push(Edge(-1,s,0,1));
		memset(d,0,sizeof(d));
		d[s]=0;
		while(!pq.empty()){
			Edge e=pq.top();pq.pop();
			if(visit[e.v])
			continue;
			//f[p.v]=p.u;
			visit[e.v]=1;
			d[e.v]=e.len;
			for(vector<Edge>::iterator it=v[e.v].begin();it!=v[e.v].end();it++){
				if(visit[it->v])
				continue;
				else if(ma[it->u][it->v]==-1)
				pq.push(Edge(e.v,it->v,e.len+1,1));
				else
				pq.push(Edge(e.v,it->v,e.len+ma[it->u][it->v],1));
			}
		}
		now_len=d[num];
		if(now_len==l)
		break;
	}
	if(now_len!=l)
	printf("NO\n");
	printf("YES\n");
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++){
		if(ma[i][j]==-1)
		printf("%d %d 1\n",i,j);
		if(ma[i][j]!=0&&ma[i][j]!=-1)
		printf("%d %d %I64d\n",i,j,ma[i][j]);
	}
}
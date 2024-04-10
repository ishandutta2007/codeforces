/**
 *    author:  gary
 *    created: 05.08.2022 08:33:11
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int GRAPH_SIZE= 2200*4+20;
int s=0,t=GRAPH_SIZE-1;
struct EDGE{
	int u,v,c,cos;
};
vector<EDGE> e;
vector<int> each[GRAPH_SIZE];
int maxflow,mincost;
int flow[GRAPH_SIZE];
int dis[GRAPH_SIZE],inq[GRAPH_SIZE],las[GRAPH_SIZE];
bool spfa(){
	memset(inq,0,sizeof(inq));
	memset(dis,63,sizeof(dis));
	flow[s]=INF;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		inq[now]=0;
		for(auto it:each[now]){
			int to,f,c;
			to=e[it].v;
			f=e[it].c;
			c=e[it].cos;
			if(f<=0) continue;
			if(dis[to]>dis[now]+c){
				dis[to]=dis[now]+c;
				las[to]=it;
				flow[to]=min(flow[now],f);
				if(!inq[to]) q.push(to);
				inq[to]=1;
			}
		}
	}
	return dis[t]!=INF;
}
void KM(){
	while(spfa()){
		maxflow+=flow[t];
		mincost+=dis[t]*flow[t];
		int now=t;
		while(now!=s){
			e[las[now]].c-=flow[t];
			e[las[now]^1].c+=flow[t];
			now=e[las[now]].u;
		}
	}
}
void add_edge(int U,int V,int C,int COS){
	EDGE tmp;
	tmp.u=U;
	tmp.v=V;
	tmp.c=C;
	tmp.cos=COS;
	e.push_back(tmp);
	each[U].push_back(e.size()-1);
	swap(tmp.u,tmp.v);
	tmp.c=0;
	tmp.cos=-COS;
	e.push_back(tmp);
	each[V].push_back(e.size()-1);
}
int n,a[GRAPH_SIZE],b[GRAPH_SIZE];
bool check(int x){
	vector<LL> v;
	rb(i,1,n){
		LL ed=0;
		rb(j,1,n*2) if(b[i]>=b[j])
		check_max(ed,1ll*x*a[j]+b[j]);
		v.push_back(ed);
	}
	sort(ALL(v));
	vector<LL> v2;
	rb(i,n+1,n*2) v2.push_back(1ll*x*a[i]+b[i]);
	sort(ALL(v2));
	rep(i,n) if(v[i]<v2[i]) return false;
	return true;
}
LL z[GRAPH_SIZE];
int id[GRAPH_SIZE],rnk[GRAPH_SIZE];
bool cmp(int A,int B){
	return z[A]<z[B];
}
bool cmp2(int A,int B){
	return b[A]<b[B];
}
int recover(int x){
	rb(i,n+1,n*2) id[i]=i,z[i]=1ll*a[i]*x+b[i];
	sort(id+n+1,id+1+n+n,cmp);
	rb(i,n+1,n*2) rnk[id[i]]=i;
	rb(i,1,n) add_edge(s,i,1,0);
	rb(i,n+1,n*2) add_edge(i,t,1,0);
	rb(i,n+1,n*2){
		if(i!=n+1) add_edge(i+n,i+n-1,INF,0);
		add_edge(i+n,i,INF,0);
	}
	rb(i,1,n){
		rl(j,n*2,n+1) if(1ll*a[i]*x+b[i]>=z[id[j]]){
			add_edge(i,j+n,1,-1);
			break;
		}
		LL ed=0;
		rb(j,1,n*2) if(b[i]>=b[j])
		check_max(ed,1ll*x*a[j]+b[j]);
		rl(j,n*2,n+1) if(ed>=z[id[j]]) {
			add_edge(i,j+n,1,0);
			break;
		}
	}
	sort(id+n+1,id+1+n+n,cmp2);
	rb(i,n+1,n*2){
		if(i!=n+1) add_edge(i+n*2,i+n*2-1,INF,0);
		add_edge(i+n*2,rnk[id[i]],INF,0);
	}
	rb(i,1,n){
		rl(j,n*2,n+1) if(b[i]>=b[id[j]]){
			add_edge(i,j+n*2,1,-1);
			break;
		}
	}
	KM();
	assert(maxflow==n);
	return 2*n+mincost;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	rb(i,1,n*2) cin>>a[i]>>b[i];
	int l=0,r=1e9+10;
	if(!check(r)){
		cout<<-1<<endl;
		return 0;
	}
	while (l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<" "<<recover(l)<<endl;
    return 0;
}
/*
1
3 10 
1 16


2 
3 0 
2 1 
1 10 
1 11

1
42 42 
47 47

8
145 1729363
891 4194243
424 853731
869 1883440
843 556108
760 1538373
270 762781
986 2589382
610 99315884
591 95147193
687 99248788
65 95114537
481 99071279
293 98888998
83 99764577
769 96951171


8
261 261639
92 123277
271 131614
320 154417
97 258799
246 17926
117 222490
110 39356
85 62864876
86 62781907
165 62761166
252 62828168
258 62794649
125 62817698
182 62651225
16 62856001


*/
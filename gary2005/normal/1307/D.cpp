/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
bool special[200000+1];int n,m,k;
vector<int> each[200000+1];
int res=0;
vector<int> m1,m2; 
int Tmp=-INF;
void dis1(){
	int dis[200000+1],vis[200000+1];
	dis[1]=0;
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		vis[now]=1;
		for(auto it:each[now]){
			if(!vis[it])
			{
				vis[it]=1;
				dis[it]=dis[now]+1;
				q.push(it);
			}
		}
	}
	rb(i,1,n)
		if(special[i])
			m1.PB(dis[i]);
	res=dis[n];
}
void dis2(){
	int dis[200000+1],vis[200000+1];
	queue<int> q;
	q.push(n);
	dis[n]=0;
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int now=q.front();
		q.pop();
		vis[now]=1;
		for(auto it:each[now]){
			if(!vis[it])
			{
				vis[it]=1;
				dis[it]=dis[now]+1;
				q.push(it);
			}
		}
	}
	rb(i,1,n)
		if(special[i])
			m2.PB(dis[i]);
}
vector<mp> m3; 
map<int,vector< int> > EE;
int main(){
	fastio;
	cin>>n>>m>>k;
	rb(i,1,k){
		int aa;
		cin>>aa;
		special[aa]=1;
	}
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		if(special[u]&&special[v]){
			Tmp=INF;
		}
		each[u].PB(v);
		each[v].PB(u);
	}
	dis1(); 
	dis2();
	rep(i,k)
		m3.PB(II(m2[i]-m1[i],i)),EE[m2[i]-m1[i]].PB(m2[i]);
	for(map<int,vector<int> > :: IT ite=EE.begin();ite!=EE.end();ite++)
		sort(ALL(ite->SEC));
	sort(ALL(m3));
	int maxx=0;
	rep(i,k)	
		m3[i].SEC=maxx=max(maxx,m2[m3[i].SEC]);
//	rep(i,k){
//		cout<<m1[i]<<" "<<m2[i]<<endl;
//	}
	rep(i,k){
		//im1 j2+i1<=i2+j1.j2-j1<=i2-i1 ,j2 
//		rr=-1;
		vector<mp> :: IT ite=lower_bound(ALL(m3),II(m2[i]-m1[i],-1));
		if(ite!=m3.begin()){
			ite--;
			Tmp=max(Tmp,m1[i]+ite->SEC+1);
		}
		if(EE[m2[i]-m1[i]].size()>1){
			if(EE[m2[i]-m1[i]][EE[m2[i]-m1[i]].size()-1]==m2[i]){
				Tmp=max(Tmp,EE[m2[i]-m1[i]][EE[m2[i]-m1[i]].size()-2]+m1[i]+1);
			}
			else{
				Tmp=max(Tmp,EE[m2[i]-m1[i]][EE[m2[i]-m1[i]].size()-1]+m1[i]+1);
			}
		}
	}
//	cout<<Tmp<<endl;
	cout<<min(res,Tmp)<<endl;
	return 0;
}
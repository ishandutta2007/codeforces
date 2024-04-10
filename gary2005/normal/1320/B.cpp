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
vector<int> each[200000+2],reach[200000+2];
int n,m;
int dis[200000+2];//t
int s,t;
void dijk(){
	priority_queue<mp,vector<mp>,greater<mp > > q;
	dis[t]=0;
	q.push(II(0,t));
	while(!q.empty()){
		int i,val;
		i=q.top().SEC;
		val=q.top().FIR;
		q.pop();
		if(dis[i]!=val) continue;
		for(auto it:reach[i]){
			if(dis[it]>val+1){
				dis[it]=val+1;
				q.push(II(dis[it],it));
			}
		}
	}
}
int p[200000+2];
bool many[200000+2];
int main(){
	fastio;
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m;
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		each[u].PB(v);
		reach[v].PB(u);
	}	
	s=-1;
	int k;
	cin>>k;
	rb(i,1,k)
	{
		cin>>p[i]; 
		if(s==-1){
			s=p[i];
		}
		t=p[i];
	}
	
	dijk();
	rb(i,1,n){
		int cnt=0;
		for(auto it:each[i]){
			if(dis[it]==dis[i]-1){
				cnt++;	
			}
		}
		many[i]=bool(cnt-1);
	}
	int M,MM;
	M=MM=0;
	rb(i,2,k){
		
		if(dis[p[i]]!=dis[p[i-1]]-1){
			M++;
			MM++;
			
		}	
		else{
			if(many[p[i-1]]){
				MM++;
			}
		}
	}
	cout<<M<<" "<<MM;
	return 0;
}
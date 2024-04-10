/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=100000+20;
int pre[MAXN];
int n,m;
vector<mp> g[MAXN];
int dist[MAXN];
bool vist[MAXN];
void bfs(){
	vist[0]=1;
	queue<int> q;
	q.push(0);
	dist[0]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto it:g[now]){
			if(!vist[it.FIR]){
				vist[it.FIR]=1;
				dist[it.FIR]=dist[now]+1;
				q.push(it.FIR);
			}
		}
	}
} 

mp best=II(INF,INF);
vector<int> vv;
int dist2[MAXN];
void bfs2(){
	memset(vist,0,sizeof(vist));
	fill(pre,pre+n,-1);
	queue<int> q;
	q.push(n-1);
	vist[n-1]=1;
	dist2[n-1]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto it:g[now]){
			if(it.SEC==0){
				if(!vist[it.FIR]){
					q.push(it.FIR);
					vist[it.FIR]=1;
					pre[it.FIR]=now;
					dist2[it.FIR]=dist2[now]+1;
				}
			}
			else{
				if(!vist[it.FIR]){
					if(II(dist[it.FIR],it.SEC)<best){
						best=II(dist[it.FIR],it.SEC);
						for(auto it:vv){
							pre[it]=-1;
						}
						vv.clear();	
					}
					if(II(dist[it.FIR],it.SEC)==best){
						vv.PB(it.FIR);
						if(pre[it.FIR]==-1){
							dist2[it.FIR]=dist2[now]+1;
							pre[it.FIR]=now;
						}
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,m){
		int u,v,len;
		scanf("%d%d%d",&u,&v,&len);
		g[u].PB(II(v,len));
		g[v].PB(II(u,len));
	}	
	bfs();
	memset(vist,0,sizeof(vist));
	bfs2();	
	if(vist[0]){
		cout<<"0\n";
		vector<int> v;
		int now=0;
		while(true){
			v.PB(now);
			if(now==n-1){
				break;
			}
			now=pre[now];
		}
		cout<<v.size()<<endl;
		for(auto it:v){
			cout<<it<<' ';
		}
		cout<<endl;
		return 0;
	}
	vector<int> q[2];
	int now=0,pre_=1;
	reverse(ALL(vv));
	q[pre_]=vv;
	cout<<best.SEC;
	rl(i,best.FIR-1,0){
		q[now].clear();
		vector<pair<mp,int> > vvv;
		int best=INF;
		for(auto it:q[pre_]){
			for(auto itt:g[it]){
				if(dist[itt.FIR]==i){
					check_min(best,itt.SEC);
				}
			}	
		}
		for(auto it:q[pre_]){
			for(auto itt:g[it]){
				if(dist[itt.FIR]==i&&itt.SEC==best){
					vvv.PB(II(II(itt.SEC,itt.FIR),it));
				}
			}	
		}
		assert(!vvv.empty());
		int z=vvv[0].FIR.FIR;
		cout<<z;
		for(auto it:vvv){
			if(it.FIR.FIR==z){
				q[now].PB(it.FIR.SEC);
				pre[it.FIR.SEC]=it.SEC;
			}
		}
		swap(now,pre_);
	}
	vector<int> rest;
	now=0;
	while(true){
		rest.PB(now);
		if(now==n-1) break;
		now=pre[now];
	}
	cout<<endl;
	cout<<rest.size()<<endl;
	for(auto it:rest) cout<<it<<" ";
	return 0;
}
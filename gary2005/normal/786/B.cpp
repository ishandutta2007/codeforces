/*
AuThOr Gwj
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const LL INF=1e17;
const int N=1<<17;
typedef pair<LL,LL> mp;
vector<mp> g[N*4+20];//in || out
LL dis[4*N+20];
int w;
void from(int a,int b,int to,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return;
	}
	if(r<=b&&l>=a){
//		cout<<"["<<l<<","<<r<<"]"<<"->"<<to-N+1<<" "<<now<<" "<<to<<endl;
		if(now>=N)
		g[now].PB(II(to,w));
		else
		g[now+2*N].PB(II(to,w));
		return;
	}
	int mid=(l+r)>>1;
	from(a,b,to,now<<1,l,mid);
	from(a,b,to,now<<1|1,mid,r);
} 
void to(int a,int b,int from,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return;
	}
	if(r<=b&&l>=a){
//		cout<<"["<<l<<","<<r<<"]"<<"<-"<<from-N+1<<endl;
		g[from].PB(II(now,w));
		return;
	}
	int mid=(l+r)>>1;
	to(a,b,from,now<<1,l,mid);
	to(a,b,from,now<<1|1,mid,r);
}
void init(int now=1,int l=1,int r=N+1){
	if(l==r-1) return;
	g[now].PB(II(now<<1,0));
	g[now].PB(II(now<<1|1,0));
	if((now<<1)>=N){ 
	g[now<<1].PB(II(now+2*N,0));
	g[now<<1|1].PB(II(now+2*N,0));
	}
	else{
	g[(now<<1)+2*N].PB(II(now+2*N,0));
	g[(now<<1|1)+2*N].PB(II(now+2*N,0));
	}
	int mid=(l+r)>>1;
	init(now<<1,l,mid);
	init(now<<1|1,mid,r);
}

int n,m,s;
int main(){
	fastio;
	R2(n,m);
	R(s);
	init();
	rb(i,1,m){
		int ty;
		R(ty);
		if(ty==1){
			int u,v;
			R2(u,v);
			R(w);
			from(u,u+1,v+N-1);
		}
		if(ty==2){
			int u,l,r;
			R(u);
			R2(l,r);
			R(w);
			to(l,r+1,u+N-1);
		}
		if(ty==3){
			int u,l,r;
			R(u);
			R2(l,r);
			R(w);
			from(l,r+1,u+N-1);
		}
	}
	priority_queue<mp,vector<mp>,greater<mp> > q;
	rb(i,1,4*N)
		dis[i]=INF;
	dis[s+N-1]=0;
	q.push(II(dis[s+N-1],s+N-1)) ;
	while(!q.empty()){
		mp now=q.top();
		q.pop();
		if(dis[now.SEC]!=now.FIR) continue;
		for(auto it:g[now.SEC]){
//			cout<<now.SEC<<" "<<it.FIR<<endl;
			if(now.FIR+it.SEC<dis[it.FIR]){
				dis[it.FIR]=now.FIR+it.SEC;
				q.push(II(dis[it.FIR],it.FIR));
			}
		}
	}
	rb(i,1,n){
		cout<<(dis[i+N-1]==INF? -1:dis[i+N-1])<<" ";
	}
	cout<<endl;
	return 0;
}
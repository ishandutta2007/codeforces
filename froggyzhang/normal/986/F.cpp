#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 40004000
const int MX=4e7;
typedef long long ll;
int Q;
bool ntp[M],ans[N];
int pn,p[M>>2];
struct Query{
	ll n,k;
	int id;
	friend bool operator < (const Query &a,const Query &b){
		return a.k<b.k;
	}
}q[N];
void init(int n){
	ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
}
vector<ll> A;
void Split(ll x){
	for(int i=1;1LL*p[i]*p[i]<=x;++i){
		if(x%p[i]==0){
			while(x%p[i]==0){
				x/=p[i];
			}
			A.push_back(p[i]);		
		}
	}
	if(x>1)A.push_back(x);
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;	
}
ll dis[N];
vector<pair<int,ll> > G[N];
void Dijkstra(){
	static bool vis[N];
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	q.emplace(0,0);
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.emplace(dis[v],v);
			}	
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(MX);
	cin>>Q;
	for(int i=1;i<=Q;++i){
		cin>>q[i].n>>q[i].k;
		q[i].id=i;
	}
	sort(q+1,q+Q+1);
	for(int i=1;i<=Q;++i){
		if(q[i].k^q[i-1].k){
			A.clear();
			Split(q[i].k);
			sort(A.begin(),A.end());
			if(A.size()>2){
				for(int i=0;i<A[0];++i)G[i].clear();
				for(int i=1;i<A.size();++i){
					for(int j=0;j<A[0];++j){
						G[j].emplace_back((j+A[i])%A[0],A[i]);
					}
				}
				Dijkstra();
			}
		}
		if(A.size()==0){
		
		}
		else if(A.size()==1){
			ans[q[i].id]=q[i].n%q[i].k==0;	
		}
		else if(A.size()==2){
			ll x,y;
			exgcd(A[0],A[1],x,y);
			x=((__int128)x*q[i].n%A[1]+A[1])%A[1];
			y=(q[i].n-x*A[0])/A[1];
			ans[q[i].id]=y>=0;
		}
		else{
			ans[q[i].id]=dis[q[i].n%A[0]]<=q[i].n;
		}
	}
	for(int i=1;i<=Q;++i){
		cout<<(ans[i]?"YES\n":"NO\n");	
	}
	return 0;
}
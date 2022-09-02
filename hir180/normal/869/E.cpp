#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
struct BIT
{
	ll bit[3005][3005];
	ll MOD;
	void init(ll p){
		MOD = p;
	}
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int j,ll x)
	{
		for(int s=i;s<3005;s+=f(s)) for(int t=j;t<3005;t+=f(t)){
			bit[s][t] = (bit[s][t]+x)%MOD;
		}
	}
	ll sum(int i,int j)
	{
		ll res=0;
		for(int s=i;s>0;s-=f(s)) for(int t=j;t>0;t-=f(t)){
			res = (bit[s][t]+res)%MOD;
		}
		return res;
	}
}bit[2];
int n,m,q;
map<P2,int>M[2];
int main(){
	cin>>n>>m>>q;
	bit[0].init(998244353);
	bit[1].init(1000000007);
	ll cur[2] = {1,1};
	ll md[2] = {998244353,1000000007};
	ll prime[5]={7,11,13,17,19};
	srand((unsigned)time(NULL));
	int v = rand()%5;
	ll pw = prime[v];
	rep(i,q){
		rep(x,2) cur[x] = (cur[x]*pw)%md[x];
		int t; scanf("%d",&t);
		if(t == 1){
			int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
			rep(x,2){
				M[x][mp(mp(a,b),mp(c,d))] = cur[x];
				bit[x].add(a,b,cur[x]);
				bit[x].add(a,d+1,md[x]-cur[x]);
				bit[x].add(c+1,b,md[x]-cur[x]);
				bit[x].add(c+1,d+1,cur[x]);
			}
		}
		else if(t == 2){
			int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
			rep(x,2){
				ll C = M[x][mp(mp(a,b),mp(c,d))];
				bit[x].add(a,b,md[x]-C);
				bit[x].add(a,d+1,C);
				bit[x].add(c+1,b,C);
				bit[x].add(c+1,d+1,md[x]-C);
			}
		}
		else{
			int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
			ll u[2],v[2];
			rep(x,2){
				u[x] = bit[x].sum(a,b);
				v[x] = bit[x].sum(c,d);
			}
			if(u[0]==v[0] && u[1]==v[1]){
				puts("Yes");
			}
			else{
				puts("No");
			}
		}
	}
}
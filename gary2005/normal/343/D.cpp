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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define W(a) cout<<a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=500000+20;
int in[MAXN],out[MAXN];
int n;
vector<int> g[MAXN];
int cnt=0;
void dfs(int now,int pre=0){
	in[now]=++cnt;
//	maxi[now]=id[now];
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now);
		}
	}
	out[now]=++cnt;
}
int tree[MAXN*8][2];//empty full
int N=1<<20;
int query0(int a,int b,int now=1,int l=1,int r=N+1){
	if(r<=b&&l>=a){
		return tree[now][0];
	}
	if(r<=a||l>=b){
		return 0;
	}
	int mid=(l+r)>>1;
	return max(query0(a,b,now<<1,l,mid),query0(a,b,now<<1|1,mid,r));
}
void modify0(int a,int T){
	a+=N-1;
	tree[a][0]=T;
	a>>=1;
	while(a){
		tree[a][0]=T;
		a>>=1;
	}
}
void modify1(int a,int b,int T,int now=1,int l=1,int r=N+1){
	if(r<=b&&l>=a){
		tree[now][1]=T;
		return ;
	}
	if(r<=a||l>=b){
		return ;
	}
	int mid=(l+r)>>1;
	modify1(a,b,T,now<<1,l,mid);modify1(a,b,T,now<<1|1,mid,r);
}
int query1(int a){
	int res=0;
	a+=N-1;
	res=tree[a][1];
	a>>=1;
	while(a){
		res=max(res,tree[a][1]);
		a>>=1;
	}
	return res;
}

int main(){
	fastio;
	R(n);
	rb(i,1,n-1){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1);
	int q;
	cin>>q;
	rb(cntt,1,q){
		int ty;
		R(ty);
		int x;
		R(x);
		if(ty==1){
			modify1(in[x],out[x],cntt);
		}
		else{
			if(ty==2){
				modify0(in[x],cntt);
			}
			else
			{
				int L1,L2;
				L1=query0(in[x],out[x]);
				L2=query1(in[x]);	
				if(L1>=L2){
					cout<<0<<endl;
				} 
				else{
					cout<<1<<endl;
				}
			}
		}
	}
	return 0;
}
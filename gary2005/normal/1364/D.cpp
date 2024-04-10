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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,k;
vector<int> g[100000+2];
int cnt[2],vis[100000+2],Col[100000+2],depth[100000+2];
void color(int now,int col){
	cnt[col]++;
	Col[now]=col;
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it]){
			color(it,col^1);	
		}
	}
}
int fa[100000+2];
void dig(int now,int dep,int fat=0){
	depth[now]=dep;
	fa[now]=fat;
	for(auto it:g[now]){
		if(!depth[it]){
			dig(it,dep+1,now);
		}		
	}
}
vector<int> res;
int main(){
	fastio;
	cin>>n>>m>>k;
	rb(i,1,m)
	{
		int u,v;
		cin>>u>>v;
		g[u].PB(v);
		g[v].PB(u);
	}
	if(m==n-1){
		cout<<1<<endl;
		color(1,0);
		if(cnt[0]>=(k+1)/2){
			int c=0;
			rb(i,1,n){
				if(Col[i]==0){
					c++;
					cout<<i<<" ";
					if(c==(k+1)/2){
						break;
					}
				}
			} 
		}
		else{
			int c=0;
			rb(i,1,n){
				if(Col[i]==1){
					c++;
					cout<<i<<" ";
					if(c==(k+1)/2){
						break;
					}
				}
			} 
		}
		return 0;
	} 
	dig(1,0);
	int tmp1=INF,tmp2;
		rb(j,1,n){
			int tt=INF;
			for(auto it:g[j]){
				tt=min(depth[it],tt);
			}
			if(tt>=depth[j]-1){
				
			}
			else{
				if(depth[j]<tmp1)
				{
					tmp1=depth[j];
					tmp2=j;
				}
			}
		}
		tmp1=-INF;
		int tmp3;
		for(auto it:g[tmp2]){
			if(depth[it]<depth[tmp2]-1){
				if(depth[it]>tmp1){
					tmp1=depth[it];
					tmp3=it;
				}
			}
		}
		int now=tmp2;
		while(1){
			res.PB(now);
			if(now==tmp3) break;
			now=fa[now];
		}
		if(res.size()>k){
//			cout<<res.size()<<endl;
			cout<<1<<endl;
			for(int j=0,cc=1;j<res.size(),cc<=(k+1)/2;j+=2,cc++){
				cout<<res[j]<<" ";
			}
		}
		else{
			cout<<2<<endl;
			cout<<res.size()<<endl;
			for(auto it:res){
				cout<<it<<" ";
			}
		}
	return 0;
}
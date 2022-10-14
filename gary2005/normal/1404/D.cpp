/*
{By GWj
*/
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
vector<int> g[1000000+10];
vector<int> pai[1000000+10];
bool vis[1000000+10];
LL sum[2];
vector<int> poin[2];
void dfs(int now,bool col){
	sum[col]+=now;
	poin[col].PB(now);
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it]){
			dfs(it,col^1);
		}
	}
}
int main(){
	fastio;
	R(n);
	if(n%2==0){
		cout<<"First"<<endl;ff;
		rb(i,0,2*n-1){
			cout<<(i%n)+1<<" ";			
		}ff;
		return 0;
	}
	else{
		cout<<"Second"<<endl;ff;
		rb(i,1,n){
			g[i].PB(i+n);
			g[i+n].PB(i);
		}
		rb(i,1,2*n){
			int ty;
			R(ty);
			pai[ty].PB(i);
		}
		rb(i,1,n)
		{
			g[pai[i][0]].PB(pai[i][1]);
			g[pai[i][1]].PB(pai[i][0]);
		}
		rb(i,1,n+n){
			if(!vis[i]){
				dfs(i,0);
			}
		}
		if(sum[0]%(n+n)==0){
			for(auto it:poin[0]){
				cout<<it<<" ";	
			}
		}
		else{
			for(auto it:poin[1]){
				cout<<it<<" ";
			}
		}ff;
		return 0;
	}
	return 0;
}
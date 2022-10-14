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
const int MAXN=2400*10+1; 
int cnt=0;
int edge[MAXN][10];
bool have[MAXN];
void insert(vector<int>& s,int now=0,int is=0){
	if(is==s.size()) {have[now]=1;return;}
	if(edge[now][s[is]]);
	else {
		edge[now][s[is]]=++cnt;
	}
	insert(s,edge[now][s[is]],is+1);
}
int nxt[MAXN];
void ac(int now=0){
	rep(i,10){
		if(edge[now][i]){
			if(now){
				int trytry=nxt[now];
				while(!edge[trytry][i]&&trytry) trytry=nxt[trytry];
				trytry=edge[trytry][i];
				nxt[edge[now][i]]=trytry;
			}
			ac(edge[now][i]);
		} 
	}
}
int dp[1001][MAXN],x;
string s;
vector<int> Numm;
void dfs(int summ){
	if(summ==x){
		rep(i,Numm.size()){
			int sum=0;
			rep(j,Numm.size()){
				if(j<i) continue;
				sum+=Numm[j];
				if(x%sum==0&&sum!=x) return;
			}
		}
		insert(Numm);
	}
	rep(i,10){
		if(!i) continue;
		if(summ+i>x) break;
		Numm.PB(i);
		dfs(summ+i);
		Numm.POB();
	}
}
int main(){
	memset(edge,0,sizeof(edge));
	fastio;
	memset(dp,63,sizeof(dp));
	int rest=INF,n;
	R2(s,x);
	dfs(0);
	ac();
	n=s.length();
	dp[0][0]=0;
	rep(i,n){
		rb(j,0,cnt){
			if(dp[i][j]!=INF){
				check_min(dp[i+1][j],dp[i][j]+1);
				int match=j;
				while(match&&!edge[match][s[i]^48]){
					match=nxt[match];
				}
				if(!have[edge[match][s[i]^48]]){
					
					check_min(dp[i+1][edge[match][s[i]^48]],dp[i][j]);
				}
			}
		}
	}
	rb(i,0,cnt) check_min(rest,dp[n][i]);
	cout<<rest<<endl; 
	return 0;
}
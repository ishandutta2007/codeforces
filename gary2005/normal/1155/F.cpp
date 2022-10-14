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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=14;
//INDEX START FROM ZERO
pair<bool,vector<mp> > line[1<<MAXN][MAXN][MAXN];
pair<int,vector<mp> > dp[1<<MAXN],cycle[1<<MAXN][MAXN];
int n,m;
vector<int> g[MAXN];
bool check(int mask1,int mask2){
	int cnt=0;
	rep(i,n)
	{
		if(mask1&(1<<i))
			if(mask2&(1<<i)){
				cnt++;
			}	
	} 
	return cnt;
}
vector<mp> merge(vector<mp> v1,vector<mp> v2){
	if(v1.size()<v2.size()){
		for(auto it:v1)
			v2.PB(it);
		return v2;	
	}
	for(auto it:v2)
			v1.PB(it);
		return v1;	
}
int main(){
	fastio;
	R2(n,m);
	rep(i,m){
		int u,v;
		R2(u,v);
		u--;
		v--;
		g[u].PB(v);
		g[v].PB(u);
	}
	vector<mp> EMPTY(0);
	rep(i,1<<n)
		dp[i]=II(INF,EMPTY);
	rep(i,n)
		line[1<<i][i][i]=II(1,EMPTY);
	vector<mp> tmp;
	rep(i,1<<n){
		rep(k,n)
		rep(j,n){
			if(j==k&&line[i][k][j].SEC.size()!=0) continue;
			if(line[i][k][j].FIR){
				for(auto it:g[j]){
					if(i&(1<<it)){
						if(i-(1<<j)-(1<<k))
						if(it==k){
							tmp=line[i][k][j].SEC;
							tmp.PB(II(j,k));
							line[i][k][k]=II(1,tmp);
							dp[i]=II(tmp.size(),tmp);
						}
						continue;
					}
					line[i+(1<<it)][k][it]=line[i][k][j];
					line[i+(1<<it)][k][it].SEC.PB(II(j,it));
				}	
			}
		}
		
	}
	rep(i,1<<n){
		if(dp[i].FIR!=INF){
//			cout<<i<<" "<<dp[i].FIR<<endl;
			int smask=((1<<n)-1)^i;
			for(int s_=smask;s_;s_=smask&(s_-1)){
				rep(st,n){
					if(i&(1<<st))
					rep(to,n){
						if(st>=to)
						if(i&(1<<to)){
//							cout<<s_<<' '<<st<<" "<<to<<endl;
							int s=(s_)|((1<<st)|(1<<to));
							if(line[s][st][to].FIR)
							if(line[s][st][to].SEC.size()+dp[i].FIR<dp[i|s].FIR){
								dp[i|s].FIR=line[s][st][to].SEC.size()+dp[i].FIR;
								dp[i|s].SEC=merge(line[s][st][to].SEC,dp[i].SEC);
							}
						}
					}
				}
			}
		}
	}
	cout<<dp[(1<<n)-1].SEC.size()<<endl;
	for(auto it:dp[(1<<n)-1].SEC){
		cout<<it.FIR+1<<" "<<it.SEC+1<<endl;
	}
	return 0;
}
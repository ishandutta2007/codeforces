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
vector<pair<mp,int> > v;
int n,m;
bool vis[5002],col[5005];
vector<int> each[5002];
int cnt[2];
void dfs(int now,bool col2=0){
	cnt[col2]++;
	col[now]=col2;
	vis[now]=1;
	for(auto it:each[now]){
		if(!vis[it]){
			dfs(it,col2^1);
		}
		else{
			if(col[it]+col[now]!=1){
				cout<<"NO";
				exit(0);
			}
		}
	}
}
bool dp[5005][5005];
int res[5005];
void print(int now,bool ty){
//	cout<<"*"<<now<<endl;
	if(col[now]==ty){
		res[now]=2;
	}
	vis[now]=1;
	for(auto it:each[now]){
		if(!vis[it]){
			print(it,ty);
		}
	}
}
int main(){
	fastio;
	int n1,n2,n3;
	cin>>n>>m;
	cin>>n1>>n2>>n3;
	if(n1+n3==0){
		if(m){
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		rb(i,1,n)
			cout<<2;
		return 0;
	}
	if(n1+n2==0){
	 
		if(m){
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		rb(i,1,n)
			cout<<3;
		return 0;
	}
	if(n3+n2==0){
		if(m){
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		rb(i,1,n)
			cout<<1;
		return 0;
	} 
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		each[v].PB(u);
		each[u].PB(v); 
	} 
	rb(i,1,n){
		if(!vis[i]){
			cnt[0]=cnt[1]=0;
			dfs(i);
			v.PB(II(II(cnt[0],cnt[1]),i));
//			cout<<cnt[0]<<" "<<cnt[1]<<" "<<i<<endl; 
		}
	}
	dp[0][0]=1;
	rb(i,1,v.size()){
		rb(j,0,5000){
			if(j>=v[i-1].FIR.FIR)
			dp[i][j]|=dp[i-1][j-v[i-1].FIR.FIR];
			if(j>=v[i-1].FIR.SEC)
			dp[i][j]|=dp[i-1][j-v[i-1].FIR.SEC];
		}
	}
//	cout<<v.size()<<endl;
	memset(vis,0,sizeof(vis));
	if(dp[v.size()][n2]){
		int is=n2;
		rl(i,v.size(),1){
			if(is>=v[i-1].FIR.FIR&&dp[i-1][is-v[i-1].FIR.FIR]){
				print(v[i-1].SEC,0);
				is-=v[i-1].FIR.FIR;
			}
			else{
				print(v[i-1].SEC,1);
				is-=v[i-1].FIR.SEC;
			} 
		}
		rb(i,1,n){
			if(!res[i]){
				if(n1){
					res[i]=1;
					n1--;
				}
				else{
					res[i]=3;
				}
			}
		}
		cout<<"YES"<<endl;
		rb(i,1,n)
			cout<<res[i];
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
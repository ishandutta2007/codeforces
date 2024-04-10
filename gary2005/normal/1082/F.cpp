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
struct node{
	int flag;
	int num,m=0,fa,size=0;
	int v[10];
};
node v[500+20];
bool vis[505][12][505];
int dp[500+20][12][502];//ij,k 
int cnt=0;
int newnode(int num)
{
	node tmp;
	tmp.flag=0;
	tmp.num=num;
	memset(tmp.v,0,sizeof(tmp.v));
	v[++cnt]=tmp;
	return cnt;
}
int n,k;
int dfs(int now,int rest,int lasdep,int depth=1){
//	cout<<now<<" "<<rest<<endl;
	if(vis[now][rest][lasdep]){
		return dp[now][rest][lasdep];
	}
	int save=rest;
	if(lasdep==depth){
		rest--;
	}
	if(rest<0) return INF;
	vis[now][save][lasdep]=1;
	int res;
	int c[11][2];
	memset(c,0x3f,sizeof(c));
	c[0][1]=0;
	bool prev=1,Now=0;
	int have=0;
	rep(i,10)
		if(v[now].v[i]) have++;
	if(!have){
		if(rest>=1){
			res=INF;
		}
		 else{
		 	return dp[now][save][lasdep]=(depth-lasdep)*v[now].flag;
		 }
	}
	else{
		rep(i,10){
			int to=v[now].v[i];
			if(to){
				rb(j,0,10)
					c[j][Now]=INF;
				rl(j,rest,0){
					rb(k_,0,j){
						if(c[j-k_][prev]<INF){
							if(dfs(to,k_,lasdep,depth+1)<INF){
								c[j][Now]=min(c[j][Now],c[j-k_][prev]+dfs(to,k_,lasdep,depth+1));
							}
						if(dfs(to,k_,depth+1,depth+1)<INF){
							c[j][Now]=min(c[j][Now],c[j-k_][prev]+dfs(to,k_,depth+1,depth+1));
						}
					}
				}
				}
			swap(Now,prev);
			}
			
		}
	}
	res=c[rest][prev];
	res+=(depth-lasdep)*v[now].flag;
	res=min(res,INF);
	return dp[now][save][lasdep]=res;
}
int main(){
	fastio;
	newnode(0);
	cin>>n>>k;
	rb(i,1,n){
		string s;int m;
		cin>>s>>m;
		rep(j,s.length()){
			s[j]=s[j]-'0';
		}
		int stay=1;
		rep(j,s.length()){
			if(v[stay].v[s[j]]){
				stay=v[stay].v[s[j]];
			}
			else{
				newnode(s[j]);
				v[stay].v[s[j]]=cnt;
				stay=cnt;
			}
		}
		v[stay].flag+=m;
		v[stay].m+=m;
	}//
	int res=INF;
	rb(i,1,k+1){
		res=min(res,dfs(1,i,1));
	}
//	cout<<dfs(6 ,0,1,4)<<endl;
	cout<<res<<endl;
	return 0;
}
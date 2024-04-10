/*
This is an idea by Gary...
dp[i][j][0]->now the first one performs,the state is (i,j),F's points-S'spoints=dp[i][j][0]
dp[i][j][1]->now the second one performs...
dp[i][j][0]=max(dp[k][j][1]+NEW_)
dp[i][j][1]=min(dp[i][k][0]-NEW_)
if(k==0)
	if(this state bring new value)
		dp[i][j][0]=max(dp[i+1][j][0],dp[i+1][j][1])+  __NEW_VALUE__
	otherwise 
		dp[i][j][0]=dp[i+1][j][0]
if(k==1)
	if(this state bring new value)
		dp[i][j][1]=min(dp[i][j+1][1],dp[i][j+1][0])-  __NEW_VALUE__
	otherwise
		dp[i][j][1]=dp[i][j+1][1] 
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=2000+3; 
int n,m,s,t,p[2001],x[MAXN],y[MAXN],used[MAXN],cnt[MAXN][MAXN];
LL path[MAXN][MAXN],val[2001][MAXN],sum[MAXN][MAXN],dp[MAXN][MAXN][2];
map<LL,int> lisan;
vector<pair<LL,int> > tmps,tmpt;
vector<pair<int,LL> > each[2000+10];
void calc(int S){
	memset(used,0,sizeof(used));
	int mini=S;
	rb(i,2,n){
		used[mini]=1;
		for(auto it:each[mini]){
			path[S][it.FIR]=min(path[S][it.FIR],path[S][mini]+it.SEC);
		}
		mini=0;
		for(int i=1;i<=n;i++){
			if(used[i]==0&&path[S][i]<path[S][mini]){
				mini=i;
			}
		}
	}
}
LL check(int i,int j,int ty){
	if(ty==0){
		/*
		**|xxx
		**|xxx
		**|xxx
		**|***
		******
		*/
		return cnt[i][j+1]-cnt[i+1][j+1];
	} 
	else{
		/*
		**xxxx
		**xxxx
		*-----
		******
		******
		*/
		return cnt[i+1][j]-cnt[i+1][j+1];
	}
}
LL get_val(int i,int j,int ty){
	if(ty==0){
		/*
		**|xxx
		**|xxx
		**|xxx
		**|***
		******
		*/
		return sum[i][j+1]-sum[i+1][j+1];
	} 
	else{
		/*
		**xxxx
		**xxxx
		*-----
		******
		******
		*/
		return sum[i+1][j]-sum[i+1][j+1];
	}
}
int main(){
	scanf("%d %d %d%d",&n,&m,&s,&t);
	rep(i,MAXN)
		rep(j,MAXN)
			path[i][j]=(LL)(1e14);
	rb(i,1,n)
		scanf("%d",&p[i]);
	rb(i,1,n) path[i][i]=0;
	rb(i,1,m){
		int u,v;LL w;
		scanf("%d %d%I64d",&u,&v,&w);
		each[u].PB(II(v,w));
		each[v].PB(II(u,w));
	}
	int tot=0;
	calc(s),calc(t);
	rb(i,1,n){
		tmps.PB(II(path[s][i],i)),lisan[path[s][i]]=1;
	}
	for(map<LL,int> :: IT ite=lisan.begin();ite!=lisan.end();ite++){
		ite->SEC=++tot;
	}
	rep(i,n)
		tmps[i].FIR=lisan[tmps[i].FIR];
	lisan.clear();
	rb(i,1,n)
		tmpt.PB(II(path[t][i],i)),lisan[path[t][i]]=1;
	tot=0;
	for(map<LL,int> :: IT ite=lisan.begin();ite!=lisan.end();ite++){
		ite->SEC=++tot;
	}
	rep(i,n)
		tmpt[i].FIR=lisan[tmpt[i].FIR];
	sort(ALL(tmps));
	sort(ALL(tmpt));
	rep(i,n)
		x[tmps[i].SEC]=tmps[i].FIR;
	rep(i,n)
		y[tmpt[i].SEC]=tmpt[i].FIR;
	rb(i,1,n)
		val[x[i]][y[i]]+=p[i],cnt[x[i]][y[i]]++/*,cout<<x[i]<<" "<<y[i]<<" "<<p[i]<<"\n"*/;
	rl(i,n,1)
		rl(j,n,1){
			sum[i][j]=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1]+val[i][j];
			cnt[i][j]+=cnt[i+1][j]+cnt[i][j+1]-cnt[i+1][j+1];
		}
	rl(i,n,1)
		rl(j,n,1)
		{
			if(check(i,j-1,0)){
				dp[i][j][0]=max(dp[i+1][j][0],dp[i+1][j][1])+get_val(i,j-1,0);
			}
			else{
				dp[i][j][0]=dp[i+1][j][0];
			}
			if(check(i-1,j,1)){
				dp[i][j][1]=min(dp[i][j+1][1],dp[i][j+1][0])-get_val(i-1,j,1);
			}
			else{
				dp[i][j][1]=dp[i][j+1][1];
			}
		}
	LL f=dp[1][1][0];
	if(f<0){
		puts("Cry");
	} 
	if(f==0){
		puts("Flowers");
	}
	if(f>0){
		puts("Break a heart");
	}
	return 0;
}
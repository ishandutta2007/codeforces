/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5+233;
vector<int> g[MAXN];
int n,dp[MAXN];
void dfs(int now,int pre){
	vector<int> ch;
	for(auto it:g[now]) if(it!=pre) ch.PB(it);
	if(ch.empty()){
		dp[now]=0;
		return ;
	}
	vector<int> tmp;
	for(auto it:ch) dfs(it,now),tmp.PB(dp[it]);
	sort(ALL(tmp));
	reverse(ALL(tmp));
	dp[now]=ch.size();
	rep(i,tmp.size()) check_max(dp[now],tmp[i]+i);
}
vector<int> pre,suf,ord;
void solve(int now){
	vector<mp> tmptmp;
	for(auto it:g[now]) tmptmp.PB(II(dp[it],it));
	sort(ALL(tmptmp));
	reverse(ALL(tmptmp));
	pre.resize(g[now].size());
	suf.resize(g[now].size());
	ord.clear();
	rep(i,pre.size()){
		if(i) pre[i]=pre[i-1];
		else pre[i]=0;
		check_max(pre[i],tmptmp[i].FIR+i);
	}
	rl(i,suf.size()-1,0){
		if(i!=suf.size()-1) suf[i]=suf[i+1];
		else suf[i]=0;
		check_max(suf[i],tmptmp[i].FIR+i);
	}
	for(auto it:tmptmp) ord.PB(it.SEC);
}
int ans=-INF;
void cr(int now,int las){
	solve(now);
	vector<int> P,S,O;
	P=pre;
	S=suf;
	O=ord;
	vector<int> Tmp;
	for(auto it:g[now]) Tmp.PB(dp[it]);
	sort(ALL(Tmp));
	reverse(ALL(Tmp));
	check_max(ans,int(Tmp.size()));
	rep(i,g[now].size()) check_max(ans,int(Tmp[i]+g[now].size()-1));
	rep(i,g[now].size()) if(i) check_max(ans,Tmp[i]+Tmp[0]+i-1);
	rep(i,O.size()){
		int nx=O[i];
		if(nx==las) continue;
		dp[now]=g[now].size()-1;
		if(i) check_max(dp[now],P[i-1]);
		if(i!=O.size()-1) check_max(dp[now],S[i+1]-1);
		cr(nx,now);
	}
}
int pp=0;
int query(int r){
	printf("? %d\n",r);
	ff;
	int x;
	scanf("%d",&x);
	pp=x;
	return x;
}
bool cmp(int A,int B){
	return dp[A]>dp[B];
}
int work(int now,int pre){
	if(pre==0){
		if(g[now].empty()){
			puts("! 1 1");ff;
			return 0;
		}
		else{
			sort(ALL(g[now]),cmp);
			vector<int> ans;
			for(auto it:g[now]){
				int tmp=work(it,now);
				if(tmp) ans.PB(tmp);
				if(ans.size()==2) break;
			}
			while(ans.size()<2) ans.PB(now);
			printf("! %d %d\n",ans[0],ans[1]);ff;
		}
	}
	else{
		vector<int> ch;
		for(auto it:g[now]) if(it!=pre) ch.PB(it);
		sort(ALL(ch),cmp);
		for(auto it:ch){
			int tmp=work(it,now);
			if(tmp) return tmp;
			if(pp!=now) return 0;
		}
		if(ch.empty()){
			if(query(now)==now) return now;
			return 0;
		}
		else{
			return now;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	cr(1,0);
	printf("%d\n",ans);ff;
	int f;
	scanf("%d",&f);
	dfs(f,0);
	work(f,0);
	return 0;
}
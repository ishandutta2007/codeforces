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
const int MAXLEN=1e5+20;
struct state{
	int len,link,minlen;
	unordered_map<char,int> ch;
};
struct SAM{	
	int sz=0,last;
	state st[MAXLEN+MAXLEN];
	bool vis[MAXLEN+MAXLEN];
	int siz[MAXLEN+MAXLEN];// 
	vector<int> g[MAXLEN+MAXLEN];
	int siz2[MAXLEN+MAXLEN];// 
	void sam_init(){
		memset(vis,0,sizeof(vis));
		st[0].len=0;
		st[0].link=-1;
		sz=0;
		last=0;
	}
	SAM(){
		sam_init();
	}
	void sam_extend(char c){
		int cur=++sz;
		st[cur].len=st[last].len+1;
		int p=last;
		while(p!=-1&&st[p].ch.find(c)==st[p].ch.end()){
			st[p].ch[c]=cur;
			p=st[p].link;
		} 
		if(p==-1){
			st[cur].link=0;
		}
		else{
			int q=st[p].ch[c];
			if(st[q].len==st[p].len+1){
				st[cur].link=q;
			}
			else{
				int clone;
				clone=++sz;
				st[clone].len=st[p].len+1;
				st[clone].ch=st[q].ch;
				st[clone].link=st[q].link;
				while(p!=-1&&st[p].ch.find(c)!=st[p].ch.end()&&st[p].ch[c]==q){
					st[p].ch[c]=clone;
					p=st[p].link;
				}
				st[cur].link=st[q].link=clone;
			}
		}
		last=cur;
		siz[cur]++;
	}
	void dfs(int now){
		vis[now]=true;
		for(auto it:g[now]){
			if(!vis[it]) dfs(it);
			siz[now]+=siz[it];
		}
	}
	void dfs2(int now){
		vis[now]=1;
		for(auto it:g[now]){
			if(!vis[it]) dfs2(it);
			siz2[now]+=siz2[it];
		}
	}
	void run(){
		rb(i,1,sz) g[st[i].link].PB(i);
		rb(i,0,sz) if(!vis[i]) dfs(i);
		rb(i,0,sz) g[i].clear();
		memset(vis,0,sizeof(vis));
		siz2[0]=1;
		rb(i,0,sz) for(auto ite=st[i].ch.begin();ite!=st[i].ch.end();ite++) g[ite->SEC].PB(i);
		rb(i,0,sz) if(!vis[i]) dfs2(i);
		rb(i,1,sz) st[i].minlen=st[i].len-siz2[i]+1;
	}
	void gen(string s){
		rep(i,s.length()) sam_extend(s[i]);	
	}
}sam;
string s[MAXLEN];
int vis[MAXLEN+MAXLEN];
int cnt[MAXLEN+MAXLEN];
void paint(int now,int col){
	while(now!=-1){
		if(vis[now]==col) break;
		vis[now]=col;
		cnt[now]++;
		now=sam.st[now].link;
	}
}
int n,k;
LL dp[MAXLEN+MAXLEN];
void calc(int now){
	vis[now]=1;
	if(now!=0){
		if(cnt[now]>=k)
		dp[now]=sam.siz2[now];
		int pre=sam.st[now].link;
		if(!vis[pre]) calc(pre);
		dp[now]+=dp[pre];
	}
}
int main(){
	scanf("%d%d",&n,&k);
	rb(i,1,n){
		sam.last=0;
		cin>>s[i];
		sam.gen(s[i]);
	}
	sam.run();
	rb(i,1,n){
		int now=0;
		rep(j,s[i].length()){
			now=sam.st[now].ch[s[i][j]];
			paint(now,i);
		}		
	}
	memset(vis,0,sizeof(vis));
	rb(i,1,sam.sz){
		if(!vis[i]){
			calc(i);
		}
	}
	rb(i,1,n){
		int now=0;
		LL rest=0;
		rep(j,s[i].length()){
			now=sam.st[now].ch[s[i][j]];
			rest+=dp[now];
		}
		printf("%lld ",rest);
	}
	return 0;
}
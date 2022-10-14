/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
const int MAXLEN=1e6+20;
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
const int MOD=998244353;
const int MUL=19260817;
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
int query(string s){
	int len=0,now=0;
	int rest=0;
	int inv=quick(MUL,s.length()/2);
	int hs=0;
	unordered_map<int,int> umap;
	rep(i,s.length()){
		char c=s[i];
		hs=(1ll*hs*MUL+s[i])%MOD;
		if(i>=s.length()/2) hs+=MOD-1ll*s[i-s.length()/2]*inv%MOD,hs%=MOD;
		while(now!=-1&&sam.st[now].ch.find(c)==sam.st[now].ch.end()){
			now=sam.st[now].link;
			len=sam.st[now].len;
		}
		if(now==-1){
			now=0;
		}
		else{
			while(sam.st[now].link!=-1&&sam.st[sam.st[now].link].len+1>=s.length()/2) now=sam.st[now].link,len=sam.st[now].len;
			now=sam.st[now].ch[c];
			len++;
			if(umap.find(hs)==umap.end()){
				rest+=(len>=s.length()/2)*sam.siz[now];
			}
		}
		if(i>=s.length()/2-1){
			umap[hs]=1;
		}
	}
	return rest;
}
int main(){
	string s;
	cin>>s;
	sam.gen(s);
	sam.run();
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		string ss;
		cin>>ss;
		ss=ss+ss;
		printf("%d\n",query(ss));
	}
	return 0;
}
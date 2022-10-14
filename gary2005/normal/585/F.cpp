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
const int MAXLEN=2e5+20;
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
const int MOD=1e9+7;
int dp[2][2][2001][1001];
mp trans[2001][1001][10];
int d;
int dd[51],tmp[51];
string s;
int solve(string b){
	memset(dp,0,sizeof(dp));
	int Tmp=0;
	dp[0][1][0][0]=1;
	int t=1;
	rl(i,d-1,0){
		dd[i]=dd[i+1];
		dd[i]+=1ll*t*(b[i]^48)%MOD;
		dd[i]%=MOD;
		t=10ll*t%MOD;
	}
	rb(i,0,d-1) dd[i]++;
	tmp[0]=1;
	rb(i,1,d){
		tmp[i]=10ll*tmp[i-1]%MOD;
	}
	rep(i,d){
		memset(dp[(i+1)&1],0,sizeof(dp[(i+1)&1]));
		rep(f,2){
			rb(j,0,sam.sz){
				rb(k,0,s.length()){
					if(dp[i&1][f][j][k]){
						if(k==d/2){
							(Tmp+=1ll*dp[i&1][f][j][k]*(f? dd[i]:tmp[d-i])%MOD)%=MOD;
							break;
						}
						rep(z,10){
							if(f==1&&(z>(b[i]^48))) break;
							int nj,nk;
							nj=trans[j][k][z].FIR;
							nk=trans[j][k][z].SEC;
							(dp[(i+1)&1][f&(z==(b[i]^48))][nj][nk]+=dp[i&1][f][j][k])%=MOD;
						}
					}
				}
			}
		}
	}
	rep(f,2)
		rb(j,0,sam.sz){
			(Tmp+=dp[d&1][f][j][d/2])%=MOD;
		}
	return Tmp;
}
int main(){
	string newstring;
	cin>>s;
	int cnt=0;
	rep(i,s.length()){
		if(i&&s[i]==s[i-1]){
			cnt++;
		}
		else{
			cnt=1;
		}
		if(cnt<=25){
			newstring.PB(s[i]);
		}
	}
	s=newstring;
	sam.gen(s);
	string x,y;
	cin>>x>>y;
	rb(j,0,sam.sz){
		rb(k,0,s.length()){
			for(char l='0';l<='9';++l){
				int Tmpj,Tmpk;
				Tmpj=j,Tmpk=k;
				while(Tmpj&&sam.st[Tmpj].ch.find(l)==sam.st[Tmpj].ch.end()) Tmpj=sam.st[Tmpj].link,Tmpk=sam.st[Tmpj].len;
				if(sam.st[Tmpj].ch.find(l)==sam.st[Tmpj].ch.end());
				else{
					Tmpj=sam.st[Tmpj].ch[l];
					Tmpk++;
				}
				trans[j][k][l^48]=II(Tmpj,Tmpk);
			}
		}
	}
	d=x.length();
	rl(i,d-1,0){
		if(x[i]!='0'){
			x[i]--;
			break;
		}
		x[i]='9';
	}
	int rest=solve(y);
	rest-=solve(x);
	rest+=MOD;
	rest%=MOD;
	cout<<rest<<endl;
	return 0;
}
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
const int MAXLEN=100000+20;
struct state{
	int len,link,minlen;
	unordered_map<char,int> ch;
};
struct SAM{	
	int sz=0,last;
	state st[MAXLEN+MAXLEN];
	bool vis[MAXLEN+MAXLEN];
	int mini[MAXLEN+MAXLEN],maxi[MAXLEN+MAXLEN];// 
	vector<int> g[MAXLEN+MAXLEN];
	void sam_init(){
		memset(mini,63,sizeof(mini));
		memset(maxi,-63,sizeof(maxi));
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
	}
	void dfs(int now){
		vis[now]=true;
		for(auto it:g[now]){
			if(!vis[it]) dfs(it);
			check_min(mini[now],mini[it]);
			check_max(maxi[now],maxi[it]);
		}
	}
	void run(){
		rb(i,1,sz) g[st[i].link].PB(i);
		rb(i,0,sz) {	if(!vis[i]) dfs(i);}
	}
	void gen(string s){
		rep(i,s.length()){
			sam_extend(s[i]);
			check_min(mini[last],i);
			check_max(maxi[last],i);
		}
	}
}sam,sam2;
int tmp[1002][2];
int totlen;
int query(){
	string s;
	cin>>s;
	int len=s.length();
	memset(tmp,63,sizeof(tmp));
	int now=0;
	rep(i,len){
		if(sam.st[now].ch.find(s[i])==sam.st[now].ch.end()) break;
		now=sam.st[now].ch[s[i]];
		tmp[i+1][0]=sam.mini[now]+1;
	}
	now=0;
	rl(i,len-1,0){
		if(sam2.st[now].ch.find(s[i])==sam2.st[now].ch.end()) break;
		now=sam2.st[now].ch[s[i]];
		tmp[len-i][1]=sam2.mini[now]+1;
	}
	rb(i,1,len-1){
//		cout<<tmp[i][0]<<' '<<tmp[len-i][1]<<endl;
		if(tmp[i][0]+tmp[len-i][1]<=totlen) return 1;
	} 
	return 0;
}
int main(){
	string s;
	cin>>s;
	totlen=s.length();
	sam.gen(s);
	sam.run();
	reverse(ALL(s));
	sam2.gen(s);
	sam2.run();
	int rest=0;
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		rest+=query();
	}
	cout<<rest<<endl;
	return 0;
}
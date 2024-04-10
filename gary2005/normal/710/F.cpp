/**
 *    author:  gary
 *    created: 12.11.2021 18:28:24
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXLEN=3e5+20;
struct state{
	int len,link,minlen;
	unordered_map<char,int> ch;
};
int cnt[MAXLEN+MAXLEN];
int vis[MAXLEN+MAXLEN];
int have[MAXLEN+MAXLEN];
struct SAM{
	int sz=0,last;
	state st[MAXLEN+MAXLEN];
	bool vis[MAXLEN+MAXLEN];
	int siz[MAXLEN+MAXLEN];
	vector<int> g[MAXLEN+MAXLEN];
	int siz2[MAXLEN+MAXLEN];
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
		int cur;
        cur=++sz;
		st[cur].len=st[last].len+1;
		int p=last;
		while(p!=-1&&st[p].ch.find(c)==st[p].ch.end()){
			st[p].ch[c]=cur;
			p=st[p].link;
		}
        bool fucking=(p==last);
		if(p==-1){
			st[cur].link=0;
		}
		else{
			int q=st[p].ch[c];
			if(st[q].len==st[p].len+1){
				st[cur].link=q;
                if(fucking){
                    last=q;
                    siz[q]++;
                    return;
                }
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
                if(fucking){
                    last=clone;
                    siz[clone]++;
                    return;
                }
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
#define ff fflush(stdout)
void jump(int x,int m){
    if(vis[x]==m) return ;
    vis[x]=m;
    have[x]=cnt[x];
    if(sam.st[x].link!=-1) jump(sam.st[x].link,m),have[x]+=have[sam.st[x].link];
    // cout<<x<<" "<<have[x]<<endl;
}
int main(){
    memset(vis,63,sizeof(vis));
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>m;
    map<string,int> edid;
    while(m--){
        int t;
        string s;
        cin>>t>>s;
        if(t==1){
            sam.last=0;
            sam.gen(s);
            // cout<<sam.last<<endl;
            cnt[sam.last]++;
            edid[s]=sam.last;
            continue;
        }
        if(t==2){
            cnt[edid[s]]--;
            continue;
        }
        if(t==3){
            sam.last=0;
            LL ans=0;
            rep(i,s.length()){
                sam.sam_extend(s[i]);
                int now=sam.last;
                jump(now,m);
                ans+=have[now];
            }
            cout<<ans<<endl;ff;
        }
    }
    return 0;
}
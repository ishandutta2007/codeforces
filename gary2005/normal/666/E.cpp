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
	int len,link,minlen,rt;
	unordered_map<char,int> ch;
};
int cnt=0;
vector<int> l(1,0),r(1,0);
vector<mp> ret(1,II(0,0));
mp get(mp A,mp B){
	if(A.SEC!=B.SEC){
		if(A.SEC<B.SEC) return B;
		return A;
	}
	return min(A,B);
}
int newnodes(){
	cnt++;
	ret.PB(II(0,0));
	l.PB(0);
	r.PB(0);
	return cnt;
}
const int N=1<<16;
void add(int now,int pos,int L=1,int R=N+1){
	if(L>pos||R<=pos) return;
	if(L==R-1){
		ret[now].FIR=L;
		ret[now].SEC++;
		return ;
	}
	int mid=(L+R)>>1;
	if(!l[now]){
		l[now]=newnodes();
		r[now]=newnodes();
	}
	add(l[now],pos,L,mid);
	add(r[now],pos,mid,R);
	ret[now]=get(ret[l[now]],ret[r[now]]);
}
int merge(int A,int B,int L=1,int R=N+1){
	if(A==0||B==0){
		return A+B;	
	}
	if(L==R-1){
		newnodes();
		ret[cnt].FIR=L;
		ret[cnt].SEC=ret[A].SEC+ret[B].SEC; 
		return cnt;
	}
	newnodes();
	int now=cnt;
	int mid=(L+R)>>1;
	l[now]=merge(l[A],l[B],L,mid);
	r[now]=merge(r[A],r[B],mid,R);
	ret[now]=get(ret[l[now]],ret[r[now]]);
	return now;
}
mp query(int a,int b,int now,int L=1,int R=N+1){
	if(!now) return II(0,0);
	if(R<=a||L>=b) return II(0,0);
	if(R<=b&&L>=a) {
		return ret[now];	
	}
	int mid=(L+R)>>1;
	return get(query(a,b,l[now],L,mid),query(a,b,r[now],mid,R));
}
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
		st[0].rt=newnodes();
		last=0;
	}
	SAM(){
		sam_init();
	}
	void sam_extend(char c,int id){
		int cur=++sz;
		st[cur].rt=newnodes();
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
				st[clone].rt=newnodes();
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
		add(st[cur].rt,id);
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
	void dfs3(int now){
		for(auto it:g[now]){
			dfs3(it);
			st[now].rt=merge(st[now].rt,st[it].rt);
//			cout<<now<<' '<<it<<' '<<' '<<ret[st[it].rt].FIR<<' '<<ret[st[it].rt].SEC<<")("<<ret[st[now].rt].SEC<<' '<<ret[st[now].rt].SEC<<endl;
		}
	}
	void run(){
		rb(i,1,sz) g[st[i].link].PB(i);
		rb(i,0,sz) if(!vis[i]) dfs(i);
		dfs3(0);
		rb(i,0,sz) g[i].clear();
		memset(vis,0,sizeof(vis));
		siz2[0]=1;
		rb(i,0,sz) for(auto ite=st[i].ch.begin();ite!=st[i].ch.end();ite++) g[ite->SEC].PB(i);
		rb(i,0,sz) if(!vis[i]) dfs2(i);
		rb(i,1,sz) st[i].minlen=st[i].len-siz2[i]+1;
	}
}sam;
int stay[500000+10];
int le[500000+10];
int bz[MAXLEN+MAXLEN][20];
int main(){
	//--------------------
//	int A=newnodes(),B=newnodes();
//	add(A,1);
//	add(B,1);
//	A=merge(A,B);
//	cout<<ret[A].SEC<<endl;
//	return 0;
	//--------------------
	string s;
	cin>>s;
	int m;
	cin>>m;
	rb(i,1,m){
		string t;
		cin>>t;
		sam.sam_extend('#',m+1);
		rep(j,t.length()){
			sam.sam_extend(t[j],i);
		}
	}
	sam.run();
//	cout<<sam.st[0].rt<<' '<<ret[sam.st[0].rt].SEC<<endl;
	int leng=s.length();
	int now=0,len=0;
	rb(i,1,leng){
		while(now!=-1&&sam.st[now].ch.find(s[i-1])==sam.st[now].ch.end()){
			now=sam.st[now].link;
			len=sam.st[now].len;
		}
		if(now==-1){
			now=0;
			len=0;
		}
		else{
			now=sam.st[now].ch[s[i-1]];
			len++;
		}
		stay[i]=now;
		le[i]=len;
	}
	rb(i,1,sam.sz){
		bz[i][0]=sam.st[i].link;
	}
	rb(j,1,19){
		rb(i,1,sam.sz){
			bz[i][j]=bz[bz[i][j-1]][j-1];		
		}
	}
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		int l,r,pl,pr;
		scanf("%d%d%d%d",&l,&r,&pl,&pr);
		pl=pr-pl+1;
		if(le[pr]<pl){
			printf("%d 0\n",l);	
			continue;
		}
		int now=stay[pr];
		rl(i,19,0){
			if(sam.st[bz[now][i]].len>=pl){
				now=bz[now][i];
			}
		}
		now=sam.st[now].rt;
		mp rest=query(l,r+1,now);
		if(rest.SEC==0) rest.FIR=l;
		printf("%d %d\n",rest.FIR,rest.SEC);
	}
	return 0;
}
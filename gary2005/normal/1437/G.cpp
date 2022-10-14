/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int N=1<<20;
struct SEGTREE{
	int tree[N+N];
	multiset<int> s[N+1];
	void init(){
		memset(tree,-63,sizeof(tree));
	}
	void modify(int index,int old,int now,int ty=0){
		if(ty){
			s[index].insert(now);
		}
		else{
			s[index].erase(s[index].lower_bound(old));
			s[index].insert(now);
		}
		index+=N-1;
		auto ite=s[index-N+1].end();
		ite--;
		tree[index]=*ite;
		index>>=1;
		while(index){
			tree[index]=max(tree[index<<1],tree[index<<1|1]);
			index>>=1;
		}
	}
	int query(int a,int b,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b){
			return -INF;
		}
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return max(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
}sgt;
struct TRIE{
	int root=0;
	int cnt=0;
	int fail[600000+20]={0};
	int son[600000+20][26];
	int fa[600000+20]={0};
	void init(){
		memset(son,0,sizeof(son));
	}
	int insert(string& s,int now=0,int stay=0){
		if(now==s.length()) return stay;
		int need=s[now]-'a';
		if(!son[stay][need]){
			fa[cnt+1]=stay;
			son[stay][need]=++cnt;
		}
		insert(s,now+1,son[stay][need]);
	}
	void go_for_fail(){
		queue<mp> q;
		rep(i,26)
			if(son[0][i])
				q.push({son[0][i],i});
		while(!q.empty()){
			int now=q.front().FIR;
			int need=q.front().SEC;
			q.pop();
			int pre=fail[fa[now]];
			if(fa[now]!=0)
				while(true){
					if(son[pre][need]){
						fail[now]=son[pre][need];
						break;
					}
					if(pre==0) break;
					pre=fail[pre];
				}
			rep(i,26)
				if(son[now][i])
					q.push(II(son[now][i],i));
		}
	}
}trie; 
int n,m,id[300000+20];
string s;
vector<pair<int,mp> > q;
vector<int> g[600000+20];
int val[600000+20],in[600000+20],out[600000+20];
int dfn[600000+20],cnt_=0,heavy[600000+20]={0},siz[600000+20],top[600000+20],fa[600000+20];
void dfs2(int now){
	dfn[now]=++cnt_;
	if(heavy[now]){
		top[heavy[now]]=top[now];
		dfs2(heavy[now]);
	}
	for(auto it:g[now]){
		if(it!=heavy[now]){
			top[it]=it;
			dfs2(it);
		}
	}
}
void dfs1(int now){
	heavy[now]=0;
	siz[now]=1;
	for(auto it:g[now]){
		fa[it]=now;
		dfs1(it);
		if(heavy[now]==0||siz[it]>siz[heavy[now]]){
			heavy[now]=it;
		}
		siz[now]+=siz[it];
	}
}
int main(){
	trie.init();	sgt.init();
	scanf("%d%d",&n,&m);
	memset(val,63,sizeof(val));
	rb(i,1,n){
		cin>>s;
//		trie.insert(s);
		id[i]=trie.insert(s);
		val[i]=0;
	}
	rb(i,1,m){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int iD,x;
			scanf("%d%d",&iD,&x);
			q.PB(II(1,II(iD,x)));
		}
		else{
			cin>>s;
			q.PB(II(2,II(trie.insert(s),0)));
		}
	}
	trie.go_for_fail();
	rb(i,1,trie.cnt){
//		cout<<i<<"->"<<trie.fail[i]<<endl;
		g[trie.fail[i]].PB(i);
	}
	dfs1(0);
	top[0]=0;
	dfs2(0);
	rb(i,1,n){
//			cout<<"*"<<dfn[i]<<endl;
		sgt.modify(dfn[id[i]],0,0,1);
	}
	for(auto it:q){
		int ty;
		ty=it.FIR;
		if(ty==1){
			int id_,x;
			id_=it.SEC.FIR;
			x=it.SEC.SEC;
			int old=val[id_];
			val[id_]=x; 
//			cout<<id[id_]<<" "<<val[id[id_]]<<' '; 
			id_=dfn[id[id_]];
//			cout<<id_<<' '<<old<<" "<<x<<endl;
			sgt.modify(id_,old,x);
		} 
		else{
			int id_=it.SEC.FIR;
			int rest=-1;
//			cout<<dfn[id[5]]<<" "<<sgt.tree[N-1+dfn[id[5]]]<<' '<<sgt.s[dfn[id[5]]].size()<<' '<<*sgt.s[dfn[id[5]]].begin()<<endl;
			while(id_){
				int now=id_;
				while(now){
					int l=dfn[top[now]],r=dfn[now];
//					cout<<l<<'-'<<r<<endl;
					check_max(rest,sgt.query(l,r+1));
					now=fa[top[now]];
				}	
				id_=trie.fa[id_];
			}
			printf("%d\n",rest);
		}
	}
	return 0;
}
/** 
  * trie 
  * fail 
  	fail
	 max 
  * fail 
  *	
  **/
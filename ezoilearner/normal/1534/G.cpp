#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

const int inf=1e9;
int n;
#define Maxn 800010
int d[Maxn],len;int mn,mx;
map<int,int> mp;
vector<int> vec[Maxn];
ll Ans=0;

struct Node{
	int a,tg,tl;
	ll sum;ll tsum;
	int son[2],fa;
}tree[Maxn<<2];int cnt=0;int root;
#define ls tree[k].son[0]
#define rs tree[k].son[1]
bool isrt(int k){return tree[tree[k].fa].son[0]!=k&&tree[tree[k].fa].son[1]!=k;}
int who(int k){return tree[tree[k].fa].son[1]==k;}
void push_up(int k){
	tree[k].sum=tree[ls].sum+tree[rs].sum+1ll*tree[k].a*tree[k].tl;
	tree[k].tsum=tree[ls].tsum+tree[rs].tsum+tree[k].tl;
}
void make_tag(int k,int t){
	tree[k].tg+=t;tree[k].sum+=1ll*t*tree[k].tsum;
	tree[k].a+=t;
}
void push_down(int k){
	if(ls)make_tag(ls,tree[k].tg);
	if(rs)make_tag(rs,tree[k].tg);
	tree[k].tg=0;
}
void rot(int k){
	int f=tree[k].fa,ff=tree[f].fa,dir=who(k);
	tree[k].fa=ff;
	if(!isrt(f))tree[ff].son[who(f)]=k;
	tree[f].son[dir]=tree[k].son[dir^1];tree[tree[k].son[dir^1]].fa=f;
	tree[k].son[dir^1]=f;tree[f].fa=k;
	push_up(f);
	push_up(k);
}
int st[Maxn<<2],tp;
void Splay(int u,int to){
	for(int x=u;x!=to;x=tree[x].fa)st[++tp]=x;
	while(tp)push_down(st[tp--]);
	for(int f;tree[u].fa!=to;rot(u))
		if(tree[f=tree[u].fa].fa!=to)rot(who(u)==who(f)?f:u);
	if(!to)root=u;
}

int hh;
void insert(int &k,int x,int t){
	if(!k){
		k=++cnt;tree[k].fa=t;
		hh=k;
		tree[k].a=0;tree[k].tl=x;tree[k].tg=0;
		push_up(k);
		return;
	}
	push_down(k);
	if(tree[k].a>=0)insert(ls,x,k);
	else insert(rs,x,k);
	push_up(k);
}

void insert(int x){
	if(!x)return;
	insert(root,x,0);
	Splay(hh,0);
}

int Find(ll x){
	int k=root;
	while(k){
		push_down(k);
		if(tree[ls].tsum<x&&tree[ls].tsum+tree[k].tl>=x)return k;
		if(tree[ls].tsum>=x)k=ls;
		else{
			x-=tree[ls].tsum+tree[k].tl;
			k=rs;
		}
	}
}

void Add(ll x,int ad){
	if(!x)return;
	int k=Find(x);
	Splay(k,0);
	make_tag(ls,ad);
	if(x-tree[ls].tsum==tree[k].tl){
		tree[k].a+=ad;
		push_up(k);
		return;
	}	
	int pre=tree[k].tl;
	tree[k].a+=ad;tree[k].tl=x-tree[ls].tsum;pre-=tree[k].tl;
	if(rs){
		int t=rs;
		while(tree[t].son[0])t=tree[t].son[0];
		Splay(t,k);
		int c=++cnt;
		tree[c].a=tree[k].a-ad;tree[c].tl=pre;
		tree[t].son[0]=c;tree[c].fa=t;
		push_up(c);push_up(t);push_up(k); 
	}else{
		int c=++cnt;rs=c;tree[c].fa=k;
		tree[c].a=tree[k].a-ad;tree[c].tl=pre;
		push_up(rs);
		push_up(k);
	}
}

void gao(int k){
	if(!k)return;
	push_down(k);
	if(tree[k].a>0)gao(ls);
	else{
		Ans+=tree[k].sum-tree[rs].sum;
		gao(rs);
	}
}

int main(){
	rd(n);
	int x,y;
	mn=inf;mx=0;
	rep(i,1,n){
		rd(x);rd(y);mx=max(mx,x);
		mn=min(mn,x);
		Ans+=x;
		int t=x+y;
		if(!mp[t]){
			mp[t]=++len;d[len]=t;
		}
		vec[mp[t]].push_back(x);
	}	
	Ans-=1ll*n*mn;
	rep(i,1,len)sort(vec[i].begin(),vec[i].end());
	sort(d+1,d+len+1);
	int all=0;
	insert(inf*2);
	rep(i,1,len){
		insert(d[i]-d[i-1]);
		int t=mp[d[i]];
		Add(vec[t][0]-mn,-(int)vec[t].size());
		for(int j=0;j<vec[t].size();++j){
			int ad=2*j+2-vec[t].size();
			Add(vec[t][j]-mn,-ad);
			if(j+1<vec[t].size())Add(vec[t][j+1]-mn,ad);
			else{
				Add(tree[root].tsum,ad);
			}
		}
	}
	gao(root);
	printf("%lld\n",Ans);
	return 0;
}
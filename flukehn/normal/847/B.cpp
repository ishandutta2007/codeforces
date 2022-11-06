#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=2e5+11;
int a[N],b[N],n;
vector<int> V[N];
struct SegTree{
	int mi[N<<2];
	#define all 1,1,n
	#define mid (L+R>>1)
	#define lson o<<1,L,mid
	#define rson o<<1|1,mid+1,R
	void build(int o,int L,int R){
		mi[o]=inf;
		if(L==R)return;
		build(lson),build(rson);
	}
	void push_up(int o){
		mi[o]=min(mi[o<<1],mi[o<<1|1]);
	}
	void updata(int o,int L,int R,int x,int v){
		if(L==R) {
			mi[o]=v;
			return; 
		}
		if(x<=mid)updata(lson,x,v);
		else updata(rson,x,v);
		push_up(o);
	}
	int query(int o,int L,int R,int l,int r){
		if(L==l&&R==r){
			return mi[o];
		}
		if(r<=mid)return query(lson,l,r);
		else if(l>mid)return query(rson,l,r);
		else return min(query(lson,l,mid),query(rson,mid+1,r));
	}
}seg;
int tot;
int inq[N];
int lst[N];
int main(){
	n=rd();
	rep(i,1,n)a[i]=b[i]=rd();
	sort(b+1,b+n+1);
	rep(i,1,n)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	seg.build(all);
	rep(i,1,n){
		int tmp;
		if(a[i]==1) tmp=inf;
		else tmp=seg.query(all,1,a[i]-1);
		//cout<<tmp<<endl;
		if(tmp==inf) {
			tot++;
			inq[i]=tot;
			seg.updata(all,a[i],tot);
			lst[tot] = i;
		}
		else {
			tmp = lst[tmp];
			inq[i]=inq[tmp];
			seg.updata(all,a[tmp],inf);
			seg.updata(all,a[i],inq[i]);
			lst[inq[i]] = i;
		}
	}
	rep(i,1,n){
		V[inq[i]].pb(b[a[i]]);
	}
	rep(i,1,tot){
		rep(j,0,V[i].size()-1){
			printf("%d%c",V[i][j]," \n"[j==j_end]);
		}
	}
}
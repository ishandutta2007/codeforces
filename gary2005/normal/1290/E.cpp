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
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=150000+233; 
int n;
struct node{
	int mx1,mx2,cnt;
	node(){mx1=mx2=cnt=0;}
	node (int A,int B,int C){mx1=A,mx2=B,cnt=C;	}
	node operator + (node B){
		node A=*this;
		if(A.mx1==B.mx1){
			return node(A.mx1,max(A.mx2,B.mx2),A.cnt+B.cnt);
		}
		if(A.mx1<B.mx1){
			return node(B.mx1,max(A.mx1,B.mx2),B.cnt);
		}
		else{
			return node(A.mx1,max(A.mx2,B.mx1),A.cnt);
		}
	}
};
const int N=1<<18;
LL rest=0;
struct SGT_BEATS{
	node tree[N+N];
	int siz[N+N];
	SGT_BEATS(){
		memset(siz,0,sizeof(siz));
	}
	void add(int pos){
		while(pos<=n){
			siz[pos]++;
			pos+=pos&(-pos);
		}
	}
	int sum(int pos){
		int s=0;
		while(pos){
			s+=siz[pos];
			pos-=pos&(-pos);
		}
		return s;
	}
	void pu(int now){
		tree[now]=tree[now<<1]+tree[now<<1|1];
	}
	void pd(int now){
		if(now<N){
			check_min(tree[now<<1].mx1,tree[now].mx1);
			check_min(tree[now<<1|1].mx1,tree[now].mx1);
		}
	}
	void modify(int pos,int now=1,int l=1,int r=N+1){
		pd(now);
		if(l==r-1){
			tree[now]=node{n+1,0,1};
			return ;
		}
		int mid=(l+r)>>1;
		if(mid>pos) modify(pos,now<<1,l,mid);
		else modify(pos,now<<1|1,mid,r);
		pu(now);
	}
	void upd(int pos,int now=1,int l=1,int r=N+1){
		pd(now);
		if(l>=pos) return ;
		if(r<=pos){
			if(tree[now].mx1<=pos){
				return ;
			}
			if(tree[now].mx2<pos){
				rest-=1ll*tree[now].cnt*(sum(tree[now].mx1-1)-sum(pos-1));
				tree[now].mx1=pos;
				pd(now);
				return;
			}
		}
		int mid=(l+r)>>1;
		upd(pos,now<<1,l,mid);
		upd(pos,now<<1|1,mid,r);
		pu(now);
	}
}sgt1,sgt2;
int a[MAXN];
int pos[MAXN];
int main(){
	scanf("%d",&n);
	rb(i,1,n) a[i]=read(),pos[a[i]]=i;
	rb(i,1,n){
		sgt1.modify(pos[i]);
		sgt2.modify(n-pos[i]+1);
		sgt1.upd(pos[i]);
		sgt2.upd(n-pos[i]+1);
		sgt1.add(pos[i]);
		sgt2.add(n-pos[i]+1);
		rest+=i;
		printf("%lld\n",rest);
	}
	return 0;
}
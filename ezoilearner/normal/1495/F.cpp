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

int n,q;
#define Maxn 200010
#define V 12000010
int p[Maxn],a[Maxn],b[Maxn];
set<int> S;

struct Node{
	int ls,rs;ll sum;
}tree[V];
int root[Maxn],cnt=0;
void Insert(int &k,int x,int l,int r,int p,ll ad){
	k=++cnt;tree[k]=tree[x];tree[k].sum+=ad;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid)Insert(tree[k].ls,tree[x].ls,l,mid,p,ad);
	else Insert(tree[k].rs,tree[x].rs,mid+1,r,p,ad);
}
ll query(int k,int l,int r,int L,int R){
	if(l==L&&r==R)return tree[k].sum;
	int mid=(l+r)>>1;
	if(R<=mid)return query(tree[k].ls,l,mid,L,R);
	else if(mid<L)return query(tree[k].rs,mid+1,r,L,R);
	else return query(tree[k].ls,l,mid,L,mid)+query(tree[k].rs,mid+1,r,mid+1,R);
}

ll calc(int s,int t){
	return query(root[s],1,n+1,1,t);
}

int stk[Maxn],tp;
ll h[Maxn];
int main(){
	rd(n);rd(q);
	rep(i,1,n)rd(p[i]);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]);p[n+1]=n+1;
	stk[++tp]=n+1;
	per(i,n,1){
		Insert(root[i],root[i+1],1,n+1,i+1,a[i]);ll v=0;
		while(tp&&p[stk[tp]]<p[i]){
			v+=h[tp];tp--;
		}
		Insert(root[i],root[i],1,n+1,stk[tp],-a[i]);
		h[++tp]=min(v+a[i],(ll)b[i]);
		Insert(root[i],root[i],1,n+1,stk[tp-1],h[tp]-v);
		stk[tp]=i;
	}
	S.insert(1);S.insert(n+1);
	ll Ans=calc(1,n+1);
	int x;
	rep(i,1,q){
		rd(x);
		if(x!=1){
			set<int>::iterator it=S.find(x);
			if(it!=S.end()){
				it++;int nxt=(*it);it--;it--;int pre=(*it);
				Ans-=calc(pre,x);Ans-=calc(x,nxt);
				Ans+=calc(pre,nxt);
				S.erase(x);
			}else{
				it=S.lower_bound(x);int nxt=(*it);it--;int pre=(*it);
				Ans-=calc(pre,nxt);Ans+=calc(pre,x);Ans+=calc(x,nxt);
				S.insert(x);
			}
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
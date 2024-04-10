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
struct node{
	int mx1,mx2,cnt1;
	LL ret;
	node(){mx1=mx2=0,ret=cnt1=0;}
	node operator + (node ano){
		node ret;
		if(this->mx1==ano.mx1){
			ret.mx1=this->mx1,ret.cnt1=this->cnt1+ano.cnt1;
			ret.mx2=max(this->mx2,ano.mx2);
		}
		if(this->mx1<ano.mx1) ret.mx1=ano.mx1,ret.cnt1=ano.cnt1,ret.mx2=max(this->mx1,ano.mx2);
		if(this->mx1>ano.mx1) ret.mx1=this->mx1,ret.cnt1=this->cnt1,ret.mx2=max(this->mx2,ano.mx1);
		ret.ret=this->ret+ano.ret;
		return ret;
	}
};
const int N=1<<17;
struct sgtbts{
	node tree[N+N];
	void pd(int idx){
		if(idx<N){
			if(tree[idx<<1].mx1>tree[idx].mx1){
				tree[idx<<1].ret-=1ll*tree[idx<<1].cnt1*(tree[idx<<1].mx1-tree[idx].mx1);
				tree[idx<<1].mx1=tree[idx].mx1;
			}
			if(tree[idx<<1|1].mx1>tree[idx].mx1){
				tree[idx<<1|1].ret-=1ll*tree[idx<<1|1].cnt1*(tree[idx<<1|1].mx1-tree[idx].mx1);
				tree[idx<<1|1].mx1=tree[idx].mx1;
			}
		}
	}
	void chk_min(int a,int b,int val,int now=1,int l=1,int r=N+1){
		pd(now);
		if(r<=a||l>=b) return ;
		if(r<=b&&l>=a){
			if(val>=tree[now].mx1) return ;
			if(val>tree[now].mx2&&val<tree[now].mx1){
				tree[now].ret-=1ll*tree[now].cnt1*(tree[now].mx1-val);
				tree[now].mx1=val;
				return ;
			}
		}
		int mid=(l+r)>>1;
		chk_min(a,b,val,now<<1,l,mid);
		chk_min(a,b,val,now<<1|1,mid,r);
		tree[now]=tree[now<<1]+tree[now<<1|1];
	}
	LL querysum(int a,int b,int now=1,int l=1,int r=N+1){
		pd(now);
		if(r<=a||l>=b) return 0;
		if(r<=b&&l>=a) return tree[now].ret;
		int mid=(l+r)>>1;
		return querysum(a,b,now<<1,l,mid)+querysum(a,b,now<<1|1,mid,r);
	}
	void modify(int pos,int x){
		int now=1,l=1,r=N+1;
		while(now<N){
			pd(now);
			int mid=(l+r)>>1;
			if(mid<=pos){
				l=mid;
				now=now<<1|1;
			}
			else{
				r=mid;
				now=now<<1;
			}
		}
		tree[now].mx1=x;
		tree[now].cnt1=1;
		tree[now].ret=x;
		now>>=1;
		while(now){
			tree[now]=tree[now<<1]+tree[now<<1|1];
			now>>=1;
		}
	}
	void build(){
		rb(i,N,N+N-1) tree[i].mx1=INF,tree[i].cnt1=1,tree[i].ret=INF;
		rl(i,N-1,1) tree[i]=tree[i<<1]+tree[i<<1|1];
	}
}pos,neg,postmp,negtmp;
int cnt[N],q;
set<int> nopos,noneg;
int main(){
	scanf("%d",&q);
	postmp.build();
	negtmp.build();
	rb(i,1,100000) nopos.insert(i),noneg.insert(i);
	rb(i,1,q){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			if(k<0){
				k=-k;
				neg.chk_min(l,r,k);
				negtmp.chk_min(l,r,k);
				auto ite=noneg.lower_bound(l);
				while(ite!=noneg.end()&&*ite<r){
					cnt[*ite]++;
					if(cnt[*ite]==2){
						pos.modify(*ite,postmp.querysum(*ite,*ite+1));
						neg.modify(*ite,negtmp.querysum(*ite,*ite+1));
					}
					ite=noneg.erase(ite);
				}
			}
			else{
				pos.chk_min(l,r,k);
				postmp.chk_min(l,r,k);
				auto ite=nopos.lower_bound(l);
				while(ite!=nopos.end()&&*ite<r){
					cnt[*ite]++;
					if(cnt[*ite]==2){
						pos.modify(*ite,postmp.querysum(*ite,*ite+1));
						neg.modify(*ite,negtmp.querysum(*ite,*ite+1));
					}
					ite=nopos.erase(ite);
				}
			}
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",pos.querysum(l,r)+neg.querysum(l,r));
		}
	}
	return 0;
}
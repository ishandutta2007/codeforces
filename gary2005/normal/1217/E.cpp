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
const int N=1<<18;
struct SEGMENTTREE{
	mp tree[N+N];//
	SEGMENTTREE(){
		rb(i,1,N+N-1)
			tree[i]=II(INF,INF);
	}
	mp merge(mp A,mp B){
		if(A>B) swap(A,B);
		if(B.FIR<A.SEC) A.SEC=B.FIR;
		return A; 
	} 
	void modify(int index,int val){
		index+=N-1;
		tree[index]=II(val,INF);
		index>>=1; 
		while(index){
			tree[index]=merge(tree[index<<1],tree[index<<1|1]);
			index>>=1;
		}
	} 
	mp query(int a,int b,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b){
			return II(INF,INF);
		}
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return merge(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
}sgt[10];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		int tmp=ai;
		rb(j,1,9){
			if(tmp%10){
				sgt[j].modify(i,ai);
			}
			tmp/=10;
		}
	}
	rb(Q,1,m){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			int i,x;
			scanf("%d%d",&i,&x);
			int tmp=x;
			rb(j,1,9){
				sgt[j].modify(i,INF);
			}
			rb(j,1,9){
				if(tmp%10){
					sgt[j].modify(i,x);
				}
				tmp/=10;
			}
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			int rest=2e9;
			rb(j,1,9){
				mp q=sgt[j].query(l,r+1);
				if(q.SEC<INF)
					check_min(rest,q.FIR+q.SEC);
			}
			if(rest==2e9){
				rest=-1;
			}
			printf("%d\n",rest);
		}
	}
	return 0;
}
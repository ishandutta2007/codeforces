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
const int MAXN=1e5+20;
pair<mp,int>  e[MAXN*3];
struct operation{
	int index,farnk;
	operation(){}
	operation(int a,int b){
		index=a;farnk=b;
	}
};
struct DSU{
	vector<operation> vec;
	int fa[MAXN],siz[MAXN],rnk[MAXN],cnt;
	DSU(){}
	DSU(int n){
		cnt=n;
		rb(i,1,n) fa[i]=i,siz[i]=1,rnk[i]=1;
	}
	int root(int v){
		return (fa[v]==v? v:root(fa[v]));
	}
	void merge(int u,int v){
		u=root(u);
		v=root(v);
		if(u==v){
			vec.PB(operation(0,0));
			return;
		}
		if(rnk[u]>rnk[v]) swap(u,v);
		fa[u]=v;
		cnt-=siz[u]%2;
		cnt-=siz[v]%2;
		vec.PB(operation(u,rnk[v]));
		siz[v]+=siz[u];
		if(rnk[u]==rnk[v]) rnk[v]++;
		cnt+=siz[v]%2;
	}
	void undo(){
		operation now=vec.back();
		vec.POB();
		if(now.farnk==0) return ;
		int u,farnk,v;
		u=now.index,farnk=now.farnk;
		v=fa[u];
		fa[u]=u;
		cnt-=siz[v]%2;
		siz[v]-=siz[u];
		rnk[v]=farnk;
		cnt+=siz[v]%2;
		cnt+=siz[u]%2;
	}
}dsu;
int n,m,rest[300000+20];
int order[300000+20];
bool cmp(int A,int B){
	return e[A].SEC<e[B].SEC;	
}
void solve(int l,int r,int L,int R){
	if(l>r) return ;
	int mid=(l+r)>>1;
	int cnt1=0;
	rb(i,l,mid){
		if(e[i].SEC<=e[order[L]].SEC){
			++cnt1;
			dsu.merge(e[i].FIR.FIR,e[i].FIR.SEC);
		}
	}
	int now=L;
	int cnt2=0;
	while(dsu.cnt){
		now++;
		if(now>R) break; 
		if(order[now]<=mid){
			cnt2++;
			dsu.merge(e[order[now]].FIR.FIR,e[order[now]].FIR.SEC);
		}		
	}
	while(now<R&&e[order[now+1]].SEC==e[order[now]].SEC){
		++now;
		if(order[now]<=mid){
			cnt2++;
			dsu.merge(e[order[now]].FIR.FIR,e[order[now]].FIR.SEC);
		}	
	}
	rb(i,1,cnt1+cnt2) dsu.undo();
	if(now>R){
		rb(i,l,mid){
			rest[i]=-1;
		}
		now=R;
	}
	else{
		rest[mid]=now;
		cnt1=0;
		rb(i,L,now){
			if(order[i]<l){
				cnt1++;
				dsu.merge(e[order[i]].FIR.FIR,e[order[i]].FIR.SEC);
			}
		}
		solve(l,mid-1,now,R);
		rb(i,1,cnt1) dsu.undo();
	}
	cnt1=0;
	rb(i,l,mid){
		if(e[i].SEC<=e[order[L]].SEC){
			++cnt1;
			dsu.merge(e[i].FIR.FIR,e[i].FIR.SEC);
		}
	}
	solve(mid+1,r,L,now);
	rb(i,1,cnt1) dsu.undo();
} 
int main(){
	scanf("%d%d",&n,&m);
	dsu=DSU(n);
	rb(i,1,m){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		e[i]=II(II(u,v),c);
	}	
	rb(i,1,m) order[i]=i;
	sort(order+1,order+1+m,cmp);
	solve(1,m,1,m);
	rb(i,1,m){
		printf("%d\n",rest[i]>=1? e[order[rest[i]]].SEC:-1);
	}
	return 0;
}
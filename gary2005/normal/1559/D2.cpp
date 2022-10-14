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
const int MAXN=1e5+1;
typedef bitset<MAXN> BIS;
vector<BIS> BS;
const int BL=333;
struct dsu{
	int big[MAXN];
	int fa[MAXN];
	int siz[MAXN];
	vector<int> con[MAXN];
	dsu(){
		fill(siz,siz+MAXN,1);
		fill(big,big+MAXN,-1);
		rep(i,MAXN) con[i].clear(),con[i].PB(i);
		rep(i,MAXN) fa[i]=i;
	}
	int root(int x){
		if(fa[x]==x) return x;
		return fa[x]=root(fa[x]);
	}
	void merge(int u,int v){
		u=root(u);
		v=root(v);
		if(siz[u]>siz[v]) swap(u,v);
		if(big[u]!=-1){
			BS[big[v]]&=BS[big[u]];
		}
		else{
			if(big[v]!=-1){
				for(auto it:con[u]){
					BS[big[v]].flip(it);
				}
			}
			else{
				for(auto it:con[u]){
					con[v].PB(it);
				}
				if(con[v].size()>BL){
					big[v]=BS.size();
					BIS tmp;
					tmp.flip();
					tmp.flip(0);
					for(auto it:con[v]){
						tmp.flip(it);
					}
					BS.PB(tmp);
				}
			}
		}
		siz[v]+=siz[u];
		fa[u]=v;
	}
}A,B;
int main(){
	int n,m1,m2;
	cin>>n>>m1>>m2;
	rb(i,1,m1){
		int u,v;
		scanf("%d%d",&u,&v);
		A.merge(u,v);
	}
	rb(i,1,m2){
		int u,v;
		scanf("%d%d",&u,&v);
		B.merge(u,v);
	}
	vector<mp> ans;
	rb(i,1,n){
		while(true){
			bool ok=0;
			int ia=A.root(i),ib=B.root(i);
			if(A.big[ia]!=-1&&B.big[ib]!=-1){
				BIS z=BS[A.big[ia]]&BS[B.big[ib]];
				int x=z._Find_first();
				if(x<=n){
					ok=1;
					A.merge(i,x);
					B.merge(i,x);
					ans.PB(II(i,x));
				}
			}
			else if(A.big[ia]==-1&&B.big[ib]!=-1){
				BIS & z=BS[B.big[ib]];
				int x=z._Find_first();
				while(x<=n&&A.root(i)==A.root(x)){
					x=z._Find_next(x);
				}
				if(x<=n){
					ok=1;
					A.merge(i,x);
					B.merge(i,x);
					ans.PB(II(i,x));
				}
			}
			else if(A.big[ia]!=-1&&B.big[ib]==-1){
				BIS & z=BS[A.big[ia]];
				int x=z._Find_first();
				while(x<=n&&B.root(i)==B.root(x)){
					x=z._Find_next(x);
				}
				if(x<=n){
					ok=1;
					A.merge(i,x);
					B.merge(i,x);
					ans.PB(II(i,x));
				}
			}
			else if(A.big[ia]==-1&&B.big[ib]==-1){
				rb(x,1,n){
					if(A.root(i)!=A.root(x)&&B.root(i)!=B.root(x)){
						ok=1;
						A.merge(i,x);
						B.merge(i,x);
						ans.PB(II(i,x));
						break;
					}
				}
			}
			if(!ok) break;
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans){
		cout<<it.FIR<<" "<<it.SEC<<endl;
	}
	return 0;
}
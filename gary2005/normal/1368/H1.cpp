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
const int MAXN=1e5+23;
const int N=1<<17;
int n,m,q;
bool col[4][MAXN];//L/R/U/D
bool get(){char c;cin>>c;return c=='B';}
int ans[MAXN];
pair<char,mp> ope[MAXN];
map<char,char> Map;
struct SEGMENTTREE1{
	int tree[N+N][2];
	bool tag[N+N];
	void build_tree(bool * a){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		rb(i,1,m){
			tree[N+i-1][a[i]]=1;
		}
		rl(i,N-1,1) tree[i][0]=tree[i<<1][0]+tree[i<<1|1][0],tree[i][1]=tree[i<<1][1]+tree[i<<1|1][1];
	}
	void pd(int now){
		if(tag[now]){
			tag[now]=0;
			swap(tree[now][0],tree[now][1]);
			if(now<N) tag[now<<1]^=1,tag[now<<1|1]^=1;
		}
	}
	void pu(int now){
		tree[now][0]=tree[now<<1][0]+tree[now<<1|1][0];
		tree[now][1]=tree[now<<1][1]+tree[now<<1|1][1]; 
	}
	void flip(int a,int b,int now=1,int l=1,int r=N+1){
		pd(now);
		if(r<=a||l>=b) return ;
		if(r<=b&&l>=a){
			tag[now]^=1;
			return pd(now);
		}
		int mid=(l+r)>>1;
		flip(a,b,now<<1,l,mid);
		flip(a,b,now<<1|1,mid,r);
		pu(now);
	}
}sgt1,sgt2;
struct Matrix{//Min+  
	int a[2][2];
	Matrix(){memset(a,63,sizeof(a));}
	Matrix(int A,int B,int C,int D){a[0][0]=A,a[0][1]=B,a[1][0]=C,a[1][1]=D;}
	Matrix operator * (const Matrix oth){
		Matrix ret;
		rep(i,2)
			rep(j,2)
				rep(k,2)
					check_min(ret.a[i][j],a[i][k]+oth.a[k][j]);
		return ret;
	}
};
Matrix I(0,INF,INF,0);
struct Vec{
	int a[2];
	Vec(){memset(a,63,sizeof(a));}
	Vec(int A,int B){a[0]=A,a[1]=B;}
	Vec operator * (const Matrix oth){
		Vec ret;
		rep(j,2)
			rep(i,2) check_min(ret.a[j],a[i]+oth.a[i][j]);
		return ret;
	}
};
Matrix mat(int A,int B){
	return Matrix(A+B,m+A+B,m+(!A)+(!B),(!A)+(!B));
}
struct SEGMENTTREE2{
	Matrix tree[N+N][2][2];
	bool tag[N+N][2];
	void build_tree(bool * left,bool * right){
		memset(tag,0,sizeof(tag));
		rep(i,N+N) rep(j,2) rep(k,2) tree[i][j][k]=I;
		rb(i,1,n)
			rep(j,2)
				rep(k,2) tree[N-1+i][j][k]=mat(j^left[i],k^right[i]);
		rl(i,N-1,1) rep(j,2) rep(k,2) tree[i][j][k]=tree[i<<1][j][k]*tree[i<<1|1][j][k];
	}
	void pd(int now){
		if(tag[now][1]){
			tag[now][1]=0;
			swap(tree[now][0][0],tree[now][0][1]);
			swap(tree[now][1][0],tree[now][1][1]);
			if(now<N) tag[now<<1][1]^=1,tag[now<<1|1][1]^=1;
		}
		if(tag[now][0]){
			tag[now][0]=0;
			swap(tree[now][1][0],tree[now][0][0]);
			swap(tree[now][1][1],tree[now][0][1]);
			if(now<N) tag[now<<1][0]^=1,tag[now<<1|1][0]^=1;	
		}
	}
	void pu(int now){
		rep(i,2) rep(j,2) tree[now][i][j]=tree[now<<1][i][j]*tree[now<<1|1][i][j]; 
	}
	void flip(int a,int b,bool num,int now=1,int l=1,int r=N+1){
		pd(now);
		if(r<=a||l>=b) return ;
		if(r<=b&&l>=a){
			tag[now][num]^=1;
			return pd(now);
		}
		int mid=(l+r)>>1;
		flip(a,b,num,now<<1,l,mid);
		flip(a,b,num,now<<1|1,mid,r);
		pu(now);
	}
}sgt3;
void solve(){
	sgt1.build_tree(col[2]);
	sgt2.build_tree(col[3]);
	sgt3.build_tree(col[0],col[1]);
	rb(i,0,q){
		if(i){
			if(ope[i].FIR=='U'){
				sgt1.flip(ope[i].second.FIR,ope[i].second.SEC+1);
			}
			if(ope[i].FIR=='D'){
				sgt2.flip(ope[i].SEC.FIR,ope[i].SEC.SEC+1);
			}
			if(ope[i].FIR=='L'){
				sgt3.flip(ope[i].SEC.FIR,ope[i].SEC.SEC+1,0);
			}
			if(ope[i].FIR=='R'){
				sgt3.flip(ope[i].SEC.FIR,ope[i].SEC.SEC+1,1);
			}
		}
		Vec rest(sgt1.tree[1][1],sgt1.tree[1][0]);
		rest=rest*sgt3.tree[1][0][0];
		rest.a[0]+=sgt2.tree[1][1];
		rest.a[1]+=sgt2.tree[1][0];
		check_min(ans[i],min(rest.a[0],rest.a[1]));
	}
}
int main(){
	Map['U']='L';
	Map['L']='U';
	Map['D']='R';
	Map['R']='D';
	scanf("%d%d%d",&n,&m,&q);
	rep(j,2) rb(i,1,n) col[j][i]=get();
	rb(j,2,3) rb(i,1,m) col[j][i]=get();
	memset(ans,63,sizeof(ans));
	rb(i,1,q){
		cin>>ope[i].first;
		scanf("%d%d",&ope[i].second.FIR,&ope[i].SEC.SEC);
	}
	solve();
	swap(n,m);
	rb(i,1,q){
		ope[i].first=Map[ope[i].FIR];
	}
	swap(col[0],col[2]);
	swap(col[1],col[3]);
	solve();
	rb(i,0,q) printf("%d\n",ans[i]);
	return 0;
}
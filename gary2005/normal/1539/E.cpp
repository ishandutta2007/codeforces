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
const int MAXN=1e5+5;
int n,m,a[MAXN],p[MAXN][2],id[MAXN],rnk[MAXN],ans[MAXN],seg[2][MAXN][2];
const int N=1<<17;
struct SGT{
	int tree[N+N];
	SGT(){memset(tree,0,sizeof(tree));}
	void push_down(int now){
		if(tree[now]==0){
			if(now<N) tree[now<<1]=tree[now<<1|1]=0;
		}
	}
	void set(int pos,int now=1,int l=1,int r=N+1){
		push_down(now);
		if(l>pos||r<=pos) return ;
		if(l==r-1){
			tree[now]=l;
			return ;
		}
		int mid=(l+r)>>1;
		set(pos,now<<1,l,mid);
		set(pos,now<<1|1,mid,r);
		tree[now]=max(tree[now<<1],tree[now<<1|1]);
	}
	void Rm(int a,int b,int now=1,int l=1,int r=N+1){
		push_down(now);
		if(r<=a||l>=b) return ;
		if(r<=b&&l>=a){
			tree[now]=0;
			push_down(now);
			return ;
		}
		int mid=(l+r)>>1;
		Rm(a,b,now<<1,l,mid);
		Rm(a,b,now<<1|1,mid,r);
		tree[now]=max(tree[now<<1],tree[now<<1|1]);
	}
};
SGT dp[2];
bool cmp(int A,int B){
	return a[A]<a[B];
}
int k[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		a[i+1]=read();seg[0][i+1][0]=read(),seg[0][i+1][1]=read();seg[1][i+1][0]=read(),seg[1][i+1][1]=read();
		k[i+1]=a[i+1];
	}
	n++;
	rb(i,1,n) p[i][0]=p[i][1]=-1;
	rb(i,1,n) id[i]=i;
	sort(id+1,id+1+n,cmp);
	sort(a+1,a+1+n);
	rb(i,1,n) rnk[id[i]]=i;
	dp[0].set(rnk[1]);
	dp[1].set(rnk[1]);
	rb(i,1,n){
		if(i!=1){
			rep(flag,2){
				if(!(k[i]<=seg[flag][i][1]&&k[i]>=seg[flag][i][0])){
					dp[flag].Rm(1,N+1);
				}
				else{
					dp[flag].Rm(1,lower_bound(a+1,a+1+n,seg[flag^1][i][0])-a);
					dp[flag].Rm(upper_bound(a+1,a+1+n,seg[flag^1][i][1])-a,N+1);
				}
			}
		}
		bool A,B;
		A=B=0;
		if(dp[0].tree[1]){
			A=1;
			p[i][0]=id[dp[0].tree[1]];
		}
		if(dp[1].tree[1]){
			B=1;
			p[i][1]=id[dp[1].tree[1]];
		}
//		cout<<A<<" "<<B<<endl;
		if(A) dp[1].set(rnk[i]);
		if(B) dp[0].set(rnk[i]);
	}
	if(p[n][0]==-1&&p[n][1]==-1){
		puts("No");
	}
	else{
		puts("Yes");
		vector<mp> v;
		int now=n;
		bool tmp;
		if(p[n][0]!=-1) tmp=0;
		else tmp=1;
		while(true){
			v.PB(II(now,tmp));
			if(now==1) break;
			assert(p[now][tmp]!=-1);
			now=p[now][tmp];
			tmp^=1;
		}
		v.PB(II(0,tmp^1));
		int P=n;
		for(auto it:v){
			rb(i,it.FIR+1,P){
				ans[i]=it.SEC^1;
			}
			P=it.FIR;
		}
		rb(i,2,n){
			printf("%d ",ans[i]);
		}
		puts("");
	}
	return 0;
}
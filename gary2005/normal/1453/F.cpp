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
const int N=1<<12;
struct segment{
	int tree[N+N];
	segment(){
		memset(tree,63,sizeof(tree)); 
	}
	void modify(int pos,int val){
		pos+=N-1;
		if(val==INF+233) tree[pos]=INF;
		else check_min(tree[pos],val);
		pos>>=1;
		while(pos){
			tree[pos]=min(tree[pos<<1],tree[pos<<1|1]);
			pos>>=1;
		}
	}
	int query(int a,int b,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b){
			return INF;
		}
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
}sgt[N];
int bit[N+10]={0};
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=N){
		bit[i]+=x;
		i+=i&(-i);	
	}
} 
int n,a[N];
int dp[N][N],k[N][N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rb(i,1,n){
			rb(j,1,n){
				sgt[i].modify(j,INF+233);
			}
		}
		rb(i,1,n) scanf("%d",&a[i]);
		rb(i,1,n){
			rb(j,i+1,n+1){
				k[i][j]=sum(j-1)-sum(i-1);
			}
			add(a[i]+i);
		}
		rb(i,1,n){
			add(a[i]+i,-1);
		}
		rb(i,1,n){
			rb(j,i+1,n+1){
				dp[i][j]=INF;
				if(i==1){
					dp[i][j]=0;
				}
				else{
					if(i!=n&&!a[i]) break;
					if(k[i][j]==0) continue;
					check_min(dp[i][j],sgt[i].query(i,j)+k[i][j]-1);
				}
				sgt[j].modify(i+a[i],dp[i][j]);
			}
		}
		cout<<dp[n][n+1]<<endl;
	} 
	return 0;
}
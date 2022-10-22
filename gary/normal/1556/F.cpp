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
const int MAXN=14;
int n,a[MAXN],mat[MAXN][MAXN],lg[1<<MAXN];
const int MOD=1e9+7;
int quick(int A,int B){
    if(B==0) return 1;
    int tmp=quick(A,B>>1);
    tmp=1ll*tmp*tmp%MOD;
    if(B&1) tmp=1ll*tmp*A%MOD;
    return tmp;
}
int inv(int A){
    return quick(A,MOD-2);
}
const int MODD=(1<<22)-1;
struct HASH_TABLE{
	int tp[MODD];
	vector<int> nex,val;
	vector<mp> is;
	HASH_TABLE(){
		fill(tp,tp+MODD,-1);
	}
	void clear(){
		for(auto it:is){
			tp[((it.FIR<<8)^it.SEC)&MODD]=-1;
		}
		is.clear();
		nex.clear();
		val.clear();
	}
	void insert(mp p,int v){
		int se=(p.FIR<<8)^p.SEC;
		se&=MODD;
		nex.PB(tp[se]);
		tp[se]=nex.size()-1;
		val.PB(v);
		is.PB(p);
	}
	int query(mp p){
		int se=(p.FIR<<8)^p.SEC;
		se&=MODD;
		for(int now=tp[se];now!=-1;now=nex[now]){
			if(is[now]==p) return val[now];
		}
		return -1;
	}
}mem;
int dp[MAXN][1<<MAXN];
void add(int & A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int main(){
    scanf("%d",&n);
    rep(i,n) scanf("%d",&a[i]);
    rep(i,n) rep(j,n) mat[i][j]=1ll*a[i]*inv(a[i]+a[j])%MOD;
    rep(i,n) lg[1<<i]=i;
    rep(mask,1<<n){
        mem.insert(II(mask,0),1);
    }
    rep(mask1,1<<n){
        for(int mask2=mask1&(mask1-1);mask2;mask2=(mask2-1)&mask1){
            int A,B;
            A=mask1^mask2;
            B=mask2;
            int ret=mem.query(II(A,B^(B&-B)));
            int z=lg[B&-B];
            rep(i,n){
                if((A>>i)&1){
                    ret=1ll*ret*mat[i][z]%MOD;
                }
            }
            mem.insert(II(A,B),ret);
        }
    }
    rep(i,n) dp[i][1<<i]=1;
    rep(mask,1<<n){
        if(__builtin_popcount(mask)>1){
            rep(j,n) if((mask>>j)&1) dp[j][mask]=1;
            for(int sub=mask&(mask-1);sub;sub=(sub-1)&mask){
                int A,B;
                A=sub;
                B=mask^sub;
                int tra=mem.query(II(B,A));
                rep(j,n) if((A>>j)&1){
                    add(dp[j][mask],MOD-1ll*dp[j][sub]*tra%MOD);
                }
            }
        }
    }
    int answer=0;
    rep(i,n) add(answer,dp[i][(1<<n)-1]);
    cout<<answer<<endl;
    return 0;
}
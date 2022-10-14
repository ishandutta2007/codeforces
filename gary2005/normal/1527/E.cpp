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
int n,k;
LL dp[35000+20][101];
int pre[35000+20],a[35000+20],p[35000+20];
const int N=1<<16;
LL add[N+N];
LL mini[N+N];
void modify(int A,LL B){
	A+=N-1;
	mini[A]=B;
	A>>=1;
	while(A){
		mini[A]=min(mini[A<<1],mini[A<<1|1]);
		A>>=1;
	}
}
LL query(int R,int now=1,int l=1,int r=N+1){
	mini[now]+=add[now];
	if(now<N){
		add[now<<1]+=add[now];
		add[now<<1|1]+=add[now];
	}
	add[now]=0;
	if(r<=R+1){
		return mini[now];
	}
	if(l>R) return 1e18;
	int mid=(l+r)>>1;
	return min(query(R,now<<1,l,mid),query(R,now<<1|1,mid,r));
}
void modify(int R,int val,int now=1,int l=1,int r=N+1){
	mini[now]+=add[now];
	if(now<N){
		add[now<<1]+=add[now];
		add[now<<1|1]+=add[now];
	}
	add[now]=0;
	if(r<=R+1){
		mini[now]+=val;
		if(now<N){
			add[now<<1]+=val;
			add[now<<1|1]+=val;
		}
		return ;
	}
	if(l>R) return ;
	int mid=(l+r)>>1;
	modify(R,val,now<<1,l,mid);
	modify(R,val,now<<1|1,mid,r);
	mini[now]=min(mini[now<<1],mini[now<<1|1]);
}
int main(){
	scanf("%d%d",&n,&k);
	rb(i,1,n) scanf("%d",&a[i]);
	LL tmp=0;
	rb(i,1,n){
		if(!pre[a[i]]);
		else{
			tmp+=i-pre[a[i]];
		}
		p[i]=pre[a[i]];
		pre[a[i]]=i;
		dp[i][1]=tmp;
	}
	rb(j,2,k){
		memset(add,0,sizeof(add));
		memset(mini,0,sizeof(mini));
		rb(i,1,j-1) modify(i,dp[i][j-1]);
		rb(i,1,j-1) dp[i][j]=1e18;
		rb(i,j,n){
			if(p[i]-1){
				modify(p[i]-1,i-p[i]);
			}
			dp[i][j]=query(i-1);
			modify(i,dp[i][j-1]);
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}
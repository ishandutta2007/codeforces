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
const int N=1<<19;
const int MAXN=3e5+233; 
int n;
int h[MAXN];
int b[MAXN];
int is[MAXN];
LL dp[MAXN];
LL tree[N+N];
LL query(int a,int b,int now=1,int l=1,int r=N+1){
	if(a==b) return -1e18;
	if(r<=a||l>=b) return -1e18;
	if(r<=b&&l>=a){
		return tree[now];
	}
	int mid=(l+r)>>1;
	return max(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
}
void modify(int pos,LL val){
	pos+=N-1;
	check_max(tree[pos],val);
	pos>>=1;
	while(pos){
		tree[pos]=max(tree[pos<<1],tree[pos<<1|1]);
		pos>>=1;
	}
}
int main(){
	memset(tree,-127,sizeof(tree));
	stack<pair<mp,pair<int,LL> > > sta;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&h[i]);
	}
	rb(i,1,n){
		scanf("%d",&b[i]);
	}
	rb(i,1,n) is[h[i]]=b[i];
	int mn=1;
	rb(i,1,n){
		int l=i;
		while(!sta.empty()&&sta.top().SEC.FIR>h[i]) l=sta.top().FIR.FIR,sta.pop();
		if(h[i]<h[mn]) mn=i;
		dp[i]=b[mn];
		if(!sta.empty()){
			check_max(dp[i],sta.top().SEC.SEC);
		}
		if(i!=1){
			check_max(dp[i],query(max(1,l-1),i)+b[i]);
//			cout<<query(max(1,l-1),i)<<endl;
		}
		modify(i,dp[i]);
		if(l==1){
			sta.push(II(II(l,i),II(h[i],(i==1? -1e18:query(1,i)+b[i]))));
		}
		else{
			sta.push(II(II(l,i),II(h[i],max(max(sta.top().SEC.SEC,dp[l-1]+b[i]),query(l,i)+b[i]))));
		}
//		cout<<i<<' '<<dp[i]<<endl;
	}
	cout<<dp[n]<<endl;
	return 0;
}
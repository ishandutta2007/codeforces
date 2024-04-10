/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int N=1<<19;
struct SEG_TREE{
	int tree[N+N];
	multiset<int> s[N+1];
	SEG_TREE (){
		memset(tree,63,sizeof(tree));
		rb(i,1,N)
			s[i].insert(INF);
	}
	void modify(int index,int x){
		index+=N-1;
		tree[index]=x;
		index>>=1;
		while(index){
			tree[index]=min(tree[index<<1],tree[index<<1|1]);
			index>>=1;
		}
	}
	void add(int index,int x){
		s[index].insert(x);
		modify(index,*(s[index].begin()));
	}
	void del(int index,int x){
		s[index].erase(s[index].lower_bound(x));
		modify(index,*(s[index].begin()));
	}
	int query(int a,int b,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b)
		{
			return INF;
		}
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
};
map<int,int> M;
int cnt=0,n,k,a[500000+20],id[500000+20],b[500000+20],dp[500000+20];
int main(){
	SEG_TREE sgt=SEG_TREE();
	scanf("%d%d",&n,&k);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	a[++n]=INF;
	rb(i,1,n)
		M[a[i]-i]=1;
	for(auto ite=M.begin();ite!=M.end();ite++){
		ite->SEC=++cnt;
	}
//	cout<<sgt.tree[1]<<endl;
	rb(i,1,n){
		id[i]=M[a[i]-i];
	}
	rb(i,1,k){
		int bi;
		scanf("%d",&bi);
		b[bi]=1;
	}
	int las=1;
	bool ok=1;
	rb(i,1,n){
		dp[i]=sgt.query(1,id[i]+1)+i-1;
		if(ok){
			check_min(dp[i],i-1);
		}
		sgt.add(id[i],dp[i]-i);
		if(b[i]){
			rb(j,las,i-1){
				sgt.del(id[j],dp[j]-j);
			}
			ok=0;
			las=i;
		}
	}
	if(dp[n]>=INF) dp[n]=-1;
	cout<<dp[n]<<endl;
	return 0;
}
/** 
  * dp[i]i dp[i]=min{dp[j]+(i-j)} (i-j<=a[i]-a[j],a[j]-j<=a[i]-i) 
  * 
  *
  *
  **/
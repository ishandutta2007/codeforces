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
const int MAXN=2e5+3;
int a[MAXN],n;
bool cmp(mp A,mp B){
	return A>B;
}
const int N=1<<18;
struct Segment{
	LL tree[N+N];
	LL tag[N+N];
	Segment(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
	}
	void pushdown(int now){
		tree[now]+=tag[now];
		if(now<N){
			tag[now<<1]+=tag[now];
			tag[now<<1|1]+=tag[now];
		}
		tag[now]=0;
	}
	void add(int a,int b,LL val,int now=1,int l=1,int r=N+1){
		pushdown(now);
		if(r<=a||l>=b) return ;
		if(r<=b&&l>=a){
			tag[now]+=val;
			pushdown(now);
			return ;
		}
		int mid=(l+r)>>1;
		add(a,b,val,now<<1,l,mid);
		add(a,b,val,now<<1|1,mid,r);
		tree[now]=min(tree[now<<1],tree[now<<1|1]);
	}
	LL query(int a,int b,int now=1,int l=1,int r=N+1){
		pushdown(now);
		if(r<=a||l>=b) return 1e18;
		if(r<=b&&l>=a) return tree[now];
		int mid=(l+r)>>1;
		return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
	void clear(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
	}
}sgtmin;
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	int cnt=0;
	vector<mp> v;
	rb(i,1,n) if(a[i]<0) v.PB(II(a[i],i));else ++cnt,sgtmin.add(i,n+1,a[i]);
	sort(ALL(v),cmp);
	int ans=cnt;
	for(auto it:v){
		if(sgtmin.query(it.SEC,n+1)+it.FIR>=0){
			sgtmin.add(it.SEC,n+1,it.FIR);
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
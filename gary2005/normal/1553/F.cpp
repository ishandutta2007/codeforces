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
const int MAXN=3e5+1;
int n,a[MAXN];
LL ans[MAXN];
struct BIT{
	LL bit[MAXN];
	void clear(){
		memset(bit,0,sizeof(bit));
	}
	BIT(){
		clear();
	}
	void add(int pos,int val){
		while(pos<=3e5){
			bit[pos]+=val;
			pos+=pos&-pos;
		}
	}
	LL sum(int pos){
		LL s=0;
		while(pos){
			s+=bit[pos];
			pos-=pos&-pos;
		}
		return s;
	}
	LL query(int l,int r){
		return sum(r)-sum(l-1);
	}
}val,cnt;
vector<int> Tmp[MAXN];
LL pre[MAXN];
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	rb(i,1,n){
		rb(j,0,300000/a[i]){
			int l,r;
			l=a[i]*j;
			r=a[i]*j+a[i]-1;
			check_max(l,1);
			check_min(r,300000);
			if(l<=r){
				ans[i]+=val.query(l,r)-1ll*a[i]*j*cnt.query(l,r);
			}
		}
		val.add(a[i],a[i]);
		cnt.add(a[i],1);
	}
	val.clear();
	rb(i,1,n) Tmp[a[i]].PB(i);
	rb(i,1,300000){
		reverse(ALL(Tmp[i]));
		for(auto it:Tmp[i]){
			if(it>0){
				val.add(it,a[it]);
				pre[it]=1ll*it*a[it]-val.sum(it);
			}
			else{
				val.add(-it,a[-it]);
			}
			if(i+a[abs(it)]<=300000)
			Tmp[i+a[abs(it)]].PB(-abs(it));
		}
	}
	rb(i,1,n){
		pre[i]+=pre[i-1];
		ans[i]+=ans[i-1];
		printf("%lld ",ans[i]+pre[i]);
	}
	puts("");
	return 0;
}
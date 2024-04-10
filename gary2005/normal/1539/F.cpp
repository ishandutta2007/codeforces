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
struct node{
	double sum;
	double pre,suf;
	node(){sum=pre=suf=0;}
	node operator + (node ano){
		node ret;
		ret.sum=ano.sum+this->sum;
		ret.pre=max(this->pre,this->sum+ano.pre);
		ret.suf=max(ano.suf,ano.sum+this->suf);
		return ret;
	}
};
int n;
const int N=1<<18;
int a[200000+20];
node sgt[N+N];
void clr(){
	rep(i,N+N) sgt[i]=node();
}
void add(int pos,double val){
	pos+=N-1;
	sgt[pos].sum+=val;
	sgt[pos].pre=sgt[pos].suf=max(0.0,sgt[pos].sum);
	pos>>=1;
	while(pos){
		sgt[pos]=sgt[pos<<1]+sgt[pos<<1|1];
		pos>>=1;
	}
}
node query(int a,int b,int now=1,int l=1,int r=N+1){
	if(r<=b&&l>=a) return sgt[now];
	int mid=(l+r)>>1;
	if(mid>=b) return query(a,b,now<<1,l,mid);
	if(mid<=a) return query(a,b,now<<1|1,mid,r);
	return query(a,b,now<<1,l,mid)+query(a,b,now<<1|1,mid,r);
}
vector<int> pos[N];
int ans[N];
void solve1(){
	clr();
	rb(i,1,n) add(i,0.5);
	rb(i,1,n){
		for(auto it:pos[i]){
			int tmp=llround(floor(query(it+1,N+1).pre+query(1,it+1).suf));
			check_max(ans[it],tmp);
		}
		for(auto it:pos[i]){
			add(it,-1);
		}
	}
}
void solve2(){
	clr();
	rb(i,1,n) add(i,0.5);
	rl(i,n,1){
		for(auto it:pos[i]){
			int tmp=llround(ceil(query(it+1,N+1).pre+query(1,it+1).suf));
			check_max(ans[it],tmp-1);
		}
		for(auto it:pos[i]){
			add(it,-1);
		}
	}
}
int main(){
	scanf("%d",&n);rb(i,1,n) scanf("%d",&a[i]),pos[a[i]].PB(i);
	solve1();
	solve2();
	rb(i,1,n) printf("%d ",ans[i]);
	puts("");
	return 0;
}
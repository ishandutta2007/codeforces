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
const int N=1<<16;
int n,m,l[N<<1],r[N<<1];
set<mp> sgt[N+N];
vector<int> seg[N];
int query(int a,int b,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b) return INF;
	if(r<=b&&l>=a){
		auto ite=sgt[now].upper_bound(II(b,0));
		if(ite==sgt[now].begin()) return INF;
		return prev(ite)->SEC;
	}
	int mid=(l+r)>>1;
	return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
}
int solve(int L,int R){
	if(L>R) return 0;
	int id=query(L,R+1);
	if(id==INF) return 0;
	return solve(L,l[id]-1)+solve(r[id]+1,R)+r[id]-l[id]+1;
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,m) scanf("%d%d",&l[i],&r[i]),seg[r[i]-l[i]+1].PB(i);
	vector<int> ans;
	rl(i,n,1){
		for(auto it:seg[i]){
			int now=l[it]+N-1;
			while(now){
				if(sgt[now].empty()){
					sgt[now].insert(II(r[it],it));
				}
				else{
					auto ite=sgt[now].lower_bound(II(r[it],0));
					while(ite!=sgt[now].end()&&ite->SEC>it) ite=sgt[now].erase(ite);
					if(ite!=sgt[now].begin()&&prev(ite)->SEC<it);
					else if(ite!=sgt[now].end()&&ite->FIR==r[it]);
					else sgt[now].insert(II(r[it],it));
				}
				now>>=1;
			}
		}
		ans.PB(solve(1,n));
	}
	reverse(ALL(ans));
	for(auto it:ans){
		printf("%d\n",it);
	}
	return 0;
}
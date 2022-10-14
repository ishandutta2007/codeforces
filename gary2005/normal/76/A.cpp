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
const int MAXN=202;
int cnt[MAXN][MAXN];// 
struct bitset_{
	LL val1,val2,val3,val4;
	inline void reset(){
		val1=val2=val3=val4=0ll;
	} 
	bitset_(){
		reset();
	}
	inline bitset_ operator | (bitset_ & that){
		bitset_ ret;
		ret.val1=val1|that.val1;
		ret.val2=val2|that.val2;
		ret.val3=val3|that.val3;
		ret.val4=val4|that.val4;
		return ret;
	}
	inline bitset_ operator & (bitset_ & that){
		bitset_ ret;
		ret.val1=val1&that.val1;
		ret.val2=val2&that.val2;
		ret.val3=val3&that.val3;
		ret.val4=val4&that.val4;
		return ret;
	}
	inline bitset_ operator ^ (bitset_ & that){
		bitset_ ret;
		ret.val1=val1^that.val1;
		ret.val2=val2^that.val2;
		ret.val3=val3^that.val3;
		ret.val4=val4^that.val4;
		return ret;
	}
	inline int count(){// ATTENTION! this is O(n)
		int ret=0;
		LL val=val1;
		while(val){
			ret++;
			val&=(val-1);
		}
		val=val2;
		while(val){
			ret++;
			val&=(val-1);
		}
		val=val3;
		while(val){
			ret++;
			val&=(val-1);
		}
		val=val4;
		while(val){
			ret++;
			val&=(val-1);
		}
		return ret;
	}
	inline int lg2(LL x){
		int l=0,r=50;
		while(l<r-1){
			int mid=(l+r)>>1;
			if((1ll<<mid)<x){
				l=mid;
			}
			else{
				if((1ll<<mid)==x){
					return mid;
				}
				r=mid;
			}
		}
		return l;
	}
	inline int low_bit(){
		if(val1){
			int ret=lg2(val1^(val1&(val1-1)))+1;
			val1&=(val1-1);	
			return ret;	
		}
		if(val2){
			int ret=lg2(val2^(val2&(val2-1)))+50+1;
			val2&=(val2-1);	
			return ret;
		} 
		if(val3){
			int ret=lg2(val3^(val3&(val3-1)))+100+1;
			val3&=(val3-1);	
			return ret;
		} 
		if(val4){
			int ret=lg2(val4^(val4&(val4-1)))+150+1;
			val4&=(val4-1);	
			return ret;
		}
		return 0;	
	}
	inline void set(int x){
		x--;
		if(x<50){
			val1|=1ll<<x;
		}
		else{
			if(x<100){
				x-=50;
				val2|=1ll<<x; 
			}
			else{
				if(x<150){
					x-=100;
					val3|=1ll<<x;
				}
				else{
					x-=150;
					val4|=1ll<<x;
				}
			}
		}
	}
	inline void unset(int x){
		x--;
		if(x<50){
			val1^=(1ll<<x);
		}
		else{
			if(x<100){
				x-=50;
				val2^=(1ll<<x);
			}
			else{
				if(x<150){
					x-=100;
					val3^=(1ll<<x);
				}
				else{
					x-=150;
					val4^=(1ll<<x);
				}
			}
		}
	}
};
bitset_ g_[MAXN];
int n,m;
bool check(){
	bitset_ unv;
	rb(i,2,n){
		unv.set(i);
	}
	queue<int> q;
	q.push(1);
	int Cnt=0;
	while(!q.empty()){
		Cnt++;
		int now=q.front();q.pop();
		bitset_ nex=unv&g_[now];
		unv=unv^nex;
		while(true){
			int nx=nex.low_bit();
			if(!nx) break;
			q.push(nx);
		}
	}
	return Cnt==n;
}
unsigned LL rest=(unsigned LL) 2000000000000000011;
typedef pair<mp,mp>  mpp;
vector<mpp> e1,e2;
#define G SEC.FIR
#define S SEC.SEC
bool cmp(mpp A,mpp B){
	return A.G<B.G;
}
bool cmp2(mpp A,mpp B){
	return A.S<B.S;
}
bool try_erase(int x,int go){
	int u,v;
	u=e2[x].FIR.FIR;
	v=e2[x].FIR.SEC;
	if(e2[x].G>go){
		return true;	
	} 
	cnt[u][v]--;
	cnt[v][u]--;
	if(cnt[u][v]==0){	
		g_[u].unset(v);
		g_[v].unset(u);
	}
	if(check()) return true;
	cnt[u][v]++;
	cnt[v][u]++;
	g_[u].set(v);
	g_[v].set(u);
	return false;
}
void add(int u,int v){
	cnt[u][v]++;
	cnt[v][u]++;
	g_[u].set(v);
	g_[v].set(u);
}
int main(){
	scanf("%d%d",&n,&m);
	int g,s;
	scanf("%d%d",&g,&s);
	rb(i,1,m){
		int u,v,gi,si;
		scanf("%d%d%d%d",&u,&v,&gi,&si);
		if(u==v){
			i--;
			m--;
			continue;
		}
		e1.PB(II(II(u,v),II(gi,si)));
		e2.PB(II(II(u,v),II(gi,si)));
	}
	sort(ALL(e1),cmp);
	sort(ALL(e2),cmp2);
	int t=0;
	priority_queue<mp,vector<mp> ,greater<mp>> q;
	for(auto it:e2){
		int u,v;
		u=it.FIR.FIR;
		v=it.FIR.SEC;
		q.push(II(it.G,t++));
	}
	t--;
	for(auto it:e1){
		while(!q.empty()){
			mp now=q.top();q.pop();
			if(now.SEC<=t){
				if(now.FIR<=it.G) add(e2[now.SEC].FIR.FIR,e2[now.SEC].FIR.SEC);
				else{
					q.push(now);
					break;
				}
			}
		}
		if(check()){
			while(t>=0&&try_erase(t,it.G)){
				t--;
			}
			check_min(rest,(unsigned LL )1*it.G*g+(unsigned LL )1*e2[t].S*s);
		}
	}
	if(rest==(unsigned LL)2000000000000000011){cout<<-1<<endl;return 0;}	
	cout<<rest<<endl;
	return 0;
}
/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,s,d;
const int mod=1145141;
struct Bitset {
	unsigned long long a[16];
	inline Bitset() { memset(a, 0, sizeof(a)); }
	inline void reset() { memset(a, 0, sizeof(a)); }
	inline void set(int i) { a[i >> 6] |= (1ull << (i & 63)); }
	inline Bitset& operator ^= (const Bitset &oth) {
		for (int i = 0; i < 16; i++) a[i] ^= oth.a[i];
		return *this;
	}
	inline Bitset operator ^ (const Bitset &oth) const {
		Bitset ret;
		for (int i = 0; i < 16; i++) ret.a[i] = a[i] ^ oth.a[i];
		return ret;
	}
	inline int getval() const {
		unsigned long long ret = 0;
		for (int i = 0; i < 16; i++) {
			ret = (ret + a[i] % mod * (i+1)*(i+1)%mod) % mod;
		}
		return ret;
	}
	inline bool operator == (const Bitset &oth) const {
		for (int i = 0; i < 16; i++) if (a[i] != oth.a[i]) return false;
		return true;
	}
};
namespace Hash_Table{
	int head[1145141]={0},cnt,nxt[(1<<20)+1]={0},val[(1<<20)+1];
	Bitset bs[(1<<20)+1];
	void insert(Bitset NOW,int VAL){
//		rb(i,1,n) cout<<NOW[i];
//		cout<<endl;
//		cout<<VAL<<endl;
//		 cout<<endl;
		int valu=NOW.getval();
		for(int now=head[valu];now;now=nxt[now]){
			if(bs[now]==NOW){
				check_min(val[now],VAL);
				return;
			}
		}
		++cnt;
		val[cnt]=VAL;
		bs[cnt]=NOW;
		nxt[cnt]=head[valu];
		head[valu]=cnt;
	}
	int query(Bitset NOW){
		int valu=NOW.getval();
		for(int now=head[valu];now;now=nxt[now]){
			if(bs[now]==NOW){
				return val[now];
			}
		}
		return INF;
	}
}
Bitset swi[31];
int bit_count[1<<20];
Bitset full;
Bitset second_part[1<<20];
int second_val[1<<20];
int main(){
//	fastio;
	cin>>n>>s>>d;
	rb(i,1,n) full.set(i);
	rep(i,1<<20)
	{
		if(i)
		bit_count[i]=bit_count[i&(i-1)]+1;
	}
	rep(i,s){
		int c;
		scanf("%d",&c);
		while(c--){
			int a;
			scanf("%d",&a);
			swi[i].set(a);
		}	
	}
	int two=min(10,s/2),one=s-two;
	rep(i,1<<one){
		Bitset now;
		rep(j,s){
			if((i>>j)&1){
				now^=swi[j];
			}
		}	
		Hash_Table:: insert(now,bit_count[i]);
	}
//	cout<<"Second_\n";
	rep(i,1<<two){
		Bitset now;
		rep(j,s){
			if((i>>j)&1){
				now^=swi[j+one];
			}
		}
		second_part[i]=now;
		second_val[i]=bit_count[i];
//		rb(j,1,n) cout<<now[j];
//		cout<<endl;
//		cout<<bit_count[i]<<endl;
//		cout<<endl;
	}
	rb(i,1,d)
	{
		Bitset query;
		int c;
		scanf("%d",&c);
		while(c--){
			int a;
			scanf("%d",&a);
			query.set(a);
		}
		int rest=INF;
		rep(mask,1<<two){
			check_min(rest,second_val[mask]+Hash_Table:: query(query^second_part[mask]));
		}
		if(rest>=INF) rest=-1;
		printf("%d\n",rest);
	}
	return 0;
}
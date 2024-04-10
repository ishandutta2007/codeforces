//2022.8.24 by ljz
//email 573902690@qq.com  
//if you find any bug in my code  
//please tell me  
#include <bits/stdc++.h>
#include <random>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1000000000000000000
#define unl __int128
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define Pair pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define pi acosl(-1.0)
#define pb push_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
#define gc getchar
#define ld long db

//inline int gc() {
//  static char buf[100000], *p1, *p2;
//  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
//}

//char sr[1 << 21], z[20];
//int C = -1, Z = 0;
//inline void Ot() { fwrite(sr, 1, C + 1, stdout), C = -1; }
//
//inline void print(LL x) {
//    if (C > 1 << 20)Ot();
//    if (x < 0)sr[++C] = '-', x = -x;
//    while (z[++Z] = x % 10 + 48, x /= 10);
//    while (sr[++C] = z[Z], --Z);
//}

template<typename T>
inline void Read(T &x) {
	int c = gc();
	bool f = false;
	for (x = 0; !isdigit(c); c = gc())if (c == '-')f = true;
	for (; isdigit(c); c = gc())x = x * 10 + c - '0';
	if (f)x = -x;
}

inline int read() {
	int s = 0, ch = gc(), w = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		else if (ch == EOF) break;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = gc();
	return s * w;
}

inline LL Read() {
	LL s = 0;
	int ch = gc(), w = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		else if (ch == EOF) break;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = gc();
	return s * w;
}

void write(unl x) {
	if (x > 9)write(x / 10);
	putchar(int(x % 10) + '0');
}

const int kcz = 998244353;

inline void add(int &x, const int &y) {
	x += y, x >= kcz ? x -= kcz : 1;
}

inline int Add(const int &x, const int &y) {
	return x + y >= kcz ? x + y - kcz : x + y;
}

inline int mul(const int &x, const int &y) {
	return (int)((LL)x * y % kcz);
}

inline int mul(const int &x, const int &y, const int &d) {
	return (int)((LL)x * y / d % kcz);
}

inline int qpow(int x, int y = kcz - 2) {
	int ret = 1;
	while (y) {
		if (y & 1)ret = mul(ret, x);
		x = mul(x, x), y >>= 1;
	}
	return ret;
}

inline int qpow(int x, int y, const int &ljc) {
	int ret = 1;
	while (y) {
		if (y & 1)ret = (int)((LL)ret * x % ljc);
		x = (int)((LL)x * x % ljc), y >>= 1;
	}
	return ret;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

//2022.8.24 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=3e5+10;
namespace MAIN {
	int n,m;
	struct LH{
		int ls,rs,dis,id;
		LL val,tag;
	}tr[N];
	int rt[N],tot;
	inline void change(const int &x,const LL &v){
		tr[x].val+=v,tr[x].tag+=v;
	}
	inline void pushdown(const int &x){
		if(!tr[x].tag)return;
		change(tr[x].ls,tr[x].tag),change(tr[x].rs,tr[x].tag),tr[x].tag=0;
	}
	int merge(int x,int y){
		if(!x||!y)return x|y;
		pushdown(x),pushdown(y);
		if(tr[x].val>tr[y].val)swap(x,y);
		tr[x].rs=merge(tr[x].rs,y);
		if(tr[tr[x].ls].dis<tr[tr[x].rs].dis)swap(tr[x].ls,tr[x].rs);
		tr[x].dis=tr[tr[x].rs].dis+1;
		return x;
	}
	inline int pop(int x){
		return merge(tr[x].ls,tr[x].rs);
	}
	vector<int> G[N];
	vector<Pair> A[N];
	int dep[N],su[N];
	LL ans;
	void dfs(int x,int fax){
		dep[x]=dep[fax]+1;
		for(auto tox:G[x]){
			if(tox==fax)continue;
			dfs(tox,x),rt[x]=merge(rt[x],rt[tox]),su[x]+=su[tox];
		}
		if(x!=1&&!su[x]){puts("-1");exit(0);}
		for(auto [y,c]:A[x]){
			tot++,tr[tot].val=c,tr[tot].id=y,rt[x]=merge(rt[x],tot);
		}
		while(dep[tr[rt[x]].id]>=dep[x])rt[x]=pop(rt[x]);
		if(rt[x])ans+=tr[rt[x]].val,change(rt[x],-tr[rt[x]].val);
	}
	inline void MAIN(const int &Case) {
		n=read(),m=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			G[u].pb(v),G[v].pb(u);
		}
		while(m--){
			int x=read(),y=read(),c=read();
			A[x].emplace_back(y,c),su[x]++,su[y]--;
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
}

int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

//    srand(time(0));
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
	int Case = 1;
	for (int T = 1; T <= Case; T++)MAIN::MAIN(T);
//    Ot();
	return 0;
}
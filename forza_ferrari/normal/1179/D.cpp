#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;

// #define int ll
#define rep(i, f, t) for (int i = (f), ed##i = (t); i <= ed##i; ++i)
#define re(i, t) rep (i, 1, t)
#define per(i, t, f) for (int i = (t), ed##i = (f); i >= ed##i; --i)
#define ste(i, f, t, s) for (int i = (f), ed##i = (t); i <= ed##i; i += s)
#define each(i, x) for (auto &&i : (x))
#define nxt(i, f, g) for (int i = g.h[f]; i; i = g.e[i].n)
#define dbg(x) (cerr << "\033[34m" << #x " = " << (x) << "\033[0m\n")
#define umod(x) ((x) >= mo && ((x) -= mo))
#define dmod(x) ((x) < 0 && ((x) += mo))
#define y1 y1__
#define fio(x) (freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout))
#define lb(x) ((x)&-(x))

template <class T, class E>
__attribute__((always_inline)) inline void up(T &x, E &&y) {
  if (x < y) x = y;
}
template <class T, class E>
__attribute__((always_inline)) inline void down(T &x, E &&y) {
  if (y < x) x = y;
}

namespace qing_wa {

template <int T>
struct fast_io {
	char p[T], *p1, *p2, q[T], *q1, *q2;
	fast_io() {
		p1 = p2 = p; q1 = q; q2 = q + T;
	}
	char gc() {
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	void pc(char ch) {
		if (q1 == q2) {
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = ch;
	}
	~fast_io() {
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1024768> io;

int read() {
	int r = 0, neg = 1;
	char ch;
	do {
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

void write(long long x) {
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	io.pc(48 + x % 10);
}

void output(long long x, char ch = '\n') {
	write(x);
	io.pc(ch);
}

const int N=1e6+9;
struct G{
  int tot,h[N];
  struct E{
    int t,n;
  }e[N<<1];
  inline void Add(int f,int t){
    e[++tot]={t,h[f]},h[f]=tot;
  }
}g;

int n,sz[N],du[N];
ll dp[N],ans=1e18;

inline void Dfs1(int f,int fa){
  sz[f]=1;
  nxt(i,f,g){
    int t=g.e[i].t;
    if(t==fa)continue;
    Dfs1(t,f);
    sz[f]+=sz[t];
  }
}

inline void Dfs2(int f,int fa){
  dp[f]=dp[fa]+1ll*sz[f]*(sz[f]-1);
  if(f!=fa){
    dp[f]-=1ll*sz[fa]*(sz[fa]-1);
    dp[f]+=1ll*(sz[fa]-sz[f])*(sz[fa]-sz[f]-1);
  }
  nxt(i,f,g){
    int t=g.e[i].t;
    if(t==fa)continue;
    Dfs2(t,f);
  }
}

inline void LuanGao(int rt){
  Dfs1(rt,rt);
  dp[rt]=0,Dfs2(rt,rt);
  // re(i,n)cerr<<i<<' '<<dp[i]<<'\n';
  int mx=1;
  rep(i,2,n){
    if(dp[i]<dp[mx])mx=i;
  }
  down(ans,dp[mx]);
  Dfs1(mx,mx);
  // dbg(mx);
  dp[mx]=0,Dfs2(mx,mx);
  // re(i,n)cerr<<i<<' '<<dp[i]<<'\n';
  re(i,n){
    down(ans,dp[i]);
  }
  // dbg(ans);
}

inline void Main() {
  n=read();
  re(i,n-1){
    int f=read(),t=read();
    ++du[f],++du[t];
    g.Add(f,t),g.Add(t,f);
  }
  LuanGao(1);
  int mx=1;rep(i,2,n)if(du[i]>du[mx])mx=i;
  LuanGao(mx);
  while(clock()*1./CLOCKS_PER_SEC<1.2)LuanGao(rand()%n+1);
  ans=1ll*n*(n-1)-ans/2;
  output(ans);
}
}

signed main() {
  qing_wa::Main();
  return 0;
}
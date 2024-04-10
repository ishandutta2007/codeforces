//2022.8.1 by ljz
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
#define poly vector<int>
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
//	static char buf[100000], *p1, *p2;
//	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
//}

//char sr[1 << 21], z[20];
//int C = -1, Z = 0;
//inline void Ot() { fwrite(sr, 1, C + 1, stdout), C = -1; }
//
//inline void print(LL x) {
//	if (C > 1 << 20)Ot();
//	if (x < 0)sr[++C] = '-', x = -x;
//	while (z[++Z] = x % 10 + 48, x /= 10);
//	while (sr[++C] = z[Z], --Z);
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

inline void write(unl x) {
	if (x > 9)write(x / 10);
	putchar(int(x % 10) + '0');
}

const int kcz = 1000000007;

inline void add(int &x, const int &y) {
	x += y, x >= kcz ? x -= kcz : 1;
}

inline int Add(const int &x, const int &y) {
	return x + y >= kcz ? x + y - kcz : x + y;
}

inline int mul(const int &x, const int &y) {
	return (int)((LL)x * y % kcz);
}

inline int Mul(const int &x, const int &y, const int &d) {
	return (int)((ull)(x) * (y) / (d) % kcz);
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
		if (y & 1)ret = (int)(1ll * ret * x % ljc);
		x = (int)(1ll * x * x % ljc), y >>= 1;
	}
	return ret;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

//2022.8.1 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=5e5+10;
int sg[N],vis[N];
namespace MAIN {
	char str[N];
	inline void MAIN(const int &Case) {
		int n=read();
		int A=0;
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)A+=str[i]=='R';
		if(A>n-A){puts("Alice");return;}
		if(A<n-A){puts("Bob");return;}
		int ans=0;
		int j=1;
		for(int i=2;i<=n;i++){
			if(str[i]==str[i-1]){
				ans^=sg[i-1-j+1],j=i;
			}
		}
		ans^=sg[n-j+1];
		puts(ans?"Alice":"Bob");
	}
}

int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);

//	srand(time(0));
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	sg[2]=1;
	for(int i=1;i<=200;i++){
		for(int j=1;j<i;j++){
			vis[sg[j-1]^sg[i-j-1]]=1;
		}
		for(int j=0;j<=i;j++)if(!vis[j]){sg[i]=j;break;}
		for(int j=0;j<=i;j++)vis[j]=0;
	}
	for(int i=201;i<=N-10;i++)sg[i]=sg[i-34];
	int Case = read();
	for (int T = 1; T <= Case; T++)MAIN::MAIN(T);
//	Ot();
	return 0;
}
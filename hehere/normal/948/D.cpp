// Codeforces Round #470 (rated, Div. 2, based on VK Cup 2018 Round 1)
// Problem D
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'%c", __LINE__, __FUNCTION__, 10);
namespace BasicUnit {
//	template<typename T>
	inline int readint() {
		int a=0, p=1; char c = getchar();
		while(isspace(c)) c = getchar();
		if(c == '-') p = -1, c = getchar();
		while(isdigit(c)) a = a*10 + c - '0', c = getchar();
		return a*p;
	}
	template<typename T>
	inline T min(T a, T b) {
		return a < b ? a : b;
	}
	template<typename T>
	inline T max(T a, T b) {
		return b < a ? a : b;
	}
}
using namespace BasicUnit;
const int maxN = 300000 + 233;
int n, a[maxN], p[maxN];
struct Trie {
	const static int BITWID = 29;
	int n, val[maxN*30], ch[maxN*30][2];
	void init() {
//		this->n = n;
		n = 0;
		memset(val, 0, sizeof(val));
		memset(ch, 0, sizeof(ch));
	}
	void insert(int x) {
		int u = 0; val[0]++;
		for(int i=BITWID; i>=0; i--) {
			int c = (x & (1 << i)) ? 1 : 0;
			if(!ch[u][c]) ch[u][c] = ++n;
			u = ch[u][c];
			val[u]++;
		}
	}
	int tackle(int x) {
		int u = 0; val[0]--;
		int ret = 0, v = 0;
		for(int i=BITWID; i>=0; i--) {
			int c = (x & (1 << i)) ? 1 : 0;
			if(ch[u][c] && val[ch[u][c]]) u = ch[u][c], v |= ((1 << i))*c;
			else u = ch[u][c^1], ret |= 1 << i, v |= ((1 << i))*c;
//			printf("val = %d\n", val[u]);
			val[u]--;
		}
//		printf("%d\n", v);
		return ret;
	}
}trie;

int main() {
//	printf("%.2lf\n", sizeof(Trie)/1000.0/1000.0);
	n = readint();
	for(int i=1; i<=n; i++) a[i] = readint();
	for(int i=1; i<=n; i++) p[i] = readint();
	trie.init();
	for(int i=1; i<=n; i++) trie.insert(p[i]);
	for(int i=1; i<=n; i++) printf("%d ", trie.tackle(a[i]));
	return 0;
}
//CF923C
//
#include <cstdio>
#include <cstring>
#include <cctype>
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'\n", __LINE__, __FUNCTION__);
namespace BasicUnit {
	inline int readint() {
		int a=0, p=1; char c = getchar();
		while(isspace(c)) c = getchar();
		if(c == '-') p = -1, c = getchar();
		while(isdigit(c)) a = a*10 + c - '0', c = getchar();
		return a*p;
	}
	inline LL readLL() {
		LL a=0, p=1; char c = getchar();
		while(isspace(c)) c = getchar();
		if(c == '-') p = -1, c = getchar();
		while(isdigit(c)) a = a*10 + c - '0', c = getchar();
		return a*p;
	}
	inline int min(int a, int b) {
		return a < b ? a : b;
	}
	inline int max(int a, int b) {
		return a > b ? a : b;
	}
	inline LL min(LL a, LL b) {
		return a < b ? a : b;
	}
	inline LL max(LL a, LL b) {
		return a > b ? a : b;
	}
}
using namespace BasicUnit;
const int maxN = 2000 + 23;
int n, a[maxN], s1[maxN], s2[maxN], rs1[maxN], rs2[maxN];
int f[maxN];
struct SparseTable {
	int f[13][maxN], *w, n;
	int log[maxN];
	void Init(int n, int *v) {
		w = v; this->n = n;
		memset(f, 0, sizeof(f));
		memset(log, 0, sizeof(log));
		log[1] = 0;
		for(int i=2; i<=n; i++) log[i] = log[i>>1] + 1;
		for(int i=1; i<=n; i++) f[0][i] = w[i];
		for(int k=1; k<=log[n]; k++)
			for(int i=1; i+(1<<k-1) <= n; i++)
				f[k][i] = max(f[k-1][i], f[k-1][i+(1<<k-1)]);
	}
	int Query(int L, int R) {
		int k = log[R - L + 1];
//		printf("f[%d][%d] = %d, f[%d][%d] = %d\n", k, L, f[k][L], k, R-(1<<k)+1, f[k][R-(1<<k)+1]);
		return max(f[k][L], f[k][R-(1<<k)+1]);
	}
}st;


void Init() {
	n = readint();
	for(int i=1; i<=n; i++) a[i] = readint();
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	memset(rs1, 0, sizeof(rs1));
	memset(rs2, 0, sizeof(rs1));
	for(int i=1; i<=n; i++) {
		s1[i] = s1[i-1]; s2[i] = s2[i-1];
		if(a[i] == 1) ++s1[i]; else ++s2[i];
	}
	for(int i=n; i>=1; i--) {
		rs1[i] = rs1[i+1]; rs2[i] = rs2[i+1];
		if(a[i] == 1) ++rs1[i]; else ++rs2[i];
	}
	memset(f, 0, sizeof(f));
	for(int i=n; i>=1; i--) if(a[i] == 2)
		f[i] = rs1[i] + s2[i];
//	for(int i=1; i<=n; i++) printf("%d ", rs1[i]);printf("\n");
//	for(int i=1; i<=n; i++) printf("%d ", rs2[i]);printf("\n");
//	for(int i=1; i<=n; i++) printf("%d ", f[i]);printf("\n");
	st.Init(n, f);
}

int main() {
	Init();
	int ans = max(s1[n], s2[n]);
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int cur = 0;
			cur = max(cur, s1[j] + rs2[j+1]);
			cur = max(cur, s1[i-1] + rs2[i]);
			int tmp = st.Query(i, j);
			cur = max(cur, s1[i-1] + rs2[j+1] + tmp - rs1[j+1] - s2[i-1]);
//			printf("[%d, %d](%d->%d->%d) cur = %d\n", i, j, tmp, tmp - rs1[j+1] - s2[i-1], s1[i-1] + rs2[j+1] + tmp - rs1[j+1] - s2[i-1], cur);
			ans = max(ans, cur);
		}
	}
	printf("%d\n", ans);
	return 0;
}
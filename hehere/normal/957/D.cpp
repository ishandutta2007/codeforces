// Codeforces Round #472 (rated, Div. 2, based on VK Cup 2018 Round 2)
// Problem D
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::swap; using std::sort;
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'%c", __LINE__, __FUNCTION__, 10);
namespace BasicUnit {
		inline int readint() {
		int a = 0, po = 1; char ch = getchar();
		while(isspace(ch)) ch = getchar();
		if(ch == '-') po = -1, ch = getchar();
		while(isdigit(ch)) a = a*10 + ch - '0', ch = getchar();
		return a * po;
	}
	inline LL readLL() {
		LL a = 0, po = 1; char ch = getchar();
		while(isspace(ch)) ch = getchar();
		if(ch == '-') po = -1, ch = getchar();
		while(isdigit(ch)) a = a*10 + ch - '0', ch = getchar();
		return a * po;
	}
	template<typename T>
	inline T min(T a, T b) { return a < b ? a : b; }
	template<typename T>
	inline T max(T a, T b) { return a > b ? a : b; }
}
using namespace BasicUnit;
const int maxN = 100000 + 233;
int n;
LL m[maxN], sm[maxN];
struct Segment {
	int L, R;
	LL v;
	Segment() { L = R = v = 0; }
	Segment(int L, int R, LL v) : L(L), R(R), v(v) {}
}stk[maxN]; int top = 1;

int main() {
	
	n = readint(); sm[0] = 0;
	for(int i=1; i<=n; i++) sm[i] = sm[i-1] + (m[i] = readLL());
	stk[top] = Segment(n, n, m[n] + 1);
	for(int i=n-1; i>=1; i--) {
		Segment t = Segment(i, i, max(stk[top].v-1, m[i]+1));
		while(top && t.v >= stk[top].v) {
			t.R = stk[top].R;
			top--;
		}
		stk[++top] = t;
	}
	LL cnt = 0;
	for(int i=top; i>=1; i--) {
		Segment &t = stk[i];
		for(int j=t.L; j<=t.R; j++) cnt += t.v - 1 - m[j];
//		printf("Segment[%d, %d] #signs = %d\n", t.L, t.R, t.v);
	}
	cout << cnt << endl;
	
	return 0;
}
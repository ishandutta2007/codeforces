#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
LL dis[N][N];
int a[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
namespace fastIO {
#define BUF_SIZE (20<<20)
#define OUT_SIZE (20<<20)
#define LL long long
	//fread->read
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], * p1 = buf + BUF_SIZE, * pend = buf + BUF_SIZE;
		if (p1 == pend) {
			p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if (pend == p1) { IOerror = 1; return -1; }
			//{printf("IO error!\n");system("pause");for (;;);exit(0);}
		}
		return *p1++;
	}
	inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
	inline void read(int& x) {
		bool sign = 0; char ch = nc(); x = 0;
		for (; blank(ch); ch = nc());
		if (IOerror)return;
		if (ch == '-')sign = 1, ch = nc();
		for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
		if (sign)x = -x;
	}
	inline void read(LL& x) {
		bool sign = 0; char ch = nc(); x = 0;
		for (; blank(ch); ch = nc());
		if (IOerror)return;
		if (ch == '-')sign = 1, ch = nc();
		for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
		if (sign)x = -x;
	}
	inline void read(double& x) {
		bool sign = 0; char ch = nc(); x = 0;
		for (; blank(ch); ch = nc());
		if (IOerror)return;
		if (ch == '-')sign = 1, ch = nc();
		for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
		if (ch == '.') {
			double tmp = 1; ch = nc();
			for (; ch >= '0' && ch <= '9'; ch = nc())tmp /= 10.0, x += tmp * (ch - '0');
		}
		if (sign)x = -x;
	}
	inline void read(char* s) {
		char ch = nc();
		for (; blank(ch); ch = nc());
		if (IOerror)return;
		for (; !blank(ch) && !IOerror; ch = nc())*s++ = ch;
		*s = 0;
	}
	inline void read(char& c) {
		for (c = nc(); blank(c); c = nc());
		if (IOerror) { c = -1; return; }
	}
	//getchar->read
	inline void read1(int& x) {
		char ch; int bo = 0; x = 0;
		for (ch = getchar(); ch < '0' || ch>'9'; ch = getchar())if (ch == '-')bo = 1;
		for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
		if (bo)x = -x;
	}
	inline void read1(LL& x) {
		char ch; int bo = 0; x = 0;
		for (ch = getchar(); ch < '0' || ch>'9'; ch = getchar())if (ch == '-')bo = 1;
		for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
		if (bo)x = -x;
	}
	inline void read1(double& x) {
		char ch; int bo = 0; x = 0;
		for (ch = getchar(); ch < '0' || ch>'9'; ch = getchar())if (ch == '-')bo = 1;
		for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
		if (ch == '.') {
			double tmp = 1;
			for (ch = getchar(); ch >= '0' && ch <= '9'; tmp /= 10.0, x += tmp * (ch - '0'), ch = getchar());
		}
		if (bo)x = -x;
	}
	inline void read1(char* s) {
		char ch = getchar();
		for (; blank(ch); ch = getchar());
		for (; !blank(ch); ch = getchar())*s++ = ch;
		*s = 0;
	}
	inline void read1(char& c) { for (c = getchar(); blank(c); c = getchar()); }
	//scanf->read
	inline void read2(int& x) { scanf("%d", &x); }
	inline void read2(LL& x) {
#ifdef _WIN32
		scanf("%I64d", &x);
#else
#ifdef __linux
		scanf("%lld", &x);
#else
		puts("error:can't recognize the system!");
#endif
#endif
	}
	inline void read2(double& x) { scanf("%lf", &x); }
	inline void read2(char* s) { scanf("%s", s); }
	inline void read2(char& c) { scanf(" %c", &c); }
	inline void readln2(char* s) { /*gets(s); */ }
	//fwrite->write
	struct Ostream_fwrite {
		char* buf, * p1, * pend;
		Ostream_fwrite() { buf = new char[BUF_SIZE]; p1 = buf; pend = buf + BUF_SIZE; }
		void out(char ch) {
			if (p1 == pend) {
				fwrite(buf, 1, BUF_SIZE, stdout); p1 = buf;
			}
			*p1++ = ch;
		}
		void print(int x) {
			static char s[15], * s1; s1 = s;
			if (!x)*s1++ = '0'; if (x < 0)out('-'), x = -x;
			while (x)*s1++ = x % 10 + '0', x /= 10;
			while (s1-- != s)out(*s1);
		}
		void println(int x) {
			static char s[15], * s1; s1 = s;
			if (!x)*s1++ = '0'; if (x < 0)out('-'), x = -x;
			while (x)*s1++ = x % 10 + '0', x /= 10;
			while (s1-- != s)out(*s1); out('\n');
		}
		void print(LL x) {
			static char s[25], * s1; s1 = s;
			if (!x)*s1++ = '0'; if (x < 0)out('-'), x = -x;
			while (x)*s1++ = x % 10 + '0', x /= 10;
			while (s1-- != s)out(*s1);
		}
		void println(LL x) {
			static char s[25], * s1; s1 = s;
			if (!x)*s1++ = '0'; if (x < 0)out('-'), x = -x;
			while (x)*s1++ = x % 10 + '0', x /= 10;
			while (s1-- != s)out(*s1); out('\n');
		}
		void print(double x, int y) {
			static LL mul[] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,
				1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
				100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL };
			if (x < -1e-12)out('-'), x = -x; x *= mul[y];
			LL x1 = (LL)floor(x); if (x - floor(x) >= 0.5)++x1;
			LL x2 = x1 / mul[y], x3 = x1 - x2 * mul[y]; print(x2);
			if (y > 0) { out('.'); for (size_t i = 1; i < y && x3 * mul[i] < mul[y]; out('0'), ++i); print(x3); }
		}
		void println(double x, int y) { print(x, y); out('\n'); }
		void print(char* s) { while (*s)out(*s++); }
		void println(char* s) { while (*s)out(*s++); out('\n'); }
		void flush() { if (p1 != buf) { fwrite(buf, 1, p1 - buf, stdout); p1 = buf; } }
		~Ostream_fwrite() { flush(); }
	}Ostream;
	inline void print(int x) { Ostream.print(x); }
	inline void println(int x) { Ostream.println(x); }
	inline void print(char x) { Ostream.out(x); }
	inline void println(char x) { Ostream.out(x); Ostream.out('\n'); }
	inline void print(LL x) { Ostream.print(x); }
	inline void println(LL x) { Ostream.println(x); }
	inline void print(double x, int y) { Ostream.print(x, y); }
	inline void println(double x, int y) { Ostream.println(x, y); }
	inline void print(char* s) { Ostream.print(s); }
	inline void println(char* s) { Ostream.println(s); }
	inline void println() { Ostream.out('\n'); }
	inline void flush() { Ostream.flush(); }
	//puts->write
	char Out[OUT_SIZE], * o = Out;
	inline void print1(int x) {
		static char buf[15];
		char* p1 = buf; if (!x)*p1++ = '0'; if (x < 0)*o++ = '-', x = -x;
		while (x)*p1++ = x % 10 + '0', x /= 10;
		while (p1-- != buf)*o++ = *p1;
	}
	inline void println1(int x) { print1(x); *o++ = '\n'; }
	inline void print1(LL x) {
		static char buf[25];
		char* p1 = buf; if (!x)*p1++ = '0'; if (x < 0)*o++ = '-', x = -x;
		while (x)*p1++ = x % 10 + '0', x /= 10;
		while (p1-- != buf)*o++ = *p1;
	}
	inline void println1(LL x) { print1(x); *o++ = '\n'; }
	inline void print1(char c) { *o++ = c; }
	inline void println1(char c) { *o++ = c; *o++ = '\n'; }
	inline void print1(char* s) { while (*s)*o++ = *s++; }
	inline void println1(char* s) { print1(s); *o++ = '\n'; }
	inline void println1() { *o++ = '\n'; }
	inline void flush1() { if (o != Out) { if (*(o - 1) == '\n')*--o = 0; puts(Out); } }
	struct puts_write {
		~puts_write() { flush1(); }
	}_puts;
	inline void print2(int x) { printf("%d", x); }
	inline void println2(int x) { printf("%d\n", x); }
	inline void print2(char x) { printf("%c", x); }
	inline void println2(char x) { printf("%c\n", x); }
	inline void print2(LL x) {
#ifdef _WIN32
		printf("%I64d", x);
#else
#ifdef __linux
		printf("%lld", x);
#else
		puts("error:can't recognize the system!");
#endif
#endif
	}
	inline void println2(LL x) { print2(x); printf("\n"); }
	inline void println2() { printf("\n"); }
#undef ll
#undef OUT_SIZE
#undef BUF_SIZE
};
using namespace fastIO;



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	deque < tuple<LL, int, int> > q1, q2;
	int n, m, w;
	read(n);
	read(m);
	read(w);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			read(a[i][j]);
			if (a[i][j] > 0)
				q2.emplace_back(a[i][j], i, j);
		}
	}
	sort(q2.begin(), q2.end());
	MEM(dis, 0x3f);
	LL inf = dis[0][0];
	LL key = inf;
	q1.emplace_back(0, 1, 1);
	dis[1][1] = 0;
	while (!q1.empty() || !q2.empty())
	{
		LL d = 0;
		int x = 0, y = 0;
		if (!q1.empty() && !q2.empty())
		{
			LL d1 = get<0>(q1.front());
			LL d2 = get<0>(q2.front());
			if (d1 <= d2 + key)
			{
				tie(d, x, y) = q1.front();
				q1.pop_front();
			}
			else
			{
				tie(d, x, y) = q2.front();
				q2.pop_front();
				if (dis[x][y] > d + key)
				{
					dis[x][y] = d + key;
					q1.emplace_front(d + key, x, y);
				}
				continue;
			}
		}
		else if (q2.empty())
		{
			tie(d, x, y) = q1.front();
			q1.pop_front();
		}
		else if (q1.empty())
		{
			tie(d, x, y) = q2.front();
			q2.pop_front();
			if (dis[x][y] > d + key)
			{
				dis[x][y] = d + key;
				q1.emplace_front(d + key, x, y);
			}
			continue;
		}
		else
			continue;
		//printf("%d %d\n", x, y);
		if (a[x][y] > 0)
		{
			key = min(key, a[x][y] + dis[x][y]);
		}
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 1 || tx > n) continue;
			if (ty < 1 || ty > m) continue;
			if (a[tx][ty] == -1) continue;
			if (dis[tx][ty] > d + w)
			{
				dis[tx][ty] = d + w;
				q1.emplace_back(d + w, tx, ty);
			}
		}
	}
	LL ans = dis[n][m];
	if (ans == inf)
		ans = -1;
	println(ans);
	return 0;
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

#define int int64_t

using namespace std;
using namespace chrono;

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

//  /

class FastInput {
	private:
		static const int bufSize = 1 << 12;
		char buffer[bufSize+1];
		char *bufPtr;
		FILE *f;
		bool autoClose;
	public:
		inline char getChar() {
			if (*bufPtr == '\0') {
				int bytesRead = fread(buffer, sizeof(char), bufSize, f);
				buffer[bytesRead] = '\0';
				bufPtr = buffer;
			}
			if (*bufPtr == '\0') {
				return '\0';
			} else {
				return *(bufPtr++);
			}
		}
		
		inline string getToken() {
			char c = '\0';
			while (c <= ' ') {
				c = getChar();
			}
			string res = "";
			while (c > ' ') {
				res += c;
				c = getChar();
			}
			return res;
		}
		
		inline int64_t getInt() {
			char c = '\0';
			while (c <= ' ') {
				c = getChar();
			}
			int64_t sign = +1;
			if (c == '+' || c == '-') {
				sign = (c == '+') ? +1 : -1;
				c = getChar();
			}
			uint64_t res = 0;
			while ('0' <= c && c <= '9') {
				res *= 10;
				res += c - '0';
				c = getChar();
			}
			return res * sign;
		}
		
		FastInput(FILE* f, bool autoClose = true)
			:  bufPtr(buffer), f(f), autoClose(autoClose) {
			buffer[0] = '\0';
		}
		
		~FastInput() {
			if (autoClose) {
				fclose(f);
			}
		}
};

class FastOutput {
	private:
		static const int bufSize = 1 << 12;
		char buffer[bufSize+1];
		char *bufPtr;
		FILE *f;
		bool autoClose;
	public:
		inline FastOutput& flush() {
			int portion = bufPtr - buffer;
			if (portion == 0) {
				return *this;
			}
			int bytesWritten = fwrite(buffer, sizeof(char), portion, f);
			if (bytesWritten != portion) {
				raiseError("Disk write error!!!");
			}
			bufPtr = buffer;
			return *this;
		}
	
		inline FastOutput& putChar(char c) {
			if (bufPtr == buffer + bufSize) {
				flush();
			}
			*(bufPtr++) = c;
			return *this;
		}
		
		inline FastOutput& putChars(const char* c) {
			while (*c != '\0') {
				putChar(*c);
				c++;
			}
			return *this;
		}
		
		inline FastOutput& putString(const string& s) {
			putChars(s.c_str());
			return *this;
		}
		
		inline FastOutput& putInt(int64_t v) {
			uint64_t n = v;
			if (v < 0) {
				putChar('-');
				n = -n;
			}
			char buf[20] = {}, *pos = buf;
			do {
				*(pos++) = (n % 10) + '0';
				n /= 10;
			} while (n != 0);
			do {
				pos--;
				putChar(*pos);
			} while (pos != buf);
			return *this;
		}
		
		inline FastOutput& putLn() {
			putChar('\n');
			return *this;
		}
		
		FastOutput(FILE* f, bool autoClose = true)
			: bufPtr(buffer), f(f), autoClose(autoClose) {
		}
		
		~FastOutput() {
			flush();
			if (autoClose) {
				fclose(f);
			}
		}
};

struct StrongComponents {
	int n;
	vector< vector<int> > g, gRev;
	vector<char> used;
	vector<int> topSort;
	
	int compCount;
	vector<int> compId;
	
	void dfs1(int v) {
		if (used[v]) {
			return;
		}
		used[v] = true;
		for (int to: g[v]) {
			dfs1(to);
		}
		topSort.push_back(v);
	}
	
	void dfs2(int v, int id) {
		if (used[v]) {
			return;
		}
		compId[v] = id;
		used[v] = true;
		for (int to: gRev[v]) {
			dfs2(to, id);
		}
	}
	
	inline vector<int> compDivide() {
		gRev.assign(n, vector<int>());
		for (int i = 0; i < n; i++) {
			for (int to: g[i]) {
				gRev[to].push_back(i);
			}
		}
		topSort.clear();
		used.assign(n, false);
		for (int i = 0; i < n; i++) {
			dfs1(i);
		}
		reverse(topSort.begin(), topSort.end());
		used.assign(n, false);
		compCount = 0;
		for (int v: topSort) {
			if (!used[v]) {
				dfs2(v, compCount++);
			}
		}
		return compId;
	}
	
	StrongComponents(int n)
		: n(n), g(n), gRev(n), compId(n) {
	} 
};

struct Road {
	int src, dst;
	int initial;
	int64_t maxCan;
};

signed main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	FastInput qin(stdin, false);
	FastOutput qout(stdout, false);
	int n = qin.getInt(), m = qin.getInt();
	vector<Road> q(m);
	StrongComponents sc(n);
	for (int i = 0; i < m; i++) {
		int src = qin.getInt() - 1, dst = qin.getInt() - 1;
		int initial = qin.getInt();
		
		auto F2 = [&](int64_t q) -> int64_t {
			return q * (q+1) / 2;
		};
		
		auto F3 = [&](int64_t q) -> int64_t {
			return q * (q+1) * (q+2) / 6;
		};
		
		int64_t l = 0, r = (int64_t)1e6;
		while (l < r) {
			int64_t m = (l + r + 1) / 2;
			if (F2(m) < initial) {
				l = m;
			} else {
				r = m-1;
			}
		}
		int64_t maxCan = initial * (l+1) - F3(l);
		
		q[i] = {src, dst, initial, maxCan};
		sc.g[src].push_back(dst);
	}
	
	sc.compDivide();
	
	int cc = sc.compCount;
	vector<int64_t> kost(cc);
	vector< vector< pair<int, int64_t> > > g(cc);
	
	for (int i = 0; i < m; i++) {
		int kSrc = sc.compId[q[i].src];
		int kDst = sc.compId[q[i].dst];
		assert(kSrc <= kDst);
		if (kSrc == kDst) {
			kost[kSrc] += q[i].maxCan;
		} else {
			g[kDst].emplace_back(kSrc, q[i].initial);
		}
	}
	
	int s = qin.getInt() - 1;
	int sC = sc.compId[s];
	vector<int64_t> dp(cc, LLONG_MIN);
	int64_t ans = kost[sC];
	dp[sC] = kost[sC];
	for (int i = sC+1; i < cc; i++) {
		for (auto it : g[i]) {
			if (dp[it.first] != LLONG_MIN) {
				dp[i] = max(dp[i], kost[i] + dp[it.first] + it.second);
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;
	return 0;
}
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using U = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::vector;
using std::pair; using std::make_pair;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[qwq] << (qwq == n ? '}' : ',') << (qwq == n ? '\n' : ' '); }
#include <ctime>
class MyTimer {
  clock_t st;
public:
  MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
  ~MyTimer() { report(); }
  void reset() { st = clock_t(); }
  void report() {  cerr << "Time consumed: " << (clock() - st) * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
} myTimer;
#else
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
class MyTimer {
public: void reset() {} void report() {}
} myTimer;
#endif

template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }
#ifdef QUICK_READ
char pool[1<<15|1],*it=pool+32768;
#define getchar() (it>=pool+32768?(pool[fread(pool,sizeof(char),1<<15,stdin)]=EOF,*((it=pool)++)):*(it++))
#endif
inline int readint() {
  int a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}
inline LL readLL() {
  LL a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}

const int maxN = 50 + 5;
const LL maxK = (LL)1e16 + 2333;
int n, a[maxN];
int comp(int x, int y) { return x > y ? 1 : x == y ? 0 : -1; }
int combcomp(int x, int y) { return x ? x : y; }
struct Triple {
  int x, y, z;
  Triple() {}
  Triple(int x, int y, int z) : x(x), y(y), z(z) {}
  bool operator < (const Triple &rhs) {
    return x != rhs.x ? x < rhs.x
                      : y != rhs.y ? y < rhs.y
                                   : z < rhs.z;
  }
  friend bool operator == (const Triple &A, const Triple &B) {
    return A.x == B.x && A.y == B.y && A.z == B.z;
  }
  friend Triple operator * (const Triple &x, const Triple &y) {
  	return Triple(combcomp(x.x, y.x), combcomp(x.y, y.y), combcomp(x.z, y.z));
	}
  int hashit() {
    return (x + 1) << 6 | (y + 1) << 3 | (z + 1);
  }
  int id(); int dir();
}trip[13], dir_table[4];
Triple get(int x, int y, int z) {
  return Triple(comp(x, y), comp(x, z), comp(y, z));
}
int Triple::id() {
  for(int i = 0; i < 13; ++i) if(*this == trip[i]) return i;
  assert(false);
  return -1;
}
int Triple::dir() {
  for(int i = 0; i < 4; ++i) if(*this == dir_table[i]) return i;
  // assert(false);
  return -1;
}
LL k;

void build() {
  int v[3]; v[0] = 0; v[1] = 1; v[2] = 2;
  int cnt = 0;
  trip[cnt++] = Triple(0, 0, 0);
  do {
    trip[cnt++] = Triple(comp(v[0], v[1]), comp(v[0], v[2]), comp(v[1], v[2]));
  } while(std::next_permutation(v, v + 3));
  v[0] = 0; v[1] = 1; v[2] = 1;
  do {
    trip[cnt++] = Triple(comp(v[0], v[1]), comp(v[0], v[2]), comp(v[1], v[2]));
  } while(std::next_permutation(v, v + 3));
  v[0] = 0; v[1] = 0; v[2] = 1;
  do {
    trip[cnt++] = Triple(comp(v[0], v[1]), comp(v[0], v[2]), comp(v[1], v[2]));
  } while(std::next_permutation(v, v + 3));
  assert(cnt == 13);
  dir_table[0] = get(0, 0, 0);
	dir_table[1] = get(0, 1, 1);
	dir_table[2] = get(0, 0, 1);
	dir_table[3] = get(0, 1, 2);
}

LL solve(int *G, bool flag = false) { // calculate #(A < A^R <= G)
  static LL f[maxN][4][13];
  // Triples as 01 - 02 - 12
  memset(f, 0, sizeof(f));
  f[0][Triple(0, 0, 0).dir()][Triple(0, 0, 0).id()] = 1;
  for(int i = 1, j = n; i < j; ++i, --j) {
    for(int _x = 0; _x < 4; ++_x) for(int _y = 0; _y < 13; ++_y) {
      LL val = f[i - 1][_x][_y]; if(!val) continue;
      Triple x = dir_table[_x], y = trip[_y];
      assert(x.dir() == _x); assert(y.id() == _y);
      for(int s = 0; s < 2; ++s) for(int t = 0; t < 2; ++t) {
        // M[x] * (s, t, G[i])
        // (t, s, G[j]) * M[y]
        Triple nx = x * get(s, t, G[i]), ny = get(flag ? !t : t, flag ? !s : s, G[j]) * y;
        if(nx.dir() < 0 || ny.id() < 0) continue;
        f[i][nx.dir()][ny.id()] += val;
//        printf("i = %d : s = %d, t = %d, f += %lld\n", i, s, t, val);
//        printf("\t (%d, %d) -> (%d, %d)\n", x.dir(), y.id(), nx.dir(), ny.id());
      }
    }
  }
  LL ans = 0;
  if(n % 2 == 0) {
    for(int _x = 0; _x < 4; ++_x) for(int _y = 0; _y < 13; ++_y) {
      Triple x = dir_table[_x], y = trip[_y];
      Triple p = x * y;
      if(p.x == -1 && p.z == -1) ans += f[n / 2][_x][_y];
      // A < A^R < G
    }
  } else {
    int i = n / 2 + 1;
    for(int t = 0; t < 2; ++t)
    for(int _x = 0; _x < 4; ++_x) for(int _y = 0; _y < 13; ++_y) {
      Triple x = dir_table[_x], y = trip[_y];
      Triple p = (x * get(t, flag ? !t : t, G[i])) * y;
      if(p.x == -1 && p.z == -1) ans += f[n / 2][_x][_y];
    }
  }
  return ans;
}

LL calc(int *a) {
  LL r = 0;
  for(int i = 1; i <= n; ++i) r = r * 2 + a[i];
  return r - 1;
}

LL general(int *a) {
	return calc(a) - solve(a, true) - solve(a, false);
}

bool isValid(int *a) {
	static int b[maxN], c[maxN];
	for(int i = 1; i <= n; ++i) b[i] = a[n + 1 - i];
	for(int i = 1; i <= n; ++i) c[i] = !b[i];
	for(int i = 1; i <= n; ++i) {
		if(a[i] < b[i]) break;
		else if(a[i] > b[i]) return false;
	}
	for(int i = 1; i <= n; ++i) {
		if(a[i] < c[i]) break;
		else if(a[i] > c[i]) return false;
	}
	return true;
}

bool add(int *a) {
	int i = n;
	while(a[i] == 1) a[i--] = 0;
	if(i < 1) {
		return false;
	}
	a[i] = 1;
	return true;
}

void debugger() {
  for(int S = 1; S < (1 << n); ++S) {
  	for(int i = 0; i < n; ++i) a[n - i] = S >> i & 1;
  	if(a[1] == 1) break;
  	LL r = general(a);
  	for(int i = 1; i <= n; ++i) printf("%d", a[i]);
  	printf(" : %lld\n", r);
	}
	exit(0);
}

int main() {
	build();
  cin >> n >> k;
//	debugger();
  memset(a, 0, sizeof(a));
  for(int i = 2; i <= n; ++i) {
    a[i] = 1;
    LL t = calc(a) - solve(a, true) - solve(a, false);
//    fprintf(stderr, "digit %d : %lld\n", i, t);
    if(t < k) a[i] = 1;
    else a[i] = 0;
  }
  while(!isValid(a)) {
  	if(!add(a)) { cout << "-1" << endl; return 0; }
	}
	if(general(a) != k - 1) { cout << "-1" << endl; return 0; }
  for(int i = 1; i <= n; ++i) cout << a[i]; cout << endl;
	return 0;
}
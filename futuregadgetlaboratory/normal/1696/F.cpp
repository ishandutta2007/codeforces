#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<chrono>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
#include<type_traits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(chrono::system_clock::now().time_since_epoch().count());
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}
inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
template<LL mod> struct Num {
	LL a;
	Num operator + (const Num & b) { return Num{(a + b.a) % mod}; }
	Num operator - (const Num & b) { return Num{(a - b.a + mod) % mod}; }
	Num operator * (const Num & b) { return Num{a * b.a % mod}; }
	Num operator / (const Num & b) { return Num{a * fastpo(b.a, mod - 2, mod) % mod}; }
	void operator += (const Num & b) {if((a += b.a) >= mod) a -= mod;}
	void operator -= (const Num & b) {if((a -= b.a) < 0) a += mod;}
	void operator *= (const Num & b) { a = a * b.a % mod; }
	void operator /= (const Num & b) { a = a * fastpo(b.a, mod - 2, mod) % mod; }
	void operator = (const Num & b) { a = b.a; }
	void operator = (const LL & b) { a = b; }
};
template<LL mod> ostream & operator << (ostream & os, const Num<mod> & a) {
	os << a.a;
	return os;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(LL x, int width = 0) {
	string res;
	if(x == 0) res.push_back('0');
	while(x) {
		res.push_back('0' + x % 10);
		x /= 10;
	}
	while((int)res.size() < width) res.push_back('0');
	reverse(res.begin(), res.end());
	return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
	fwrite(buf, 1, _bl, stdout);
	_bl = 0;
}
__inline void _putchar(char c) {
	if(_bl == _B) flush();
	buf[_bl++] = c;
}
inline void print(LL x, char c) {
	static char tmp[20];
	int l = 0;
	if(!x) tmp[l++] = '0';
	else {
		while(x) {
			tmp[l++] = x % 10 + '0';
			x /= 10;
		}
	}
	for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
	_putchar(c);
}
typedef double C;
struct P {
	C x, y;
	void scan() {
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x; y = _y;
	}
	void print() {
		cout << '(' << x << ' ' << y << ')' << endl;
	}
	P operator + (const P & b) const { return P{x + b.x, y + b.y}; }
	P operator - (const P & b) const { return P{x - b.x, y - b.y}; }
	C operator * (const P & b) const { return x * b.y - y * b.x; }
	C operator % (const P & b) const { return x * b.x + y * b.y; }
};
P operator * (const C & x, const P & b) { return P{x * b.x, x * b.y}; }
const int N = 111;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int rela[N];
int getr(int x) {
    int p = x;
    while(rela[p] != p) p = rela[p];
    int p1 = p; p = x;
    while(rela[p] != p) {
        int p2 = rela[p];
        rela[p] = p1;
        p = p2;
    }
    return p1;
}
char s[N][N][N];
int vst[N];
vector<vector<int> > cls[N];
int lvl[N], dis[N][N], fa[N], o[N];
int main() {
	int t;
	scanf("%d", &t);
//t = 1000;
	for(int qq = 1; qq <= t; qq++) {
		int n;
		scanf("%d", &n);
/*n = 100;
memset(dis, inf, sizeof(dis));
for(int i = 1; i <= n; i++) {
	dis[i][i] = 0;
	if(i > 1) {
		int x = gene() % (i - 1) + 1;
		dis[x][i] = dis[i][x] = 1;
	}
}
for(int k = 1; k <= n; k++) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
		}
	}
}*/

		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				scanf("%s", s[i][j] + 1);
//for(int k = 1; k <= n; k++) s[i][j][k] = dis[i][k] == dis[j][k] ? '1' : '0';
			}
		}
		int mn = n;
		for(int i = 1; i <= n; i++) {
			memset(vst, false, sizeof(vst));
			for(int j = 1; j <= n; j++) {
				if(vst[j]) continue;
				vector<int> vec;
				vec.pb(j);
				vst[j] = 1;
				for(int k = j + 1; k <= n; k++) {
					if(s[j][k][i] == '1') {
						//cout << s[j][k][i];
						vec.pb(k);
						vst[k] = 1;
					}
				}
				//cout << i << ' ' << j << endl;
				cls[i].pb(vec);
			}
			mn = min(mn, (int)cls[i].size());
		}
		//cout << "mn" << mn << endl;
		vector<int> v0;
		for(int i = 1; i <= n; i++) {
			lvl[i] = cls[i].size() - mn;
			if(lvl[i] == 0) {
				v0.pb(i);
				//cout << "mini" << i << endl;
			}
		}
		vector<pair<int, int> > ans;
		if(v0.size() == 2) {
			ans.pb({v0[0], v0[1]});
		}
		for(int i = 1; i <= n; i++) fa[i] = -1;
		for(int i = 1; i <= n; i++) o[i] = i;
		sort(o + 1, o + 1 + n, [&](int x, int y) { return lvl[x] < lvl[y];});
		
		for(int d = 1; d <= n; d++) {
			int i = o[d];
			//cout << i << ' ' << lvl[i] << endl;
			for(auto & t : cls[i]) {
				bool flag = false;
				bool f1 = false;
				for(auto v : t) {
					if(lvl[v] == lvl[i] - 1 && fa[i] == v) {
						flag = true;
					}
					if(v0.size() == 1 && lvl[i] == 0 && lvl[v] == 1) {
						flag = true;
					}
					if(lvl[i] == 0 && v == v0[0] + v0[1] - i) {
						f1 = true;
					}
				}
				flag = lvl[i] > 0 || v0.size() == 1 ? flag : f1;
				if(flag) {
					for(auto v : t) {
						if(lvl[v] == lvl[i] + 1) {
							
							ans.pb({i, v});
							fa[v] = i;
							//cout << i << '~' << v << endl;
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = i == j ? 0 : inf;
		for(auto t : ans) {
			dis[t.fi][t.se] = 1;
			dis[t.se][t.fi] = 1;
		}

		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				for(int k = 1; k <= n; k++) {
					if((s[i][j][k] == '1') != (dis[i][k] == dis[j][k])) {
						flag = false;
					}
				}
			}
		}
		if(ans.size() != n - 1) flag = false;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(dis[i][j] == inf) flag = false;
/*if(!flag) {
	printf("%d %d\n", ans.size(), flag);
	assert(false);
}*/
		if(flag) {
			printf("Yes\n");
			for(auto t : ans) printf("%d %d\n", t.fi, t.se);
		}else printf("No\n");
		for(int i = 1; i <= n; i++) cls[i].clear();
	}

}
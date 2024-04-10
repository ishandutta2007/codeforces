#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);


using namespace std;


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);
template<class T> void re(std::vector<T>& a);


void pr(int x);


void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

void pc();
template<class T, class... Ts> void pc(const T& t, const Ts&... ts);

#define dbg(x...) pr("[",#x,"] = ["), pc(x);


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


const int MOD = 1000000007;

int m[110][110];
int temp[110][110];
int ans[110][110];

void mult(int c[110][110], int a[110][110], int b[110][110]) {
    REP(i,105) REP(j,105) c[i][j] = 0;
    REP(i,105) REP(k,105) REP(j,105) {
        c[i][j] = (c[i][j] + a[i][k] * 1ll * b[k][j]) % MOD;
    }
}

void copia(int c[110][110], int a[110][110]) {
    REP(i,105) REP(j,105) c[i][j] = a[i][j];
}

vector<int> a;
int n,k;

int C2(int n) {
    long long k = (n * 1ll * (n-1))%MOD;
    k = (k * modInv(2,MOD)) % MOD;
    return k;
}

void solve()
{
    re(n, k);
    a.resize(n); re(a);

    int left_side = 0;
    REP(i,n) {
        if (a[i] == 0) left_side++;
    }

    int right_side = n - left_side;
    int invn2 = modInv(C2(n), MOD);

    for (int i = max(0, left_side - right_side); i <= left_side; i++) {
        if (i != max(0, left_side - right_side)) {
            m[i][i-1] = (i * 1ll * (i + right_side - left_side)) % MOD;
            m[i][i-1] = (m[i][i-1] * 1ll * invn2) % MOD;
            //dbg(i, m[i][i-1]);
        }
        
        m[i][i] = ((left_side-i) * 1ll * (i + right_side - left_side)) % MOD;
        m[i][i] = (m[i][i] + i * 1ll * (left_side-i)) % MOD;
        m[i][i] = (m[i][i] + C2(left_side) + C2(right_side)) % MOD;
        m[i][i] = (m[i][i] * 1ll * invn2) % MOD;
        //dbg(i, m[i][i]);

        if (i < left_side) {
            m[i][i+1] = ((left_side-i) * 1ll * (left_side-i)) % MOD;
            m[i][i+1] = (m[i][i+1] * 1ll * invn2) % MOD;
            //dbg(i, m[i][i+1]);
        }
    }

    REP(i, 105) ans[i][i] = 1;

    while (k) {
        if (k&1) {
            mult(temp, ans, m);
            copia(ans, temp);
        }
        mult(temp, m, m);
        copia(m, temp);
        k >>= 1;
    }
    
    int has = 0;
    REP(i, left_side) if (a[i]==0) has++;

    //dbg(has);
    ps(ans[has][left_side]);
}


int main() {


    solve();
}


template <typename T>
T extGcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m) {
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

void pc() { pr("]\n"); }
template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
}
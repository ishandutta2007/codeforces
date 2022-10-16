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

#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);


int n,m;


const int mod = 998244353;
int prob[3100][3100];
int a[210000];
int w[210000];
int likw, otw;

void solve()
{
    re(n,m);

    for (int i = 0; i < n; i++) {
        re(a[i]);
    }
    for (int i = 0; i < n; i++) {
        re(w[i]);
        if (a[i]) likw += w[i];
        else otw += w[i];
    }

    prob[0][0] = 1;

    for (int d = 1; d <= m; d++) {
        for (int picked = 0; picked <= d; picked++) {
            
            int np = d - picked;
            if (np > otw) continue;

            long long picks = (prob[d-1][picked-1] * 1ll * (likw+picked-1)) % mod;
            picks = (picks * 1ll * modInv(likw+otw+(picked-1)-np, mod)) % mod;
            
            long long nopicks = prob[d-1][picked] * 1ll * (otw - (np-1)) % mod;
            nopicks = (nopicks * 1ll * modInv(likw+otw+picked-(np-1), mod)) % mod;
            prob[d][picked] = (picks + nopicks) % mod;
        }
    }

    int likeex = likw;
    for (int picked = 0; picked <= m; picked++) {
        likeex = (likeex + picked * 1ll * prob[m][picked]) % mod;
    }
    likeex = (likeex * 1ll * modInv(likw, mod)) % mod;

    int otex = 0;
    for (int picked = 0; picked <= m; picked++) {
        int npicked = m-picked;
        long long th = (prob[m][picked] * 1ll * (otw - npicked)) % mod;
        otex = (otex + th) % mod;
    }
    otex = (otex * 1ll * modInv(otw, mod)) % mod;

    for (int i = 0; i < n; i++) {
        if (a[i]) printf("%lld\n", (w[i] * 1ll * likeex) % mod);
        else printf("%lld\n", (w[i] * 1ll * otex) % mod);
    }
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
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


using namespace std;


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);


typedef pair<int, int> pii;


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n, m;

vector<pii> g[110000];
vector<pii> outward[110000];
vector<int> inward[110000];
bool done[110000];
int s[110000];
int p10[110000];
int i10[110000];

void sdfs(int v, int p) {
    s[v] = 1;
    for (auto x : g[v]) if (x.first != p && !done[x.first]) {
        sdfs(x.first, v);
        s[v] += s[x.first];
    }
}

void dfs(int v, int p, int out, int in, int h, int rt) {
    outward[rt].push_back({out, h});
    inward[rt].push_back(in);
    for (auto x : g[v]) if (x.first != p && !done[x.first]) {
        dfs(x.first, v, (out*10ll+x.second)%m, (in+x.second*1ll*p10[h])%m, h+1, rt);
    }
}

long long decompose(int v) {
    sdfs(v,-1);

    int cen = v, p = -1;
    bool found = false;
    while (!found) {
        found = true;
        for (auto x : g[cen]) if (x.first != p && !done[x.first]) {
            if (s[x.first]+s[x.first] >= s[v]){
                p = cen; cen = x.first;
                found = false;
                break;
            }
        }
    }

    map<int, int> counts;
    long long ans = 0;
    done[cen] = true;
    
    //printf("START COUNT FOR %d\n", cen);
    counts[0]++;
    for (auto x : g[cen]) if (!done[x.first]) {
        outward[x.first].clear(); inward[x.first].clear();
        dfs(x.first, -1, x.second%m, x.second%m, 1, x.first);
        for (int pp : inward[x.first]) {
            if (pp == 0) ans++;
            counts[pp]++;
        }
    }

    //  for (auto x : g[cen]) if (!done[x.first]) {
    //      printf("branch %d\n", x.first);
    //      for (int pp : inward[x.first]) printf("%d ", pp);
    //      printf("\n");
    // }

    for (auto x : g[cen]) if (!done[x.first]) {
        for (int pp : inward[x.first]) counts[pp]--;
        for (auto pp : outward[x.first]) {
            int want = ((m-pp.first) * 1ll * i10[pp.second]) % m; 
            ans += counts[want];
        }
        for (int pp : inward[x.first]) counts[pp]++;
    }

    // printf("centroid %d -> %lld\n", cen, ans);
    for (auto x : g[cen]) if (!done[x.first]) {
        ans += decompose(x.first);
    }
    return ans;
}

void solve()
{
    re(n,m);
    rep(i,0,n-1) {
        int a, b, c;
        re(a,b,c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    p10[0] = i10[0] = 1;
    rep(i,1,n+1) {
        p10[i] = (p10[i-1] * 1ll * 10) % m;
        i10[i] = modInv(p10[i], m);
    }

    ps(decompose(0));
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


void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
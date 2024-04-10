#pragma GCC target("avx2")
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
#include "immintrin.h" 


using namespace std;


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef pair<int, int> pii;


#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int n, m, q;
alignas(32) int smt[1024][1024];

void Vmin(int* V, int *V2, int n) {
    int i = 0;
    for (i = 0; i+8 <= n; i += 8) {
        __m256i v1 = _mm256_load_si256((__m256i*) &V[i]);
        __m256i v2 = _mm256_load_si256((__m256i*) &V2[i]);
        __m256i v3 = _mm256_min_epi32(v1, v2);
        _mm256_store_si256((__m256i*) &V[i], v3);
        _mm256_store_si256((__m256i*) &V2[i], v3);
    }

    for (; i < n; i++) {
        V[i] = V2[i] = min(V[i], V2[i]);
    }
}

int ans[210000];

void solve()
{
    re(n,m,q);

    rep(i,n) {
        rep(j,n) smt[i][j] = 1000000000;
        smt[i][i] = 0;
    }

    vector< pii > edges(m);
    vector< pair< pair< pii, pii >, int > > queries(q);

    for (int i = 0; i < m; i++) {
        int u,v; re(u,v); u--; v--;
        edges[i] = {u,v};
    }

    for (int i = 0; i < q; i++) {
        re(queries[i].first.first.first, queries[i].first.first.second, queries[i].first.second.first, queries[i].first.second.second); 
        queries[i].first.first.first--; queries[i].first.first.second--;
        queries[i].first.first.first = -queries[i].first.first.first;
        queries[i].second = i;
    }
    sort(all(queries));

    int at = m-1;
    for (int i = 0; i < q; i++) {
        while (at >= -queries[i].first.first.first) {
            int u = edges[at].first, v = edges[at].second;
            Vmin(smt[u], smt[v], n);
            smt[u][v] = smt[v][u] = at;
            at--;
        }

        ans[queries[i].second] = (smt[queries[i].first.second.first-1][queries[i].first.second.second-1] <= queries[i].first.first.second);
    }

    for (int i = 0; i < q; i++) {
        ps(ans[i] ? "Yes" : "No");
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
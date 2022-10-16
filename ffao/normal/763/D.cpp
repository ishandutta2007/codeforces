#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#include <random>
#include <chrono>

int n,a,b;
vector<pii> edges;
vector<int> adj[210000];
unsigned long long t[210000];
int size[210000];
int order[210000];
unsigned long long ad[210000];

multiset<unsigned long long> allt;
int curcnt;
int ans, ani;

int dfs(int v, int p) {
    int tam = 1;
    for (int e : adj[v]) {
        int dest;
        if (e >= n-1) dest = edges[e - (n-1)].first;
		else dest = edges[e].second;

        if (dest != p) {
            size[e] = dfs(dest, v);
            tam += size[e];
        }
    }
    return tam;
}

unsigned long long get_seq(int e) {
	int v, rev;
	if (e >= (n-1)) {
		v = edges[e-(n-1)].first;
        rev = e-(n-1);
	}
	else {
		v = edges[e].second;
        rev = e+(n-1);
	}

    return ad[v] - t[rev];
}

bool comps(int a, int b) {
	return size[a] < size[b];
}

void add(unsigned long long t) {
    if (allt.find(t) == allt.end()) curcnt++;
    allt.insert(t);
}

void rem(unsigned long long t) {
    allt.erase(allt.find(t));
    if (allt.find(t) == allt.end()) curcnt--;
}

void odfs(int v, int p) {
    for (int e : adj[v]) {
        int dest;
        if (e >= n-1) dest = edges[e - (n-1)].first;
		else dest = edges[e].second;

        if (dest != p) {
            add(t[e]);
            odfs(dest, v);
        }
    }
}

void ddfs(int v, int p) {
    if (curcnt > ans) {
        ans = curcnt;
        ani = v;
    }
    for (int e : adj[v]) {
        int dest, ote;
        if (e >= n-1) {
			dest = edges[e - (n-1)].first;
            ote = e - (n-1);
		}
		else {
			dest = edges[e].second;
            ote = e + (n-1);
		}

        if (dest != p) {
            rem(t[e]);
            add(t[ote]);
            ddfs(dest, v);
            rem(t[ote]);
            add(t[e]);
        }
    }
}

void solve()
{
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<unsigned long long> dist;

    memset(size, -1, sizeof(size));

    scanf("%d", &n);

    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b); a--; b--;
        edges.push_back({a,b});
        adj[a].push_back(i);
        adj[b].push_back((n-1) + i);
    }

    dfs(0, -1);
    for (int i = 0; i < n-1; i++) {
        if (size[i] == -1) size[i] = n - size[(n-1) + i];
        else size[(n-1) + i] = n - size[i];
    }

    for (int i = 0; i < 2*(n-1); i++) {
        order[i] = i;
    }
    sort(order, order + 2*(n-1), comps);

    int cur = 0;
    while (cur < 2*(n-1)) {
        int st = cur;
        int th = size[order[cur]];
        while (cur < 2*(n-1) && size[order[cur]] == th) cur++;

        vector< pair< unsigned long long, int > > seqs;
        for (int k = st; k < cur; k++) {
            seqs.push_back(make_pair(get_seq(order[k]), order[k]));
        }

        sort(seqs.begin(), seqs.end());

        unsigned long long cur_t = 0;
        for (int k = 0; k < seqs.size(); k++) {
            if (k == 0 || seqs[k].first != seqs[k-1].first) {
                cur_t = dist(rng);
            }
            //printf("t[%d]=%llu (%d %llu)\n", seqs[k].second, cur_t, seqs[k].first.first, seqs[k].first.second);
            t[seqs[k].second] = cur_t;
            
            int e = seqs[k].second, p;
            if (e >= (n-1)) p = edges[e-(n-1)].second;
            else p = edges[e].first;

            ad[p] += t[e];
        }
    }

    odfs(0, -1);
    ddfs(0, -1);
    ps(ani+1);
}

int main() {

    solve();
}

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
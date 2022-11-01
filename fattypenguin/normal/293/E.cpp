#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;


const int maxn = 200007;

vector<pair<int, int> > e[maxn];
int sz[maxn], n;
bool vis[maxn];
pair<ll, int> tmp[maxn];
long long l, w, ans = 0;

void calcSize(int u, int fa)
{
    sz[u] = 1;
    int n = e[u].size();
    vector<pair<int,int> > &v = e[u];
    for (int i = 0;i < n; ++i)
        if (!vis[v[i].first] && v[i].first != fa)
        {
            calcSize(v[i].first, u);
            sz[u] += sz[v[i].first];
        }
}

int findCenter(int u, int fa, int size)
{
    int maxpart = size - sz[u], n = e[u].size();
    vector<pair<int,int> > &v = e[u];
    for (int i = 0; i < n; ++i)
        if (!vis[v[i].first] && v[i].first != fa)
            maxpart = max(maxpart, sz[v[i].first]);
    if (maxpart * 2 <= size) return u;
    for (int t, i = 0; i < n; ++i)
        if (!vis[v[i].first] && v[i].first != fa)
        {
            t = findCenter(v[i].first,u,size);
            if (t != -1) return t;
        }
    return -1;
}

int getCenter(int u)
{
    calcSize(u, -1);
    return findCenter(u,-1,sz[u]);
}

void getLength(int u, int fa, int distance, pair<ll, int> dist[], int &top, int depth)
{
	if (depth <= l && distance <= w) ++ans;
    dist[top++] = MP(distance, depth);
    int n = e[u].size();
    vector<pair<int,int> > &v = e[u];
    for (int i = 0;i < n; ++i)
        if (!vis[v[i].first] && v[i].first != fa)
            getLength(v[i].first, u, distance + v[i].second, dist, top, depth + 1);
}

pair<ll, int> res[maxn];

struct Event {
	int x, k;

	Event(int x, int k) : x(x), k(k) {

	}

	bool operator < (const Event &o) const {
		return x < o.x;
	}
};

int BIT[maxn];

void add(int x, int y) {
	++x;
	while (x <= n + 10) {
		BIT[x] += y;
		x += x & -x;
	}
}

int sum(int x) {
	++x;
	int ret = 0;
	while (x) {
		ret += BIT[x];
		x -= x & -x;
	}

	return ret;
}


ll getValidPairs(pair<ll, int> d[], int limit, int l, int r)
{
    // int ret = 0;
    // while (l < r)
    // {
    //     while (d[r] + d[l] > limit)
    //         --r;
    //     if (l <= r) ret += r - l;
    //     ++l;
    // }
    // return ret;
	int total = 0;
	for (int i = l; i <= r; ++i) {
		res[total++] = d[i];
	}

	vector<PII> event;
	int ptr = total - 1;
	for (int i = 0; i < total; ++i) {
		while (ptr > i && res[i].first + res[ptr].first > limit) --ptr;
		// cout << "PTR = " << res[i].first << " " << res[ptr].first << endl;
		if (ptr <= i) break;
		if (i < ptr && res[i].second < ::l && res[i].first + res[ptr].first <= limit) {
			event.PB(MP(i, -(::l - res[i].second)));
			event.PB(MP(ptr, ::l - res[i].second));
		}
	}

	SORT(event);
	// TR(it, event) cout << "event x = " << it->first << " " << it->second << endl;

	ll ret = 0;
	ptr = 0;
	for (int i = 0; i < total; ++i) {
		add(res[i].second, 1);
		while (ptr < event.size() && event[ptr].first <= i) {
			int t = event[ptr].second;
			if (t < 0) {
				ret -= sum(abs(t));
			} else {
				ret += sum(abs(t));
			}
			++ptr;
		}
	}

		while (ptr < event.size()) {
			int t = event[ptr].second;
			if (t < 0) {
				ret -= sum(abs(t));
			} else {
				ret += sum(abs(t));
			}
			++ptr;
		}

	for (int i = 0; i < total; ++i) {
		add(res[i].second, -1);
	}

	return ret;

}

void solve(int u)
{
    u = getCenter(u);
    vis[u] = true;
    int n = e[u].size();
    vector<pair<int,int> > &v = e[u];
    int cnt = 0, prev = 0;
    ll part = 0;
    for (int i = 0; i < n; ++i)
        if (!vis[v[i].first])
        {
            getLength(v[i].first, u, v[i].second, tmp, cnt, 1);
            sort(tmp+prev, tmp+cnt);
            part += getValidPairs(tmp,w,prev,cnt-1);
            prev = cnt;
        }
    sort(tmp,tmp + cnt);
    // cout << "u = " << u << " ans1 = " << ans << endl;
    ans += getValidPairs(tmp,w,0,cnt-1) - part;
    // cout << "u = " << u << " ans2 = " << ans << endl;
    for (int i = 0; i < n; ++i)
        if (!vis[v[i].first])
            solve(v[i].first);
}

int main() {
	cin >> n >> l >> w;
	REP(i, n - 1) {
		int u, v, t;
		scanf("%d%d", &u, &t);
		--u;
		v = i + 1;
		e[u].PB(MP(v, t));
		e[v].PB(MP(u, t));
	}
	solve(0);
	cout << ans << endl;
	return 0;
}
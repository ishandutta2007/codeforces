#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int maxn = 111111;
map<int, int> M[maxn];
vector<int> vec[maxn];
int n, tot;
int a[maxn], ss, tt;

int get(int u){
	for (int i = 1; i <= tot; ++i)
		if (sz(vec[i]) >= u) return i; else u -= sz(vec[i]);
}

int getPos(int u){
	for (int i = 1; i <= tot; ++i)
		if (sz(vec[i]) >= u) return u - 1; else u -= sz(vec[i]);
}

void rebuild(){
	int tt = 0;
	for (int i = 1; i <= tot; ++i){
		M[i].clear();
		for (int j = 0; j < sz(vec[i]); ++j){
			a[++tt] = vec[i][j];
		}
		vec[i].clear();
	}
	tot = 1;
	for (int i = 1; i <= n; ++i){
		if (sz(vec[tot]) == ss){
			++tot;
		}
		vec[tot].push_back(a[i]);
		if (M[tot].find(a[i]) == M[tot].end()) M[tot][a[i]] = 1; else ++M[tot][a[i]];
	}
}

int main(){
	scanf("%d", &n);
	ss = (int)(sqrt(n) + 1);
	tot = 1;
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		if (sz(vec[tot]) == ss) ++tot;
		vec[tot].push_back(a[i]);
		if (M[tot].find(a[i]) == M[tot].end()) M[tot][a[i]] = 1; else ++M[tot][a[i]];
	}
	int lastAns = 0, Q, calc = 0;
	scanf("%d", &Q);
	for (; Q; --Q){
		int kind, l, r, k;
		scanf("%d", &kind);
		if (kind == 1){
			scanf("%d%d", &l, &r);
			l = (l + lastAns - 1) % n + 1;
			r = (r + lastAns - 1) % n + 1;
			if (l > r) swap(l, r);
			int u = get(l), v = get(r);
			int p1 = getPos(l), p2 = getPos(r);
			int tmp = vec[v][p2];
			for (int i = p2; i < sz(vec[v]) - 1; ++i)
				vec[v][i] = vec[v][i + 1];
			vec[v].pop_back();
			vec[u].push_back(tmp);
			if (M[v].find(tmp) == M[v].end()) M[v][tmp] = -1; else --M[v][tmp];
			for (int i = sz(vec[u]) - 1; i > p1; --i)
				vec[u][i] = vec[u][i - 1];
			vec[u][p1] = tmp;
			if (M[u].find(tmp) == M[u].end()) M[u][tmp] = 1; else ++M[u][tmp];
			++calc;
			if (calc == ss){
				calc == 0;
				rebuild();
			}
		} else {
			scanf("%d%d%d", &l, &r, &k);
			l = (l + lastAns - 1) % n + 1;
			r = (r + lastAns - 1) % n + 1;
			k = (k + lastAns - 1) % n + 1;
			if (l > r) swap(l, r);
			int u = get(l), v = get(r);
			int p1 = getPos(l), p2 = getPos(r);
			lastAns = 0;
			for (int i = u + 1; i < v; ++i)
				if (M[i].find(k) != M[i].end())
					lastAns += M[i][k];
			if (u != v){
				for (int i = p1; i < sz(vec[u]); ++i)
					if (vec[u][i] == k) ++lastAns;
				for (int i = 0; i <= p2; ++i)
					if (vec[v][i] == k) ++lastAns;
			} else {
				for (int i = p1; i <= p2; ++i)
					if (vec[u][i] == k) ++lastAns;
			}
			printf("%d\n", lastAns);
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 100000

typedef long long lint;

using namespace std;

const lint maxv = 100000002;

lint gcd(lint a, lint b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

lint mcm(lint a, lint b)
{
	return a/gcd(a,b)*b;
}

vector <int> adj[MAXN];
lint sum[MAXN], mm[MAXN], nchild[MAXN];
bool failed;

inline bool leaf(int v) {return (v != 0 && adj[v].size() == 1);}

void p1(int v, int parent)
{
	if (leaf(v)) {
		nchild[v] = 0;
		mm[v] = 1;
	} else {
		sum[v] = 0;
		mm[v] = 1;
		nchild[v] = 0;

		for (int i = 0; i < (int)adj[v].size(); i++) {
			int v2 = adj[v][i];
			if (v2 == parent) continue;
			
			p1(v2, v);

			sum[v] += sum[v2];
			mm[v] = mcm(mm[v], mm[v2]);
			if (mm[v] > maxv) failed = true;

			nchild[v] ++;
		}

		mm[v] *= nchild[v];
		if (mm[v] > maxv) failed = true;
	}
}

void p2(int v, int parent)
{
	if (leaf(v)) {
	} else {
		for (int i = 0; i < (int)adj[v].size(); i++) {
			int v2 = adj[v][i];
			if (v2 == parent) continue;

			mm[v2] = mm[v] / nchild[v];

			p2(v2, v);
		}
	}
}

lint p3(int v, int parent)
{
	lint ret = (sum[v] / mm[v]) * mm[v];
	
	for (int i = 0; i < (int)adj[v].size(); i++) {
		int v2 = adj[v][i];
		if (v2 == parent) continue;
		
		ret = min(ret, p3(v2, v) * nchild[v]);
	}
	
	return ret;
}

int main(int argc, char ** argv)
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> sum[i];

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	failed = false;
	p1(0, -1);
	if (!failed)
		p2(0, -1);

	lint ret;

	if (!failed)
		ret = sum[0] - p3(0, -1);

	if (failed)
		ret = sum[0];

	cout << ret << endl;

	return 0;
}
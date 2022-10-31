#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

int n, a[5555], tree[30000], mini[30000];
int minx, minin;

void build(int vl, int vr, int node) {
	if (vl==vr) mini[node]=vl, tree[node]=a[vl];
	else {
		build(vl, (vl+vr)/2, node*2);
		build((vl+vr)/2+1, vr, node*2+1);
		if (tree[node*2]<tree[node*2+1]) tree[node]=tree[node*2], mini[node]=mini[node*2];
		else tree[node]=tree[node*2+1], mini[node]=mini[node*2+1];
	}
}

void getmin(int l, int r, int vl, int vr, int node) {
	if (l>vr||r<vl) return;
	else if (vl>=l&&vr<=r) {if (minx>tree[node]) minx=tree[node], minin=mini[node];}
	else {
		getmin(l, r, vl, (vr+vl)/2, node*2);
		getmin(l, r, (vl+vr)/2+1, vr, node*2+1);
	}
}

int solve (int x, int y, int k)  {
	int ans=0;
	if (x>y) return 0;
	if (x==y) return (a[x]>k);
	minx=2000000000;
	getmin(x, y, 0, n-1, 1);
	int minxx=minx, mininn=minin;
	ans+=minxx-k;
	ans+=solve(x, mininn-1, minxx);
	ans+=solve(mininn+1, y, minxx);
	ans=min(ans, y-x+1);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	build(0, n-1, 1);
	cout << solve(0, n-1, 0);
    return 0;
}
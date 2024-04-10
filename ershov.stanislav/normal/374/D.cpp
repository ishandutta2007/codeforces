#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

struct node {
	node * l, * r;
	int cnt, val, prior;
};

int getcnt(node * v) {
	return v ? v->cnt : 0;
}

void updcnt(node * v) {
	v->cnt=getcnt(v->r)+getcnt(v->l)+1;
}

node * merge(node * a, node * b) {
	if (!a) return b;
	else if (!b) return a;
	else {
		node * t;
		if (a->prior>b->prior) a->r=merge(a->r, b), t=a;
		else b->l=merge(a, b->l), t=b;
		updcnt(t);
		return t;
	}
}
void del(int i, node * & tree) {
	if (!tree||tree->cnt==1) {
		tree=nullptr;
	} else {
		int lcnt=getcnt(tree->l);
		if (lcnt==i-1) tree=merge(tree->l, tree->r);
		else if (lcnt<i-1) del(i-lcnt-1, tree->r);
		else del(i, tree->l);
		updcnt(tree);
	}
}

void print(node * v) {
	if (!v) return;
	print(v->l);
	printf("%d", v->val);
	print(v->r);
}

int n, m, a[1111111];
node * tree;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m;
	for (int i=0; i<m; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++) {
		int b;
		scanf("%d", &b);
		if (b==-1) {
			if (!tree) continue;
			int * i=upper_bound(a, a+m, tree->cnt);
			i--;
			for (;i!=a-1; i--) {
				del(*i, tree);
			}
			
		} else {
			node * n=new node();
			n->prior=(rand()<<16)+rand();
			n->val=b;
			n->cnt=1;
			tree=merge(tree, n);
		}
	}
	if (tree) print(tree);
	else cout << "Poor stack!";
    return 0;
}
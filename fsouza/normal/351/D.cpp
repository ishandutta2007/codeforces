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
#define MAXM 100005

typedef long long lint;

using namespace std;

int b[MAXM];
int next[MAXM];
int until[MAXM];

struct node {
	int ndiff;
	int ngood;
	node() {ndiff = 0; ngood = 0;}
	node(const node& n1, const node& n2) {
		ndiff = n1.ndiff + n2.ndiff;
		ngood = n1.ngood + n2.ngood;
	}
} tree[4*MAXM];

node tree_query(int a, int b, int n, int l, int r)
{
	if (a > r || b < l) return node();
	if (a <= l && r <= b) return tree[n];

	int m = (l+r)/2;

	return node(tree_query(a, b, 2*n+1, l, m),
		    tree_query(a, b, 2*n+2, m+1, r));
}

void tree_update2(int pos, int v, int n, int l, int r)
{
	tree[n].ngood += v;
	
	if (l != r) {
		int m = (l+r)/2;
		if (pos <= m) tree_update2(pos, v, 2*n+1, l, m);
		else tree_update2(pos, v, 2*n+2, m+1, r);
	}
}

void tree_update(int pos, int v, int n, int l, int r)
{
	tree[n].ndiff += v;
	
	if (l != r) {
		int m = (l+r)/2;
		if (pos <= m) tree_update(pos, v, 2*n+1, l, m);
		else tree_update(pos, v, 2*n+2, m+1, r);
	}
}


int main(int argc, char ** argv)
{
	int m;

	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	memset(tree, 0, sizeof(tree));

	map <int, int> id;

	for (int i = m-1; i >= 0; i--) {
		if (id.find(b[i]) == id.end())
			next[i] = m;
		else
			next[i] = id[b[i]];
		id[b[i]] = i;

		until[i] = i;
		if (next[i] != m) {
			until[i] = next[i];
			if (next[next[i]] != m && next[next[i]] - next[i] == next[i] - i)
				until[i] = until[next[i]];
		}
	}

	int nq;

	scanf("%d", &nq);
	
	vector <pair<pair <int, int>, int> > q;
	vector <int> ret(nq, 0);

	for (int i = 0; i < nq; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		q.push_back(make_pair(make_pair(l, r), i));
	}

	sort(q.rbegin(), q.rend());

	map <int, vector <pair <int, int> > > put;

	int lastl = m;
	for (int i = 0; i < nq; i++) {
		int l = q[i].first.first, r = q[i].first.second, qid = q[i].second;

		while (lastl > l) {
			lastl --;
			{
				int p = lastl;
				if (next[p] != m)
					tree_update(next[p], -1, 0, 0, m-1);
				tree_update(p, 1, 0, 0, m-1);

				vector <pair <int, int> >& bla = put[b[p]];

				for (int k = 0; k < (int)bla.size(); k++)
					tree_update2(bla[k].first, bla[k].second, 0, 0, m-1);
				bla.clear();

				
				tree_update2(p, 1, 0, 0, m-1);
				bla.push_back(make_pair(p, -1));

				if (next[until[p]] != m) {
					tree_update2(next[until[p]], -1, 0, 0, m-1);
					bla.push_back(make_pair(next[until[p]], +1));
				}
					
			}
		}

		node x = tree_query(l, r, 0, 0, m-1);

		ret[qid] = 1 + x.ndiff - (x.ngood != 0);
	}

	for (int i = 0; i < nq; i++)
		printf("%d\n", ret[i]);

	return 0;
}
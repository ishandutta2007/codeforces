#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 100005;

int n;
long long a[MAXN];
long long b[MAXN];
int c[2][2];

struct Node
{
	long long ans,sum,cnt;
	long long left[2][2];
	long long right[2][2];
}node[MAXN * 4];

void push_up(int o)
{
	Node l = node[o << 1],r = node[(o << 1) + 1];
	node[o].cnt = l.cnt + r.cnt;
	if (l.cnt & 1)
		node[o].sum = l.sum - r.sum;
	else
		node[o].sum = l.sum + r.sum;
	if (l.cnt & 1)
	{
		node[o].left[0][0] = max(l.left[0][0],l.sum - r.left[1][1]);
		node[o].left[0][1] = min(l.left[0][1],l.sum - r.left[1][0]);
		node[o].left[1][0] = max(l.left[1][0],l.sum - r.left[0][1]);
		node[o].left[1][1] = min(l.left[1][1],l.sum - r.left[0][0]);
	}
	else
	{
		node[o].left[0][0] = max(l.left[0][0],l.sum + r.left[0][0]);
		node[o].left[0][1] = min(l.left[0][1],l.sum + r.left[0][1]);
		node[o].left[1][0] = max(l.left[1][0],l.sum + r.left[1][0]);
		node[o].left[1][1] = min(l.left[1][1],l.sum + r.left[1][1]);
	}
	if (r.cnt & 1)
	{
		node[o].right[0][0] = max(r.right[0][0],l.right[1][0] - r.sum);
		node[o].right[0][1] = min(r.right[0][1],l.right[1][1] - r.sum);
		node[o].right[1][0] = max(r.right[1][0],l.right[0][0] + r.sum);
		node[o].right[1][1] = min(r.right[1][1],l.right[0][1] + r.sum);
	}
	else
	{
		node[o].right[0][0] = max(r.right[0][0],l.right[0][0] + r.sum);
		node[o].right[0][1] = min(r.right[0][1],l.right[0][1] + r.sum);
		node[o].right[1][0] = max(r.right[1][0],l.right[1][0] - r.sum);
		node[o].right[1][1] = min(r.right[1][1],l.right[1][1] - r.sum);
	}
	node[o].ans = max(node[o].ans,max(l.ans,r.ans));
	node[o].ans = max(node[o].ans,max(l.right[0][0] + r.left[0][0],l.right[0][0] + r.left[1][0]));
	node[o].ans = max(node[o].ans,max(l.right[1][0] - r.left[0][1],l.right[1][0] - r.left[1][1]));
}

void build_tree(int o,int l,int r)
{
	if (l == r)
	{
		node[o].ans = node[o].sum = b[l];
		node[o].cnt = 1;
		node[o].left[0][0] = node[o].left[0][1] = 0;
		node[o].left[1][0] = node[o].left[1][1] = b[l];
		node[o].right[0][0] = node[o].right[0][1] = 0;
		node[o].right[1][0] = node[o].right[1][1] = b[l];
		return;
	}
	int mid = (l + r) >> 1;
	build_tree(o << 1,l,mid);
	build_tree((o << 1) + 1,mid + 1,r);
	push_up(o);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i < n;i++)
		b[i] = abs(a[i] - a[i + 1]);
	n--;
	build_tree(1,1,n);
	cout << node[1].ans << endl;
	return 0;
}
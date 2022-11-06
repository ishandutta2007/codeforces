#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
struct node {
	int cnt, laz;
	node *ch[2];
}pn[6300000], *root;
int n, m, nT;
set<int> S;
void ins (int a) {
	if (S.find(a) != S.end()) return;
	S.insert(a);
	node *p = root; p->cnt++;
	for (int i = 20; ~i; i--) {
		int k = (a >> i) & 1;
		if(!p->ch[k]) p->ch[k] = &pn[nT++];
		p = p->ch[k];
		p->cnt++;
	}
}
inline int siz (node *p) {return p ? p->cnt : 0;}
void push_down (node *p, int d) {
	if (p->ch[0]) p->ch[0]->laz ^= p->laz;
	if (p->ch[1]) p->ch[1]->laz ^= p->laz;
	if ((p->laz >> d) & 1)
		swap(p->ch[0], p->ch[1]);
	p->laz = 0;
}
int mex(){
	int ret = 0;
	node *p = root;
	for (int d = 20; ~d; d--) {
		if (!p) break;
		push_down(p, d);
		if (siz(p->ch[0]) != (1 << d))
			p = p->ch[0];
		else
			p = p->ch[1], ret |= (1 << d);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	root = &pn[nT++];
	cin>>n>>m;
	int a;
	while (n--) {
		cin >> a; ins(a);
	}
	while (m--) {
		cin >> a;
		root->laz ^= a;
		cout << mex() << endl;
	}
	return 0;
}
#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "movetofront"


const int INF = int(1e9);
const int INFll = int(1e9) + 7;
const int SZ = 70;

using namespace std;

struct V;

typedef V *pV;




struct V{
	static pV null;
	pV l, r;
	int key, val, sz, num, ind;
	V(): l(this), r(this), key(rand()), val(INFll), sz(0), num(0){}
	V(int x): l(null), r(null), key(rand()), val(x), sz(1), num(0){}
	V(int x, int ind): l(null), r(null), key(rand()), val(x), sz(1), num(0), ind(ind){}
	void update(){
		sz = 1 + l->sz + r->sz;
	}
};

pV V::null = new V();


int ans[1000005], used[1000005];

void Print(pV T){
	if (T == V::null) return;
	Print(T->l);
	ans[T->ind] = T->num;
	Print(T->r);
}

void Merge(pV &T, pV l, pV r){
	if (l == V::null){
		T = r;
	} else if (r == V::null){
		T = l;
	} else if (l->key < r->key) {
		Merge(l->r, l->r, r);
		T = l;
		T->update();
	} else {
		Merge(r->l, l, r->l);
		T = r;
		T->update();
	}
}

void Split(pV T, pV &l, pV &r, int x){
	if (T == V::null){
		l = T;
		r = T;
	} else if (T->l->sz >= x){
		Split(T->l, l, T->l, x);
		r = T;
		r->update();
	} else {
		Split(T->r, T->r, r, x - T->l->sz - 1);
		l = T;
		l->update();
	}
}

void Insert(pV &T, int x, int val, int ind){
	pV l, r, g;
	Split(T, l, r, x);
	Merge(l, l, new V(val, ind));
	Merge(T, l, r);
}

void Change(pV &T, int x, int y){
	pV l, r, g, f;
	Split(T, l, r, y);
	Split(l, g, f, y - 1);
	if ((f->num && f->num != x) || (used[x] && !f->num)){
		printf("-1\n");
		exit(0);
	}
	used[x] = 1;
	f->num = x;
	Merge(l, f, g);
	Merge(T, l, r);
}


int n, sz = 0, m;
pV root, tt;

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	scanf("%d%d", &n, &m);
	root = V::null;
	for (int i = 0; i < n; i++){
		Insert(root, i + 1, i + 1, i);
	}
	for (int i = 0; i < m; i++){
		int x, y; scanf("%d%d", &x, &y);
		Change(root, x, y);
	}
	Print(root); 
	int tmp = 1;
	for (int i = 0; i < n; i++){
		if (!ans[i]){
			while (used[tmp]) tmp++;
			printf("%d ", tmp);
			tmp++;
		}
		else printf("%d ", ans[i]);
	}
}
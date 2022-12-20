#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
const int N = 110000;

int id[N];

void gao(int n){
	for (int i=0; i<n; ++i) id[i] = i + 1;
	random_shuffle(id, id+n);
	id[n] = id[0];
}

set<pair<int, int> > s;
bool fun(int v, int e){
	gao(v);
	int cnt = 0;
	for (int i=0; i<v; ++i) if (s.find(make_pair(id[i], id[i+1])) == s.end()) cnt ++;
	if (cnt < e) return false;
	cnt = e;
	for (int i=0; i<v && cnt; ++i) if (s.find(make_pair(id[i], id[i+1])) == s.end()) {
		cnt --;
		printf("%d %d\n", id[i], id[i+1]);
	}
	return true;
}

int main(){
	int v, e, a, b;
	cin >> v >> e;
	for (int i=0; i<e; ++i){
		cin >> a >> b;
		s.insert(make_pair(a, b));
		s.insert(make_pair(b, a));
	}

	for (int i=0; i<100; ++i){
		if (fun(v, e)) return 0;
	}
	puts("-1");
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;
char l[200020], r[200020];
vector<int> nl, nr, ql, qr, occl[26], occr[26];
vector<pair<int, int>> ans;

int main() {
	scanf("%d %s %s", &n, l, r);
	for(int i = 0; i < n; i++) {
		if(l[i] == '?') ql.push_back(i+1);
		else occl[l[i]-'a'].push_back(i+1);
	}
	for(int i = 0; i < n; i++) {
		if(r[i] == '?') qr.push_back(i+1);
		else occr[r[i]-'a'].push_back(i+1);
	}
	for(int i = 0; i < 26; i++) {
		while(!occl[i].empty() && !occr[i].empty()) {
			ans.emplace_back(occl[i].back(), occr[i].back());
			occl[i].pop_back();
			occr[i].pop_back();
		}
		while(!occl[i].empty()) {
			nl.push_back(occl[i].back());
			occl[i].pop_back();
		}
		while(!occr[i].empty()) {
			nr.push_back(occr[i].back());
			occr[i].pop_back();
		}
	}
	while(!ql.empty() && !nr.empty()) {
		ans.emplace_back(ql.back(), nr.back());
		ql.pop_back();
		nr.pop_back();
	}
	while(!nl.empty() && !qr.empty()) {
		ans.emplace_back(nl.back(), qr.back());
		nl.pop_back();
		qr.pop_back();
	}
	while(!ql.empty() && !qr.empty()) {
		ans.emplace_back(ql.back(), qr.back());
		ql.pop_back();
		qr.pop_back();
	}
	
	printf("%d\n", ans.size());
	for(auto p : ans) printf("%d %d\n", p.first, p.second);
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &p){
	return (p[x] == x)?x:(p[x] = find(p[x], p));
}

void merge(int x, int y, vector<int> &p){
	x = find(x, p);
	y = find(y, p);
	p[max(x, y)] = min(x, y);
}

void solve(){
	int n, k;
	string s;
	cin >> n;
	cin >> k;
	cin >> s;
	vector<int> p(26);
	iota(p.begin(), p.end(), 0);
	for(int i = 0; i < n; i++){
		int c = s[i] - 'a';
		while(k > 0 && find(c, p) > 0){
			merge(find(c, p) - 1, find(c, p), p); k--;
		}
		cout << char(find(c, p) + 'a');
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}
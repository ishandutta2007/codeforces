#include <bits/stdc++.h>
using namespace std;

vector <string> ans;
int mask;

void go(const string &s, int pos, int dep, string r){
	if (dep == 4){
		if (pos == s.length()) ans.push_back(r.substr(1));
		return ;
	}
	for (int l = 1; l <= 3 && pos + 1 <= s.length(); l++){
		if (l > 1 && s[pos] == '0') continue;
		int x = 0;
		for (int i = 0; i < l; i++){
			x = x * 10 + s[pos + i] - '0';
		}
		if (x > 255) continue;
		go(s, pos + l, dep + 1, r + "." + s.substr(pos, l));
	}
}

void check(const char* s){
	go(s, 0, 0, "");
}

void gen(string cur, int pos, const string &al){
	if (pos == al.length()){
		sort(cur.begin(), cur.end());
		do{
			string d = cur;
			reverse(d.begin(), d.end());
			check((cur + d).c_str());
			check((cur + d.substr(1)).c_str());
		}while (next_permutation(cur.begin(), cur.end()));
		return ;
	}
	for (int l = 0; cur.length() <= 6; l++){
		gen(cur, pos + 1, al);
		cur += al[pos];
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	stringstream ss;
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		mask |= 1 << x;
		ss << x;
	}
	string al = ss.str();
	if (al.length() <= 6) gen(al, 0, al);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%s\n", ans[i].c_str());
	}
}

int main(){
	solve();
	return 0;
}
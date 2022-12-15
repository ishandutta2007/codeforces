#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 6e6, sigma = 2;
int trie[ms][sigma], qnt[ms], z;

string toBinary(int n) {
	string s;
	for(int i = 30; i >= 0; i--){
		s.push_back(((n >> i) & 1) + '0');
		//cout << s << '\n';
	}
	return s;
}

int get_id(char c) {
	return c - '0';
}

int toDecimal(string p) {
	int n = 0;
	for(int i = 30, pos = 0; i >= 0; i--, pos++) {
		n += get_id(p[pos]) * (1 << i);
	}
	return n;
}


void insert(int n) {
	string p = toBinary(n);
	int cur = 0;
	for(int i = 0; i < p.size(); i++) {
		int id = get_id(p[i]);
		if(trie[cur][id] == -1) {
			memset(trie[z], -1, sizeof trie[z]);
			trie[cur][id] = z++;
		}
		cur = trie[cur][id];
		qnt[cur]++;
	}
}

void remove(int n) {
	string p = toBinary(n);
	int cur = 0;
	for(int i = 0; i < p.size(); i++) {
		cur = trie[cur][get_id(p[i])];
		qnt[cur]--;
	}
}

int search(int n) {
	string p = toBinary(n);
	string ans;
	int cur = 0;
	for(int i = 0; i < p.size(); i++) {
		int id = get_id(p[i]);
		if(trie[cur][!id] == -1 || qnt[trie[cur][!id]] == 0) {
			ans.push_back('0');
			cur = trie[cur][id];
		} else {
			ans.push_back('1');
			cur = trie[cur][!id];
		}
	}
	return toDecimal(ans);
}

void init() {
	memset(trie[0], -1, sizeof trie[0]);
	z = 1;
	insert(0);
}

int main(){
	int q;
	cin >> q;
	init();
	for(int i = 0; i < q; i++) {
		string s;
		int n;
		cin >> s >> n;
		//cout << toBinary(n) << '\n';
		//cout << toDecimal(toBinary(n)) << '\n';
		if(s == "+") insert(n);
		else if(s == "-") remove(n);
		else cout << search(n) << '\n';
	}
	return 0;
}
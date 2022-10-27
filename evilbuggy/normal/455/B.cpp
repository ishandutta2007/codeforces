#include <bits/stdc++.h>
using namespace std;

const int maxk = 26;
const int maxn = 100005;

int ptr, trie[maxn][maxk];

inline void insert(string s){
	int root = 0;
	for(int i = 0; i < (int)s.size(); i++){
		int ch = s[i] - 'a';
		if(trie[root][ch] == -1){
			trie[root][ch] = ptr++;
		}
		root = trie[root][ch];
	}
}

int canwin(int v){
	for(int i = 0; i < maxk; i++){
		if(trie[v][i] == -1)continue;
		if(!canwin(trie[v][i]))return 1;
	}
	return 0;
}

int canlos(int v){
	bool leaf = true;
	for(int i = 0; i < maxk; i++){
		if(trie[v][i] == -1)continue; leaf = false;
		if(!canlos(trie[v][i]))return 1;
	}
	if(leaf)return 1;
	return 0;
}

inline void init(){
	ptr = 1;
	memset(trie, -1, sizeof(trie));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	int n; cin >> n;
	int k; cin >> k;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		insert(s);
	}
	if(!canwin(0)){
		cout << "Second" << '\n';
	}else if(canlos(0)){
		cout << "First" << '\n';
	}else if(k&1){
		cout << "First" << '\n';
	}else{
		cout << "Second" << '\n';
	}

	return 0;
}
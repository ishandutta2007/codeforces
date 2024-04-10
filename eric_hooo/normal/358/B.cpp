#include <bits/stdc++.h>
using namespace std;

string a[100010];
string s;
char buf[100010];
string ppp = "<3";

string read(){
	scanf("%s", buf);
	return buf;
}

int get_pos(string &t, int pos){
	int j = 0;
	for (int i = pos; i < s.length(); i++){
		if (s[i] == t[j]){
			j++;
			if (j == t.length()) return i + 1;
		}
	}
	return -1;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		a[i] = read();
	}
	s = read();
	int pos = get_pos(ppp, 0);
	if (pos == -1){
		printf("no\n");
		return 0;
	}
	for (int i = 0; i < n; i++){
		pos = get_pos(a[i], pos);
		if (pos == -1){
			printf("no\n");
			return 0;
		}
		pos = get_pos(ppp, pos);
		if (pos == -1){
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
	return 0;
}
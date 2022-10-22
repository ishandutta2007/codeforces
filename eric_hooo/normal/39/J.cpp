#include <bits/stdc++.h>
using namespace std;

char buf[1000010];
string s, t;

string read(){
	scanf("%s", buf);
	return buf;
}

int main(){
	s = read(), t = read();
	int r, l;
	for (r = 0; r < t.length(); r++){
		if (s[r] != t[r]) break;
	}
	for (l = t.length() - 1; l >= 0; l--){
		if (s[l + 1] != t[l]) break;
	}
	l++;
	if (l > r){
		printf("0\n");
		return 0;
	}
	printf("%d\n", r - l + 1);
	for (int i = l; i <= r; i++){
		printf("%d ", i + 1);
	}
	printf("\n");
	return 0;
}
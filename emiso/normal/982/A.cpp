#include <bits/stdc++.h>

using namespace std;

int n;
char s[1010];
string str;

int main() {
	int f = 1;
	scanf("%d %s", &n, s);
	
	str = "0";
	str += s;
	str += "0";
	
	for(int i = 1; i <= n; i++) {
		if(str[i] == '0') {
			if(str[i-1] == '0' && str[i+1] == '0') f = 0;
		} else if(str[i] == '1') {
			if(str[i-1] == '1' || str[i+1] == '1') f = 0;
		} else assert(false);
	}
	
	printf("%s\n", f ? "Yes" : "No");
	
	return 0;
}
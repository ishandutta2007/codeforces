#include <bits/stdc++.h>
using namespace std;

char buf[1000010];
int z[1000010];
string s;

void get_z(string s){
	int n = s.length();
	int L = 0, R = 0;
	for (int i = 1; i < s.length(); i++){
		if (R < i){
			L = R = i;
			while (R < n && s[R - L] == s[R]) R++;
			z[i] = R - L, R--;
			continue;
		}
		int pos = i - L;
		if (z[pos] + i < R){
			z[i] = z[pos];
			continue;
		}
		L = i;
		while (R < n && s[R - L] == s[R]) R++;
		z[i] = R - L, R--;
	}
}

int main(){
	scanf("%s", buf), s = buf;
	int n = s.length();
	get_z(s);
	int maxj = 0;
	for (int i = 1; i < n; i++){
		if (z[i] == n - i && maxj >= n - i){
			printf("%s\n", s.substr(0, z[i]).c_str());
			return 0;
		}
		maxj = max(maxj, z[i]);
	}
	printf("Just a legend\n");
	return 0;
}
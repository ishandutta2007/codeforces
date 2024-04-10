#include <bits/stdc++.h>

 
char s[110000];

void solve() {
	scanf("%s", s);

	int n = strlen(s);

	bool found = false;
	for (int i = 0; i < n && !found; i++) {
		if (s[i] != 'a') {
			for (int j = i; j < n; j++) {
				if (s[j]=='a') break;
				s[j]--;
			}
			found = true;
		}
	}	

	if (!found) s[n-1] = 'z';
	printf("%s\n", s);
}


int main() {
    solve();
}
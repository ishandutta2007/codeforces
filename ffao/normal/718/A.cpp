#include <stdio.h>
#include <bits/stdc++.h>

 
#include <vector>
#include <utility>


#include <algorithm>


int n, t;
char s[310000];

void solve() {
	scanf("%d %d %s", &n, &t, s);

	int dec_loc = -1;
	for (int i = 0; i < n; i++) if (s[i]=='.') dec_loc = i;

	for (int i = dec_loc+1; i < n; i++) {
		if (s[i] != '.' && s[i] >= '5') {
			for (int j = i; j < n; j++) s[j]='0';

			for (int j = i-1; j >= 0; j--) {
				if (s[j] != '.') {
					s[j]++;
					if (s[j] == '9'+1) s[j]='0';
					else break;
				}
			}

			t--;
			for (int j = i-1; j > dec_loc && t; j--) {
				if (s[j] != '.') {
					if (s[j] < '5') break;
					if (s[j] >= '5') s[j] = '0';

				} 

				t--;
				for (int k = j-1; k >= 0; k--) {
					if (s[k] != '.') {
						s[k]++;
						if (s[k] == '9'+1) s[k]='0';
						else break;
					}
				}
			}
		}
	}

	for (int i = n-1; i >= 0; i--) {
		if (s[i] != '.' && s[i] != '0') {
			s[i+1] = 0;
			break;
		}
		if (s[i] == '.') {
			s[i] = 0;
			break;
		}
	}

	if (s[0]=='0' && s[dec_loc]==0) printf("1");
	printf("%s\n", s);
}


int main() {
    solve();
}
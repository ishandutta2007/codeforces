#include <bits/stdc++.h>
using namespace std;

int n, k;
char s[1000010];
int fail[1000010];
int f[1000010][22];

void get_fail(){
	fail[1] = 0;
	int j = 0;
	for (int i = 2; i <= n; i++){
		while (j && s[i] != s[j + 1]) j = fail[j];
		if (s[i] == s[j + 1]) j++;
		fail[i] = j;
	}
}

void get_f(){
	for (int i = 1; i <= n; i++){
		f[i][0] = fail[i];
	}
	for (int j = 1; j < 22; j++){
		for (int i = 1; i <= n; i++){
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	get_fail(), get_f();
	for (int i = 1; i <= n; i++){
		int left = ((k - 1ll) * i + k - 1) / k;
		int right = (1ll * k * i) / (k + 1);
		int now = i;
		for (int j = 21; j >= 0; j--){
			if (f[now][j] > right) now = f[now][j];
		}
		now = f[now][0];
		putchar(now >= left && now <= right ? '1' : '0');
	}
	putchar('\n');
	return 0;
}
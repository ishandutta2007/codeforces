#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;

int cnt[26][maxn];
char s[maxn];
int main() {
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for (int i = 1; i <= l; i++) {
		for (int j = 0; j < 26; j++)	
			cnt[j][i] = cnt[j][i - 1];
		cnt[s[i] - 'a'][i]++;
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (r == l) printf("Yes\n");
		else {
			if (s[l] != s[r]) {
				printf("Yes\n");
			}
			else {
				int tot = 0;
				for (int j = 0; j < 26; j++)
					if (cnt[j][r] != cnt[j][l - 1]) tot++;
				if (tot <= 2) printf("No\n");
				else printf("Yes\n");
			}
		}
	}
	return 0;
}
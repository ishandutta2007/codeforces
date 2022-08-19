#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
char inp[maxn];
int fl[maxn];
int main() {
	scanf("%s", inp);
	int l = strlen(inp);
	for (int i = l - 1; i >= 0; i--)
		fl[inp[i] - 'a'] = i + 1;
	int cs = -1;
	for (int j = 0; j < 26; j++)
		if (!fl[j]) break;
		else cs = j;
	for (int j = 25; j > cs; j--) {
		if (fl[j]) {
			printf("NO\n");
			return 0;
		}
	} 
	for (int j = 0; j <= cs - 1; j++)
		if (fl[j] > fl[j + 1]) {
			cout << "NO" << endl;
			return 0;
		}
	printf("YES\n");
	return 0;
}
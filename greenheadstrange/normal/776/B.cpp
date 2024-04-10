#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
bool bpr[maxn];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < maxn; i++) bpr[i] = 1;
	for (int i = 2; i <= n + 1; i++)
		for (int j = 2; j * i <= n + 1; j++)
			bpr[j * i
			] = 0;
	if (n <= 2) cout << 1 << endl;
	else cout << 2 << endl;
	for (int i = 2; i <= n + 1; i++)
		if (bpr[i]) printf("1 ");
		else printf("2 ");
	return 0;
}
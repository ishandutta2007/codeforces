#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
char inp[maxn];
int fl[maxn];
int main() {
	int n;
	cin >> n;
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int nc = 0;
		if (x1 % 2) nc += 2;
		if (y1 % 2) nc ++;
		printf("%d\n", nc + 1);
	}
 	return 0;
}
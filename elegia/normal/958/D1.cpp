#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

const int maxn = 200001;
map < pair<int, int>, int > cnt;
pair<int, int> ans[maxn];

int gcd(int a, int b);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char str[15];
		scanf("%s", str);
		int len = strlen(str);
		int top = 1;
		int a, b, c;
		sscanf(str+top, "%d", &a);
		if (a >= 10) top += 3;
		else top += 2;
		sscanf(str+top, "%d", &b);
		if (b >= 10) top += 4;
		else top += 3;
		sscanf(str+top, "%d", &c);
		int g = gcd(a + b, c);
		cnt[make_pair((a + b) / g, c / g)]++;
		ans[i] = make_pair((a + b) / g, c / g);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", cnt[ans[i]]);
	}
	return 0;
}

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}
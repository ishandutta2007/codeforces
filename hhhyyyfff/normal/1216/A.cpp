#include <cstdio>
#include <cstdlib>

using namespace std;

//------------------------------------OI----------------------------------------

char s[200010];
int n, ans;

int main() {
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; i += 2)
		if (s[i] == s[i + 1]) {
			s[i] = 'a';
			s[i + 1] = 'b';
			++ans;
		}
	printf("%d\n%s\n", ans, s);
	return 0;
}
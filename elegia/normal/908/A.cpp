#include <cstdio>

using namespace std;

char s[110];
bool ch[256];

int main() {
	ch['a'] = true;
	ch['e'] = true;
	ch['i'] = true;
	ch['o'] = true;
	ch['u'] = true;
	for (int i = 1; i < 10; i += 2)
		ch[i + '0'] = true;
	scanf("%s", s);
	int ans = 0;
	for (char* p = s; *p; ++p)
		ans += ch[*p];
	printf("%d\n", ans);
	return 0;
}
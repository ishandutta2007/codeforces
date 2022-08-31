#include <cstdio>

using namespace std;

typedef long long ll;

char s[6];

bool isPal() {
	return s[0] == s[4] && s[1] == s[3];
}

int main() {
	scanf("%s", s);
	for (int i = 0; i < 5; ++i)
		s[i] -= '0';
	int cnt = 0;
	while (!isPal()) {
		++cnt;
		if (++s[4] != 10)
			continue;
		s[4] = 0;
		if (++s[3] != 6)
			continue;
		s[3] = 0;
		if (s[0] == 2 && s[1] == 3) {
			s[0] = s[1] = 0;
			continue;
		}
		if (++s[1] != 10)
			continue;
		s[1] = 0;
		++s[0];
	}
	printf("%d\n", cnt);
	return 0;
}
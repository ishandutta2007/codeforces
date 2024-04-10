#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int ans = 0;
	int q = 0;
	char buf[200];
	while (true) {
		buf[0] = 0;
		gets(buf);
		if (buf[0] == 0)
			break;
		int l = strlen(buf);
		if (buf[0] == '+')
			q++;
		else if (buf[0] == '-')
			q--;
		else
			ans += q * (l - 1 - (find(buf, buf + l, ':') - buf));
	}
	printf("%d\n", ans);
}
// Print n binary strings with respective given lengths such that
// no string is a prefix of another.

#include <cstdio>
using namespace std;
const int N = 1001;
char res[N][N];
int q[N][N], magic[N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		q[x][q[0][x]++] = i;
	}
	for (int i = 1; i <= 1000; ++i)
		while (q[0][i]--) {
			if (magic[0]) {
				printf("NO");
				return 0;
			}
			res[q[i][q[0][i]]][i] = '\0';
			for (int j = 0; j < i; ++j)
				res[q[i][q[0][i]]][j] = '0' + magic[j + 1];
			for (int j = i; j >= 0; --j)
				if (magic[j] ^= 1) break;
		}
	printf("YES");
	for (int i = 0; i < n; ++i)
		printf("\n%s", res[i]);
}
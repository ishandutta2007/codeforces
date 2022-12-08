#include <cstdio>
#include <cstring>

using namespace std;

char s[150010];
int t, r;

bool isone(int x, int y, int z) {
	return s[x] == 'o' && s[y] == 'n' && s[z] == 'e';
}

bool istwo(int x, int y, int z) {
	return s[x] == 't' && s[y] == 'w' && s[z] == 'o';
}

int main() {
    scanf("%d", &t);
    while (t--) {
    	scanf("%s", s);
    	if (strlen(s) < 3) {
    		puts("0");
    		puts("");
    		continue;
		}
		r = 0;
    	for (int i = 0; s[i + 2] != '\0'; ++i) {
    		if (isone(i, i + 1, i + 2)) {
    			s[++i] = '-';
    			++r;
			}
			if (istwo(i, i + 1, i + 2)) {
				if (isone(i + 2, i + 3, i + 4)) {
					s[i += 2] = '-';
				} else {
					s[++i] = '-';
				}
				++r;
			}
		}
		printf("%d\n", r);
		for (int i = 0, f = 0; s[i] != '\0'; ++i) {
			if (s[i] == '-') {
				if (f) {
					putchar(' ');
				} else {
					f = 1;
				}
				printf("%d", i + 1);
			}
		}
		puts("");
    }
    return 0;
}
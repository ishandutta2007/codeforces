#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 105;

int n;

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		n = strlen(s);
		printf("%d\n", n);
	}	
	return 0;
}
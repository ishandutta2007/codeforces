#include <cstdio>

#include <algorithm>

using namespace std;


const int N = 1300;


int n, m;

char s[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i)
		s[i] = '4';
	s[n] = '5';
	puts(s + 1);
	for (int i = 1; i < n; ++i)
		s[i] = '5';
	puts(s + 1);
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, cnt;
char s[N];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n && s[i] == '<'; i ++) cnt ++;
	for (int i = n - 1; ~i && s[i] == '>'; i --) cnt ++;
	printf("%d\n", cnt);
	return 0;
}
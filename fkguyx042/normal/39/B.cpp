#include <stdio.h>
#include <vector>

using namespace std;

#define FOR(i, x) for (int i = 0; i < (int)(x); i++)
typedef vector<int> vi;
int n;
int a[10000];


int main()
{
	scanf("%d", &n);
	FOR(i, n)
		scanf("%d", &a[i]);
	vi v;
	FOR(i, n)
	{
		if (a[i] == v.size() + 1)
		{
			v.push_back(2000 + i + 1);
		}
	}
	printf("%d\n", v.size());
	FOR(i, v.size())
	{
		if (i) printf(" ");
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}
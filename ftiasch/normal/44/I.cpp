#include <cstdio>
#include <vector>
#include <cstring>
#define ans(x) ans[(x)&1]
#define cans(x) cans[(x)&1]
using namespace std;

struct Tproject {
	int cSet;
	vector<int> set[20];
} ans[2][120000];

int cans[20];
int n;

int main()
{
	cans[1] = 1;
	ans[1][1].cSet = 1;
	ans[1][1].set[1].push_back(1);
	scanf("%d", &n);
	for (int ID = 2; ID <= n; ++ID) {
		cans(ID) = 0;
		memset(ans(ID), 0, sizeof(ans(ID)));
		for (int i = 1; i <= cans(ID - 1); ++i) {
			if (i & 1) for (int j = 1; j <= ans(ID - 1)[i].cSet + 1; ++j) {
				ans(ID)[++cans(ID)] = ans(ID - 1)[i];
				ans(ID)[cans(ID)].set[j].push_back(ID);
				if (j == ans(ID - 1)[i].cSet + 1) ++ans(ID)[cans(ID)].cSet;
			} else for (int j = ans(ID - 1)[i].cSet + 1; j >= 1; --j) {
				ans(ID)[++cans(ID)] = ans(ID - 1)[i];
				ans(ID)[cans(ID)].set[j].push_back(ID);
				if (j == ans(ID - 1)[i].cSet + 1) ++ans(ID)[cans(ID)].cSet;
			}
		}
	}
	printf("%d\n", cans(n));
	for (int i = 1; i <= cans(n); ++i) {
		for (int j = 1; j <= ans(n)[i].cSet; ++j) {
			printf("{");
			for (int k = 0; k < ans(n)[i].set[j].size(); ++k) {
				printf("%d", ans(n)[i].set[j][k]);
				if (k != ans(n)[i].set[j].size() - 1) printf(",");
			}
			printf("}");
			if (j != ans(n)[i].cSet) printf(",");
		}
		printf("\n");
	}
}
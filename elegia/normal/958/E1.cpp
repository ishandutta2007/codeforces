#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 200010;


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	puts(n == m ? "Yes" : "No");
	return 0;
}
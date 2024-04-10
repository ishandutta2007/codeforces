#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <unordered_map>

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, k;
int pw;
const int mod = 1000000007;

int pd[2][110][111100];
int x[210];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	sort(x,x+n);

	for (int d = 0; d <= k; d++) {
		pd[1][0][d+100000] = 1;
	}

	int vidx = 0;
	for (int i = n-1; i >= 1; i--, vidx^=1) {
		//printf("%d\n", pd[vidx^1][0][50000]);
		for (int o = 0; o+i <= n && o <= i; o++) {
			int mind = 0;
			if (i > 0) mind = -x[i-1] * o;

			int maxd = k - x[i] * o;

			for (int d = mind; d <= maxd; d++) {
				int didx = d + 100000;
				pd[vidx][o][didx] = pd[vidx^1][o+1][didx-x[i]];
				if (d + x[i] <= k)
					if (o) pd[vidx][o][didx] = (pd[vidx][o][didx] + o * 1ll * pd[vidx^1][o-1][didx+x[i]]) % mod;
			
				pd[vidx][o][didx] = (pd[vidx][o][didx] + (o+1) * 1ll * pd[vidx^1][o][didx]) % mod;
				//printf("pd[%d][%d][%d] = %d\n", i, o, d, pd[vidx][o][didx]);
			}
			for (int d = maxd+1; d <= k; d++) pd[vidx][o][d+100000] = 0;
		}
	}

	int ans = pd[vidx^1][0][100000];
	ans = (ans + pd[vidx^1][1][100000-x[0]]) % mod;
	printf("%d\n", ans);
}
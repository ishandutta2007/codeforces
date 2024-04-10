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

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, m, b;

pii beac[1100000];
int kill[1100000];
char s[5100];
map< pair<int,int>, int> cnt;

int main() {
	scanf("%d", &n);
	scanf("%s", s);

	cnt[{0,0}] = 1;
	int ans = 0;
	int ud = 0;
	int lr = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') ud++;
		else if (s[i] == 'D') ud--;
		else if (s[i] == 'L') lr++;
		else if (s[i] == 'R') lr--;

		ans += (cnt[{ud, lr}]++);
	}

	printf("%d\n", ans);
}
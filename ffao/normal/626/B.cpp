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

int p[211][211][211];
int n;
char s[1001];
int cnt[3];

int rec(int b, int g, int r) {
	if (b+g+r == 1) {
		if (b == 1) return 1;
		else if (g == 1) return 2;
		return 4;
	}

	int &ret = p[b][g][r];
	if (ret == -1) {
		ret = 0;

		if (b > 1) ret |= rec(b-1,g,r);
		if (g > 1) ret |= rec(b,g-1,r);
		if (r > 1) ret |= rec(b,g,r-1);

		if (b && r) ret |= rec(b-1,g+1,r-1);
		if (g && r) ret |= rec(b+1,g-1,r-1);
		if (b && g) ret |= rec(b-1,g-1,r+1); 
	}

	return ret;
}

int main() {
	memset(p,-1,sizeof(p));
	scanf("%d", &n);
	scanf("%s", s);

	REP(i,n) {
		if (s[i] == 'B') cnt[0]++;
		else if (s[i] == 'G') cnt[1]++;
		else if (s[i] == 'R') cnt[2]++;
	}

	int r = rec(cnt[0], cnt[1], cnt[2]);

	if (r & 1) printf("B");
	if (r & 2) printf("G");
	if (r & 4) printf("R");
	printf("\n");
}
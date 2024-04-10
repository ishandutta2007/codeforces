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

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int a[110000];

map< pair<int, int>, int> ptc;
map<int, int> xc;
map<int, int> yc;
int n;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		ptc[{u,v}]++;
		xc[u]++;
		yc[v]++;
	}

	long long ans = 0;
	for (auto it = ptc.begin(); it != ptc.end(); it++) {
		ans -= it->second*1ll*(it->second-1)/2;
	}
	for (auto it = xc.begin(); it != xc.end(); it++) {
		ans += it->second*1ll*(it->second-1)/2;
	}
	for (auto it = yc.begin(); it != yc.end(); it++) {
		ans += it->second*1ll*(it->second-1)/2;
	}

	printf("%lld\n", ans);
}
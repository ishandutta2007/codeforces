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

int main() {
	scanf("%d", &n);

	for (int i = 20; i>= 0; i--) {
		if ((1<<i) <= n) {
			printf("%d ", i+1);
			n -= 1<<i;
		}
	}
}
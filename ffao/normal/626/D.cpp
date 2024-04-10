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

int n;
int balls[5100];
const int mod = 1000000007;

double diff[4][5100];

int main() {
	scanf("%d", &n);

	REP(i,n) scanf("%d", &balls[i]);

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			diff[0][abs(balls[j] - balls[i])] += 2.0 / (n*(n-1));
		}
	}

	for (int od = 1; od <= 5000; od++) {
		for (int nd = 1; od+nd <= 5000; nd++) {
			diff[1][od+nd] += diff[0][od] * diff[0][nd];
		}
	}

	double ans = 0;
	for (int od = 1; od <= 5000; od++) {
		for (int nd = od+1; nd <= 5000; nd++) {
			ans += diff[1][od] * diff[0][nd];
		}
	}

	printf("%.15f\n", ans);
}
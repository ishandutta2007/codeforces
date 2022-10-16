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

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, m, T;
int h, mm, s;
int tttm[20001];
int id[20001];

int main() {
	scanf("%d %d %d", &n, &m, &T);
	int next_id = 1;
	bool ok = false;
	int la = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d:%d:%d", &h, &mm, &s);
		int t = h*60*60 + mm*60 + s;
		tttm[i] = t;

		while (tttm[la] + T - 1 < tttm[i]) {
			la++;
		}

		int coinc;
		if (la != i) coinc = next_id - id[la] + 1;
		else coinc = 1;

		if (coinc == m) ok = true;

		if (coinc <= m) id[i] = next_id++;
		else id[i] = next_id-1;
	}

	if (!ok) printf("No solution\n");
	else {
		printf("%d\n", next_id - 1);
		for (int i = 0; i < n; i++) {
			printf("%d\n", id[i]);
		}
	}
}
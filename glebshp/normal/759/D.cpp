#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 5010;
const int ssize = 26;
const int mdl = 1000 * 1000 * 1000 + 7;

int cnk[size][size];
char buf[size];
int last[ssize][size];
int total[size];
int help[size];

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;

    scanf("%d", &n);
    scanf("%s", buf);

	total[0] = 1;
	for (int i = 0; i < n; i++) {
		int cur = buf[i] - 'a';
		for (int j = 0; j <= n; j++) {
			help[j] = last[cur][j];
		}

		for (int j = n; j > 0; j--) {
			last[cur][j] = total[j - 1] + mdl - last[cur][j - 1];
			if (last[cur][j] >= mdl)
				last[cur][j] -= mdl;
		}

		for (int j = n; j > 0; j--) {
			total[j] += last[cur][j];
			if (total[j] >= mdl)
				total[j] -= mdl;
			total[j] += mdl - help[j];
			if (total[j] >= mdl)
				total[j] -= mdl;			
		}
	}

	for (int i = 0; i <= n; i++) {
		cnk[i][0] = 1;
		cnk[i][i] = 1;
		for (int j = 1; j < i; j++) {
			cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
			if (cnk[i][j] >= mdl)
				cnk[i][j] -= mdl;
		}
	}
		
	long long rans = 0ll;
	for (int i = 1; i <= n; i++) {
//		cerr << i << ' ' << cnk[n - 1][i - 1] << ' ' << total[i] << endl;
		rans = (rans + cnk[n - 1][i - 1] * 1ll * total[i]) % mdl;		
	}

	cout << rans << endl;

    return 0;
}
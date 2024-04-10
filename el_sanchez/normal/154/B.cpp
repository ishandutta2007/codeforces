#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 101000;

int n, m, k, d, cur, failid;
int id[MAXN];
bool state[MAXN], prim[MAXN], cpr[MAXN], fail;
char c;

int main() {

	scanf("%d%d\n", &n, &m);
	forn(i, m) {
		cin >> c;
		scanf("%d\n", &cur);
		if (c == '+') {
			if (state[cur])
				cout << "Already on" << endl;
			else {
				//factorize_1
				fail = 0;
				k = cur;
				d = 2;
				while (d * d <= cur) {
					cpr[d] = 0;
					while (k % d == 0) {
						cpr[d] = 1;
						k /= d;
					}
					if (cpr[d] && prim[d]) {
						fail = 1;
						failid = d;
					}
					d++;
				}
				if (!fail && k > 1 && prim[k]) {
					fail = 1;
					failid = k;
				}
				if (fail) 
					cout << "Conflict with " << id[failid] << endl;
				else {
					state[cur] = 1;
					d = 2;
					while (d * d <= cur) {
						if (cpr[d]) {
							prim[d] = 1;
							id[d] = cur;
						}
						d++;
					}
					if (k > 1) {
						prim[k] = 1;
						id[k] = cur;
					}
					cout << "Success" << endl;
				}
			}
		} else {
			if (!state[cur])
				cout << "Already off" << endl;
			else {
				state[cur] = 0;
				k = cur;
				d = 2;
				while (d * d <= cur) {
					if (k % d == 0) {
						prim[d] = 0;
						id[d] = 0;
						while (k % d == 0) 
							k /= d;
					}
					d++;
				}
				if (k > 1 && prim[k]) {
					prim[k] = 0;
					id[k] = 0;
				}
				cout << "Success" << endl;
			}
		}
	}

    return 0;
}
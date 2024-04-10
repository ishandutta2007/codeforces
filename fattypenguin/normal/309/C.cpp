#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

ll cont[35];
int num[35];
int arr[2000007];

int main() {
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		int a;
		scanf("%d", &a);
		for (int i = 30; i >= 0; --i) {
			if (a & (1 << i)) {
				++cont[i];
			}
		}
	}

	int ans = 0;
	REP(i, m) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + m);
	for (int i = m - 1; i >= 0; --i) {
		int a = arr[i];
		bool found = false;
		for (int j = a; j <= 30; ++j) {
			if (cont[j] > 0) {
				for (int k = j; k > a; --k) {
					--cont[k];
					cont[k - 1] += 2;
				}
				found = true;
				break;
			}
		}

		if (!found) {
			for (int j = 30; j > a; --j) {
				if (num[j]) {
					--num[j];
					++cont[j];
					--ans;
					break;
				}
			}

			for (int j = a; j <= 30; ++j) {
				if (cont[j] > 0) {
					for (int k = j; k > a; --k) {
						--cont[k];
						cont[k - 1] += 2;
					}
					found = true;
					break;
				}
			}
		}

		if (found) {
			--cont[a];
			++num[a];
			++ans;
		}
	}

	cout << ans << endl;
	return 0;
}
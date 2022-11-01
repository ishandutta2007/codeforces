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

int w, h, k;
char m1[2222][2222];
char m2[2222][2222];

int mat[2222][2222];

int main() {
	cin >> h >> w >> k;
	int t1 = 0, t2 = 0;
	int total = 0;
	int all = 0;
	REP(i, 2 * h - 1) {
		if (i % 2 == 0) {
			scanf("%s", m1[t1++]);
			int length = strlen(m1[t1 - 1]);
			total += count(m1[t1 - 1], m1[t1 - 1] + length, 'E');
			all += length;
		}
		else {
			scanf("%s", m2[t2++]);
			int length = strlen(m2[t2 - 1]);
			total += count(m2[t2 - 1], m2[t2 - 1] + length, 'E');
			all += length;
		}
	}

	if (h > w) {
		for (int i = 0; i < w; ++i) {
			mat[0][i] = 0;
			for (int j = 0; j < h - 1; ++j) {
				if (m2[j][i] == 'E') {
					mat[j + 1][i] = mat[j][i];
				} else {
					mat[j + 1][i] = mat[j][i] ^ 1;
				}
			}

			if (i == 0) continue;

			int cost = 0;
			for (int j = 0; j < h; ++j) {
				if (mat[j][i] != mat[j][i - 1]) {
					if (m1[j][i - 1] == 'E') ++cost;
				} else {
					if (m1[j][i - 1] == 'N') ++cost;
				}
			}

			if (cost > h - cost) {
				REP(j, h) mat[j][i] ^= 1;
			}
		}
	} else {
		for (int i = 0; i < h; ++i) {
			mat[i][0] = 0;
			for (int j = 0; j < w - 1; ++j) {
				if (m1[i][j] == 'E') {
					mat[i][j + 1] = mat[i][j];
				} else {
					mat[i][j + 1] = mat[i][j] ^ 1;
				}
			}

			// cout << "i = " << i << m1[i][0] << mat[i][0] << " " << mat[i][1] <<  endl;

			if (i == 0) continue;

			int cost = 0;
			for (int j = 0; j < w; ++j) {
				if (mat[i - 1][j] != mat[i][j]) {
					if (m2[i - 1][j] == 'E') ++cost;
				} else {
					if (m2[i - 1][j] == 'N') ++cost;
				}
			}

			if (cost > w - cost) {
				REP(j, w) mat[i][j] ^= 1;
			}
		}
	}

	if (k == 1) {
		if (total * 4 >= 3 * all) {
			cout << "YES\n";
			REP(i, h) { REP(j, w) cout << "1 "; cout << endl;}
			return 0; 
		}
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	REP(i, h) { REP(j, w) cout << mat[i][j]+1 << " "; cout << endl;}
	return 0;
}
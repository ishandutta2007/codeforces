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

int img[2][77][77];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
	int n, t;
	cin >> n >> t;
	img[0][0][0] = n;
	int all = 0;
	int steps = 0;
	while (1) {
		int now = all++&1, next = now ^ 1;
		REP(i, 70) REP(j, 70) img[next][i][j] = 0;
		bool change = false;
		REP(i, 70) REP(j, 70) {
			if (img[now][i][j] >= 4) {
				REP(k, 4) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < 70) {
						img[next][nx][ny]++;
						if (i == 0 && j == 1 || i == 1 && j == 0) {
							if (nx == 0 && ny == 0) {
								img[next][nx][ny]++;
							}
						}
						if (i > 0 && j == 1 || j > 0 && i == 1) {
							if (nx == 0 || ny == 0) {
								img[next][nx][ny]++;
							}
						}
					}
				}
				img[next][i][j] += img[now][i][j] - 4;
				change = true;
			} else {
				img[next][i][j] += img[now][i][j];
			}
		}
		if (!change) break;
		++steps;
	}
	REP(i, t) {
		int x, y;
		cin >> x >> y;
		if (x < 0) x = -x;
		if (y < 0) y = -y;
		int ans = 0;
		if (x < 70 && y < 70) ans = img[all&1][x][y];
		cout << ans << endl;
	}
	return 0;
}
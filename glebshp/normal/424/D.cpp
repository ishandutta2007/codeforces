#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define right sdlkfj
#define left sdlkfjsdf

const double pi = acos(-1.0);
const int size = 350;
const int inf = 1000 * 1000 * 1000;

int n, m, t;
int tp, tu, td;
int field[size][size];
int right[size][size], left[size][size], up[size][size], down[size][size];

inline int getvalue(int x1, int y1, int x2, int y2) {
	return (right[x1][y2] - right[x1][y1]) + (down[x2][y2] - down[x1][y2]) + (left[x2][y1] - left[x2][y2]) + (up[x1][y1] - up[x2][y1]);
}

inline int way(int x1, int y1, int x2, int y2) {
	if (field[x1][y1] == field[x2][y2])
		return tp;
	else {
		if (field[x1][y1] < field[x2][y2])
			return tu;
		else
			return td;
	}
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d", &tp, &tu, &td);
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
    		scanf("%d", &field[i][j]);

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++) {
    		if (i == 0) {
    			down[i][j] = 0;
    		} else {
    			down[i][j] = down[i - 1][j] + way(i - 1, j, i, j);
    		}
    		if (j == 0) {
    			right[i][j] = 0;
    		} else {
    			right[i][j] = right[i][j - 1] + way(i, j - 1, i, j);
    		}
    	}

   	for (int i = n - 1; i >= 0; i--)
   		for (int j = m - 1; j >= 0; j--) {
   			if (i == n - 1) {
   				up[i][j] = 0;
   			} else {
   				up[i][j] = up[i + 1][j] + way(i + 1, j, i, j);
   			}
   			if (j == m - 1) {
   				left[i][j] = 0;
   			} else {
   				left[i][j] = left[i][j + 1] + way(i, j + 1, i, j);
   			}
   		}
//   	cerr << getvalue(3, 2, 5, 6) << endl;

   	int best = inf + 1;
   	int bx1 = -1, by1 = -1, bx2 = -1, by2 = -1;
		
   	for (int i = 0; i < n - 2; i++)
   		for (int j = i + 2; j < n; j++) {
   			set <pair <int, int> > vars;
   			for (int k = 2; k < m; k++) {
   				int val = left[j][k - 2] - right[i][k - 2] + up[i][k - 2] - up[j][k - 2];
   				vars.insert(mp(val, k - 2));
   				
   				val = down[j][k] - down[i][k] + right[i][k] - left[j][k];
   				set <pair <int, int> >::iterator it = vars.lower_bound(mp(t - val, 0));
   				if (abs(it->fs + val - t) < best) {
   					best = abs(it->fs + val - t);
   					bx1 = i;
   					by1 = it->sc;
   					bx2 = j;
   					by2 = k;
   				}
   				if (it != vars.begin()) {
   					--it;
   					if (abs(it->fs + val - t) < best) {
   					best = abs(it->fs + val - t);
   					bx1 = i;
   					by1 = it->sc;
   					bx2 = j;
   					by2 = k;
   				}
   				}
   			}
   		}

// 	cout << best << endl;
   	cout << bx1 + 1 << ' ' << by1 + 1 << ' ' << bx2 + 1 << ' ' << by2 + 1 << endl;

    return 0;
}
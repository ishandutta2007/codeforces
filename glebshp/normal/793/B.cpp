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

const int size = 1010;
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};

char field[size][size];
int ans[6][size][size];
int n, m;

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    	scanf("%s", field[i]);

    int xs = 0, ys = 0;
    int xt = 0, yt = 0;
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++) {
    		if (field[i][j] == 'S') {
    			xs = i;
    			ys = j;
    		}
    		if (field[i][j] == 'T') {
    			xt = i;
    			yt = j;
    		}
    	}

    for (int a = 0; a < 5; a++) 
	    for (int i = 0; i < n; i++)
	    	for (int j = 0; j < m; j++)
	    		ans[a][i][j] = false;

	ans[0][xs][ys] = true;
	for (int a = 0; a < 5; a++) {
		for (int i = 0; i < n; i++) {
			bool flag = false;
			for (int j = 0; j < m; j++) {
				flag = flag || ans[a][i][j];
				if (field[i][j] == '*')
					flag = false;
				ans[a + 1][i][j] |= flag;
			}
			flag = false;
			for (int j = m - 1; j >= 0; j--) {
				flag = flag || ans[a][i][j];
				if (field[i][j] == '*')
					flag = false;
				ans[a + 1][i][j] |= flag;			
			}
		}
		for (int j = 0; j < m; j++) {
			bool flag = false;
			for (int i = 0; i < n; i++) {
				flag = flag || ans[a][i][j];
				if (field[i][j] == '*')
					flag = false;
				ans[a + 1][i][j] |= flag;
			}
			flag = false;
			for (int i = n - 1; i >= 0; i--) {
				flag = flag || ans[a][i][j];
				if (field[i][j] == '*')
					flag = false;
				ans[a + 1][i][j] |= flag;
			}
		}
	}

	bool rans = ans[0][xt][yt] || ans[1][xt][yt] || ans[2][xt][yt] || ans[3][xt][yt];

	if (rans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

    return 0;
}
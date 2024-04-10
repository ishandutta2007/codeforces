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

const double pi = acos(-1.0);

const int size = 300;
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};

char field[size][size];

long long game[size][size];

int ans = 0;
int n, m;

bool onfield(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    	cin >> field[i];

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++) {
    		if (field[i][j] == 'B')
    			game[i][j] = 1;
    		else
    			game[i][j] = -1;
    	}

    int ans = 0;
    while (true) {
    	int tx = -1;
    	int ty = -1;
    	for (int i = n - 1; i >= 0; i--) {
    		if (tx != -1)
    			break;
    		for (int j = m - 1; j >= 0; j--) {
    			if (game[i][j] != 0) {
    				tx = i;
    				ty = j;
    				break;
    			}
    		}
    	}

    	if (tx == -1)
    		break;
    	for (int i = 0; i <= tx; i++)
    		for (int j = 0; j <= ty; j++) {
    			game[i][j] -= game[tx][ty];
    		}

    	ans++;
    }

    cout << ans << endl;

    return 0;
}
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
const int size = 210;
const int middle = 105;

int n;
char field[size][size];
bool valid[size][size];
int cnt[size][size];

bool onfield(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    	scanf("%s", field[i]);

	for (int i = -n + 1; i < n; i++)
		for (int j = -n + 1; j < n; j++)
			valid[i + middle][j + middle] = true;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			for (int i = -n + 1; i < n; i++)
				for (int j = -n + 1; j < n; j++) {
					if (onfield(x + i, y + j) && field[x][y] == 'o' && field[x + i][y + j] == '.') {
						valid[i + middle][j + middle] = false;
					}
				}

	bool flag = true;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++) {
			for (int i = -n + 1; i < n; i++)
				for (int j = -n + 1; j < n; j++)
					if (onfield(x + i, y + j) && field[x][y] == 'o' && valid[i + middle][j + middle]) {
						cnt[x + i][y + j]++;
					} 
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (field[i][j] == 'x' && cnt[i][j] == 0)
				flag = false;

	if (!flag)
		printf("NO\n");
	else {
		printf("YES\n");
		for (int i = -n + 1; i < n; i++) {
			for (int j = -n + 1; j < n; j++) {
			    if (i == 0 && j == 0)
			    	printf("o");
			  	else {	
					if (valid[i + middle][j + middle])
						printf("x");
					else
						printf("."); 
				}
			}
			printf("\n");
		}	
	}


    return 0;
}
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
const int size = 1000 * 1000 + 100;
const int linf = 1000 * 1000 - 1;
const int bsize = 1100;

vector <int> basket[bsize][bsize];
int x[size], y[size];
int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d%d", &x[i], &y[i]);
    	basket[x[i] / bsize][y[i] / bsize].pb(i);
    }

    for (int i = 0; i < bsize; i++) {
    	if (i % 2 == 0) {
    		for (int j = 0; j < bsize; j++) {
    			for (int k = 0; k < (int) basket[i][j].size(); k++)
    				printf("%d ", basket[i][j][k] + 1);
    		}
    	} else {
    		for (int j = bsize - 1; j >= 0; j--) {
    			for (int k = 0; k < (int) basket[i][j].size(); k++)
    				printf("%d ", basket[i][j][k] + 1);
    		}
    	}
    }
    	

    return 0;
}
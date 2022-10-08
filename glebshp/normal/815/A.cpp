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

const int size = 1000;

vector <int> horans;
vector <int> verans;

int n, m;
int a[size][size];
bool used[size][size];

void no_ans() {
	printf("-1\n");

	exit(0);
}

void apply_hor(int x) {
	for (int i = 0; i < m; i++) {
		a[x][i] -= 1;
		if (a[x][i] < 0)
			no_ans();
	}

	horans.pb(x);
}

void apply_ver(int x) {
	for (int i = 0; i < n; i++) {
		a[i][x] -= 1;
		if (a[i][x] < 0)
			no_ans();
	}

	verans.pb(x);
}

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++) {
    		scanf("%d", &a[i][j]);
    	}

    int mn = a[0][0];
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++)
    		mn = min(mn, a[i][j]); 
    }

    for (int i = 0; i < mn; i++) {
    	if (n < m) {
	    	for (int j = 0; j < n; j++)
    			apply_hor(j);
    	} else {
    		for (int j = 0; j < m; j++)
    			apply_ver(j);
    	}
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++)
    		if (a[i][j] == 0) {
    			for (int k = 0; k < n; k++) {
    				while (a[k][j] > 0)
    					apply_hor(k);
    			}
    			for (int k = 0; k < m; k++)
    				while (a[i][k] > 0)
    					apply_ver(k);

    			
    			for (int p = 0; p < n; p++)
    				for (int q = 0; q < m; q++)
    					if (a[p][q] != 0)
    						no_ans();

    			printf("%d\n", (int) horans.size() + (int) verans.size());
    			for (auto& e : horans)
    				printf("row %d\n", e + 1);
    			for (auto& e : verans)
    				printf("col %d\n", e + 1);

    			return 0;
    		}
    }
    assert(false);


    return 0;
}
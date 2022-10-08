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

const int size = 1000 * 1000 + 100;
//const int size = 100;
const int ssize = 21;
const long long mdl = 1000 * 1000 * 1000 + 7;

//int ans[size][size];
int q;
long long help[ssize][size];
int mindiv[size];

int nod(int a, int b) {
	if (b == 0) {
		return a;
	}

	return nod(b, a % b);
}

int main () {
	for (int i = 0; i < size; i++)
		mindiv[i] = i;
	for (int i = 2; i * i < size; i++) 
		if (mindiv[i] == i) {
			for (int j = i; i * j < size; j++) {
				mindiv[i * j] = min(mindiv[i * j], i);
			}
		}

	for (int i = 0; i < size; i++)
		help[0][i] = 1;
	for (int i = 1; i < ssize; i++) {
		help[i][0] = 2;
		for (int j = 1; j < size; j++) {
			help[i][j] = help[i - 1][j] + help[i][j - 1];
			if (help[i][j] >= mdl) {
				help[i][j] -= mdl;
			}
		}
	}

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
    	int r, n;
    	scanf("%d%d", &r, &n);
    	int lst = -1;
    	int cnt = 0;
    	long long ans = 1;
    	while (n > 1) {
    		if (mindiv[n] != lst) {
    			ans = (ans * help[cnt][r]) % mdl;
    			lst = mindiv[n];
    			cnt = 1;
    		} else {
    			cnt++;
    		}
    		n /= mindiv[n];
    	}
    	ans = (ans * help[cnt][r]) % mdl;

    	printf("%lld\n", ans);
    }
    

    /*
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= i; j++) {
    		if (i % j == 0 && nod(j, i / j) == 1) {
    			ans[0][i]++;
    		}
    	}	
    }


    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		for (int k = 1; k <= n; k++) {
    			if (j % k == 0) {
    				ans[i][j] += (ans[i - 1][k] + ans[i - 1][j / k]);
    			}
    		}
    	}
    	for (int j = 1; j <= n; j++)
    		ans[i][j] /= 2;
    }

    for (int i = 0; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    //	    if (j == 4 || j == 9 || j == 36)
	    		printf("%6d", ans[i][j]);
    	}
    	printf("\n");	
    }
    */

    return 0;
}